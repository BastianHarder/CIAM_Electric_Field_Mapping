#ifndef CIAM_ELECTRICALFIELDMAPPING_EXTERNALRHD2000_HPP
#define CIAM_ELECTRICALFIELDMAPPING_EXTERNALRHD2000_HPP

#include "datasource/iDataSource.hpp"
#include "hal/iSPI.hpp"
#include "rhd2000registers.hpp"

#include <memory>
#include <atomic>
#include <thread>

namespace CIAM {

class ExternalRHD2000 : public iDataSource{
public:
  ExternalRHD2000();
  ~ExternalRHD2000() override = default;

  bool setSpi(const std::shared_ptr<iSPI>& newSpi);
  bool configure(const DataSourceConfig& config) override;
  bool init() override;
  bool startSamplingData(const std::chrono::milliseconds& samplingPeriod) override;
  bool stopSamplingData() override;

private:
  std::unique_ptr<Rhd2000Registers> rhd2000registers;
  std::shared_ptr<iSPI> spi;
  std::atomic<bool> isRunning{false};
  std::thread *samplingThread;
};

}  // namespace CIAM

#endif  // CIAM_ELECTRICALFIELDMAPPING_EXTERNALRHD2000_HPP
