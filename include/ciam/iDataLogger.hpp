#ifndef CIAM_ELECTRICALFIELDMAPPING_IDATALOGGER_HPP
#define CIAM_ELECTRICALFIELDMAPPING_IDATALOGGER_HPP

#include "ciam/config/DataLoggerConfig.hpp"
#include <memory>
#include <chrono>

namespace CIAM {
class iDataSource;

class iDataLogger {
public:
  iDataLogger() = default;
  virtual ~iDataLogger() = default;

  virtual void configure(const DataLoggerConfig& dataLoggerConfig) noexcept = 0;
  virtual void setDataSource(const std::shared_ptr<iDataSource>& newDataSource) noexcept = 0;
  virtual void startDataLogging(const std::chrono::milliseconds& samplingPeriod) noexcept = 0;
  virtual void stopDataLogger() noexcept = 0;
};

}  // namespace CIAM

#endif  // CIAM_ELECTRICALFIELDMAPPING_IDATALOGGER_HPP
