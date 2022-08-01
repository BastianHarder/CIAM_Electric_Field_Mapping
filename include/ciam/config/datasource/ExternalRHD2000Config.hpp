#ifndef CIAM_ELECTRICALFIELDMAPPING_EXTERNALRHD2000CONFIG_HPP
#define CIAM_ELECTRICALFIELDMAPPING_EXTERNALRHD2000CONFIG_HPP

#include "DataSourceConfig.hpp"
#include <cstdint>
namespace CIAM {

class ExternalRHD2000Config : public DataSourceConfig {
public:
  ExternalRHD2000Config() : DataSourceConfig(DataSourceConfig::DataSourceType::EXTERNAL_RHD2000) {}
  double sampleRate = DEFAULT_SAMPLE_RATE;
  uint32_t spiClockSpeed = DEFAULT_SPI_CLOCK_SPEED;

private:
  static constexpr double DEFAULT_SAMPLE_RATE = 5000;
  static constexpr uint32_t DEFAULT_SPI_CLOCK_SPEED = 500000;
};

}  // namespace CIAM

#endif  // CIAM_ELECTRICALFIELDMAPPING_EXTERNALRHD2000CONFIG_HPP
