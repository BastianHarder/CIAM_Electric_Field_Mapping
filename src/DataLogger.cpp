//----------------------------------------------------------------------------------
// Copyright 2022 Universitaetsklinikum Freiburg
// Section of Neuroelectronic Systems
// Authors: Bastian Harder
// Project: CIAM
// File Description: This class provides functions to read data from INTAN RHD2000
// over spi and save this data in a file.
// This class makes use of  bcm2835_chip class and rhd2000registers class.
//----------------------------------------------------------------------------------

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "DataLogger.hpp"
#include "hal/RaspberryPiBoard.hpp"

#include "hal/SimulationBoard.hpp"

#include "rhd2000registers.hpp"

#include "datasource/externaladc/ExternalRHD2000.hpp"

#include "hal/RaspberryPiBoard.hpp"
#include "spdlog/spdlog.h"

namespace CIAM {
// Constructor: initialise the class
DataLogger::DataLogger() {}

// Destructor: close the class and deallocate any memory
DataLogger::~DataLogger() {}

void DataLogger::configure(const DataLoggerConfig& dataLoggerConfig) noexcept {
  switch (dataLoggerConfig.datasourceConfig->getDataSourceType()) {
  case DataSourceConfig::DataSourceType::EXTERNAL_RHD2000: {
    std::shared_ptr<ExternalRHD2000> externalRhd2000 = std::make_shared<ExternalRHD2000>();
    //std::shared_ptr<iSPI> spi = std::make_shared<SimulationBoard>();
    std::shared_ptr<iSPI> spi = std::make_shared<RaspberryPiBoard>();
    externalRhd2000->setSpi(spi);
    dataSource = externalRhd2000;
    dataSource->configure(*dataLoggerConfig.datasourceConfig);
    break;
  }
  case DataSourceConfig::DataSourceType::FILE_DATA:
    break;
  };

  dataSource->init();
}

// Function: Save Vector content in a file (append vector content to existing file)
void DataLogger::saveResultsToFile(const std::vector<uint16_t>& u16_vector) noexcept {
  int VectorLength = static_cast<int>(u16_vector.size());
  FILE* pFile;

  pFile = fopen("rhd2000_results.txt", "a");
  if (pFile != NULL) {
    fprintf(pFile, "Result Vector content: \n");
    for (int i = 2; i < VectorLength; i++) {
      fprintf(pFile, "Result of ADC Channel %d: \t %x \n", (i - 2), u16_vector[i]);
    }
    fclose(pFile);
  } else {
    printf("Error while opening the file! \n");
  }
}

void DataLogger::setDataSource(const std::shared_ptr<iDataSource>& newDataSource) noexcept {}
// Function:
void DataLogger::startDataLogging(const std::chrono::milliseconds& samplingPeriod) noexcept {
  if(!dataSource) {
    SPDLOG_ERROR("Trying to sample without data source");
    return;
  }
  dataSource->startSamplingData(samplingPeriod);
}
void DataLogger::stopDataLogger() noexcept {
  if(!dataSource) {
    SPDLOG_ERROR("Trying to stop sample without data source");
    return;
  }
  dataSource->stopSamplingData();
}
}
