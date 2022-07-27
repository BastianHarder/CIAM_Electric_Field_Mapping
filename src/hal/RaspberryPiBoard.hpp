//----------------------------------------------------------------------------------
// Copyright 2022 UniversitĂ¤tsklinikum Freiburg
// Section of Neuroelectronic Systems
// Authors: Bastian Harder
// Project: CIAM
// File Description: This class provides several board functions e.g. SPI,
// using the C library for bcm2835 from https://www.airspayce.com/mikem/bcm2835/
//----------------------------------------------------------------------------------

#ifndef RASPBERRY_PI_BOARD_HPP
#define RASPBERRY_PI_BOARD_HPP

#include <cstdint>
#include <vector>

#include "iSPI.hpp"
namespace CIAM {
class RaspberryPiBoard : public iSPI {
public:
  RaspberryPiBoard();
  ~RaspberryPiBoard() override;

  void initSpi(uint32_t spiSpeedHz) override;
  uint32_t getSpiClockFreq() override;
  uint8_t spi_transfer8(uint8_t value) override;
  void spi_transfer16(char* tbuf, char* rbuf) override;
  void spi_transfer(std::vector<uint16_t>& commandList, std::vector<uint16_t>& receivedList) override;

private:
  uint32_t spiClockFreqHz;

  static constexpr uint8_t SUCCESS = 1;
  static constexpr uint8_t FAIL = 0;
};
}
#endif // RASPBERRY_PI_BOARD_HPP

