//----------------------------------------------------------------------------------
// Copyright 2022 Universitaetsklinikum Freiburg
// Section of Neuroelectronic Systems
// Authors: Bastian Harder
// Project: CIAM
// File Description: main function
//----------------------------------------------------------------------------------

#include <cstdio>
#include "ciam/Factory.hpp"
#include <cstdint>
#include <thread>

#include "spdlog/spdlog.h"
#include "ciam/config/DataLoggerConfig.hpp"
#include "ciam/config/datasource/ExternalRHD2000Config.hpp"

CIAM::DataLoggerConfig generateConfig() {
  CIAM::DataLoggerConfig dataLoggerConfig;
  dataLoggerConfig.datasourceConfig = std::make_shared<CIAM::ExternalRHD2000Config>();
  return dataLoggerConfig;
}

int main(int argc, char **argv) {
  spdlog::default_logger()->set_level(spdlog::level::level_enum::warn);
  CIAM::Factory ciamFactory;


  std::shared_ptr<CIAM::iDataLogger> dataLogger = ciamFactory.getDataLogger();

  CIAM::DataLoggerConfig dataLoggerConfig = generateConfig();
  dataLogger->configure(dataLoggerConfig);
  dataLogger->startDataLogging(std::chrono::milliseconds(20));

  std::this_thread::sleep_for(std::chrono::seconds(2));
  dataLogger->stopDataLogger();
  return 0;
}
