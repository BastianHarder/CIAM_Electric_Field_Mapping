#ifndef CIAM_ELECTRICALFIELDMAPPING_SIMULATIONBOARD_HPP
#define CIAM_ELECTRICALFIELDMAPPING_SIMULATIONBOARD_HPP

#include "iSPI.hpp"
namespace CIAM {

class SimulationBoard : public iSPI {
public:
  void initSpi(uint32_t spiSpeedHz) override;
  uint32_t getSpiClockFreq() override;
  uint8_t spi_transfer8(uint8_t value) override;
  void spi_transfer16(char *tbuf, char *rbuf) override;
  void spi_transfer(std::vector<uint16_t> &commandList, std::vector<uint16_t> &receivedList) override;
};
}
#endif  // CIAM_ELECTRICALFIELDMAPPING_SIMULATIONBOARD_HPP
