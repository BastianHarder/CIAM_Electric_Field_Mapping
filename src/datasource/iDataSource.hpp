#ifndef CIAM_ELECTRICALFIELDMAPPING_IDATASOURCE_HPP
#define CIAM_ELECTRICALFIELDMAPPING_IDATASOURCE_HPP

#include "ciam/config/datasource/DataSourceConfig.hpp"

#include <chrono>
namespace CIAM {
class iDataSource {
public:
  iDataSource() = default;
  virtual ~iDataSource() = default;

  virtual bool configure(const DataSourceConfig& config) = 0;
  virtual bool init() = 0;
  virtual bool startSamplingData(const std::chrono::milliseconds& samplingPeriod) = 0;
  virtual bool stopSamplingData() = 0;
};
}

#endif //CIAM_ELECTRICALFIELDMAPPING_IDATASOURCE_HPP
