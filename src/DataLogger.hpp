//----------------------------------------------------------------------------------
// Copyright 2022 Universitaetsklinikum Freiburg
// Section of Neuroelectronic Systems
// Authors: Bastian Harder
// Project: CIAM
// File Description: This class provides functions to read data from INTAN RHD2000
// over spi and save this data in a file.
// This class makes use of  bcm2835_chip class and rhd2000registers class.
//----------------------------------------------------------------------------------

#ifndef DATA_LOGGER_HPP
#define DATA_LOGGER_HPP

#include "ciam/iDataLogger.hpp"
#include "datasource/iDataSource.hpp"
#include <cstdint>
#include <vector>

namespace CIAM {
class DataLogger : public iDataLogger {
public:
  DataLogger();
  ~DataLogger() override;

  void configure(const DataLoggerConfig& dataLoggerConfig) noexcept override;
  void setDataSource(const std::shared_ptr<iDataSource>& newDataSource) noexcept override;
  void startDataLogging(const std::chrono::milliseconds& samplingPeriod) noexcept override;
  void stopDataLogger() noexcept override;

private:
  void saveResultsToFile(const std::vector<uint16_t> &u16_vector) noexcept;
  std::shared_ptr<iDataSource> dataSource;
};
}  // namespace CIAM

#endif  // DATA_LOGGER_H
