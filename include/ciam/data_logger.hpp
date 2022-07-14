//----------------------------------------------------------------------------------
// Copyright 2022 Universitaetsklinikum Freiburg
// Section of Neuroelectronic Systems
// Authors: Bastian Harder
// Project: CIAM
// File Description: This class provides functions to read data from INTAN RHD2000
// over spi and save this data in a file.
// This class makes use of  bcm2835_chip class and rhd2000registers class.
//----------------------------------------------------------------------------------

#ifndef DATA_LOGGER_HPP
#define DATA_LOGGER_HPP

#include <cstdint>
#include <vector>

class Data_Logger
{
public:
    Data_Logger();
	~Data_Logger();
	void save_vector_to_file(std::vector<uint16_t>& u16_vector);
	void data_logging(uint32_t spi_clock_speed, double sampleRate);
};

#endif // DATA_LOGGER_H

