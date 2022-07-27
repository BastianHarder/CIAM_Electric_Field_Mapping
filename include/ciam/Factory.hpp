#ifndef CIAM_ELECTRICALFIELDMAPPING_FACTORY_HPP
#define CIAM_ELECTRICALFIELDMAPPING_FACTORY_HPP

#include "ciam/iDataLogger.hpp"
#include <memory>
namespace CIAM {
class Factory {
public:
  Factory() = default;
  ~Factory() = default;

  std::shared_ptr<iDataLogger> getDataLogger();
private:
  std::shared_ptr<iDataLogger> dataLogger;
};
}
#endif  // CIAM_ELECTRICALFIELDMAPPING_FACTORY_HPP
