#include "ciam/Factory.hpp"
#include "DataLogger.hpp"

namespace CIAM {
std::shared_ptr<iDataLogger> Factory::getDataLogger() {
  if(!dataLogger) {
    dataLogger = std::make_shared<DataLogger>();
  }
  return dataLogger;
}
}
