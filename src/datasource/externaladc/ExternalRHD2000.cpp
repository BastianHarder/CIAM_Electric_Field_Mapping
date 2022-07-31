#include "ExternalRHD2000.hpp"
#include "ciam/config/datasource/ExternalRHD2000Config.hpp"

#include "spdlog/spdlog.h"

#include <iostream>

namespace CIAM {
ExternalRHD2000::ExternalRHD2000() {}

bool ExternalRHD2000::setSpi(const std::shared_ptr<iSPI>& newSpi) {
  spi = newSpi;
  return true;
}
bool ExternalRHD2000::configure(const DataSourceConfig& config) {
  const ExternalRHD2000Config *configPtr = dynamic_cast<const ExternalRHD2000Config*>(&config);
  if(configPtr == nullptr) {
    std::cout << "Configuration type for External RHD 2000 is not correct" << std::endl;
    return false;
  }
  const ExternalRHD2000Config& externalRhd2000Config = *configPtr;

  rhd2000registers = std::make_unique<Rhd2000Registers>(externalRhd2000Config.sampleRate);
  if(!spi) {
    std::cout << "SPI Not set! Configuration failed." << std::endl;
    return false;
  }

  spi->initSpi(externalRhd2000Config.spiClockSpeed);
  return false;
}

bool ExternalRHD2000::init() {
  // generate vector object to store commands for rhd2000
  std::vector<uint16_t> rhd2000commandVector;
  // generate vector object to store received results from rhd2000
  std::vector<uint16_t> rhd2000receivedResVector;
  // variable to store length of command vector

  // Initialize and calibrate RHD2000
  rhd2000registers->createCommandListRegisterConfig(rhd2000commandVector, true);
  // Print whole command vector for checking purpose
  SPDLOG_DEBUG("Config Command Vector Content: ");
  for (int i = 0; i < rhd2000commandVector.size(); i++) {
    SPDLOG_DEBUG("Vector Index {}: 0x{:x}", i, rhd2000commandVector[i]);
  }
  // Perform SPI Transfer, let received half words be stored in rhd2000receivedResVector
  spi->spi_transfer(rhd2000commandVector, rhd2000receivedResVector);
  // Print whole result vector for checking purpose
  SPDLOG_DEBUG("Config Result Vector Content:");
  SPDLOG_DEBUG("Result Vector Length: {}", rhd2000receivedResVector.size());
  for (int k = 0; k < rhd2000receivedResVector.size(); k++) {
    SPDLOG_DEBUG("Vector Index {} 0x{:x}", k, rhd2000receivedResVector[k]);
  }
  return true;
}

bool ExternalRHD2000::startSamplingData(const std::chrono::milliseconds& samplingPeriod) {
  if(this->isRunning) {
    SPDLOG_WARN("Sampling is already being performed");
    return false;
  }
  this->isRunning = true;
  samplingThread = new std::thread([this, samplingPeriod]() {
    std::vector<uint16_t> rhd2000commandVector;
    // generate vector object to store received results from rhd2000
    std::vector<uint16_t> rhd2000receivedResVector;
    while (this->isRunning) {
      rhd2000registers->createCommandListConvert(rhd2000commandVector);
      // Print whole command vector for checking purpose
      printf("Convert Command Vector Content: \n");
      for (int i = 0; i < rhd2000commandVector.size(); i++) {
        printf("Vector Index %d: \t %x \n", i, rhd2000commandVector[i]);
      }
      // Make sure result vector is empty and can store new results
      rhd2000receivedResVector.clear();
      // Perform SPI transfer, let received half words be stored in rhd2000receivedResVector
      spi->spi_transfer(rhd2000commandVector, rhd2000receivedResVector);
      rhd2000receivedResVector.size();
      // Print whole result vector for checking purpose
      printf("Convert Result Vector Content: \n");
      SPDLOG_DEBUG("Result Vector Length: {}", rhd2000receivedResVector.size());
      for (int k = 0; k < rhd2000receivedResVector.size(); k++) {
        printf("Vector Index %d: \t %x \n", k, rhd2000receivedResVector[k]);
      }
      std::this_thread::sleep_for(samplingPeriod);
    }
  });
  return true;
}

bool ExternalRHD2000::stopSamplingData() {
  if(samplingThread == nullptr || !isRunning) {
    return true;
  }
  isRunning = false;
  if (samplingThread->joinable()) {
    samplingThread->join();
  }
  return false;
}

}  // namespace CIAM
