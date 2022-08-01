#ifndef CIAM_ELECTRICALFIELDMAPPING_ISPI_HPP
#define CIAM_ELECTRICALFIELDMAPPING_ISPI_HPP

#include <cstdint>
#include <vector>

namespace CIAM {
class iSPI {
public:
  iSPI() = default;
  virtual ~iSPI() = default;

  virtual void initSpi(uint32_t spiSpeedHz) = 0;
  virtual uint32_t getSpiClockFreq()  = 0;
  virtual uint8_t spi_transfer8(uint8_t value) = 0;
  virtual void spi_transfer16(char* tbuf, char* rbuf) = 0;
  virtual void spi_transfer(std::vector<uint16_t>& commandList, std::vector<uint16_t>& receivedList) = 0;
};
}
#endif  // CIAM_ELECTRICALFIELDMAPPING_ISPI_HPP
