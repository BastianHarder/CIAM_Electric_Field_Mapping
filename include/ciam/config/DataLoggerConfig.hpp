#ifndef CIAM_ELECTRICALFIELDMAPPING_DATALOGGERCONFIG_HPP
#define CIAM_ELECTRICALFIELDMAPPING_DATALOGGERCONFIG_HPP

#include "datasource/DataSourceConfig.hpp"
#include <memory>
#include <string>

namespace CIAM {
class DataLoggerConfig {
public:
  std::string writeToFile;
  std::shared_ptr<DataSourceConfig> datasourceConfig;
};
}
#endif  // CIAM_ELECTRICALFIELDMAPPING_DATALOGGERCONFIG_HPP
