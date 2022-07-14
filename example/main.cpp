//----------------------------------------------------------------------------------
// Copyright 2022 Universitaetsklinikum Freiburg
// Section of Neuroelectronic Systems
// Authors: Bastian Harder
// Project: CIAM
// File Description: main function
//----------------------------------------------------------------------------------

#include <cstdio>
#include "ciam/data_logger.hpp"
#include <cstdint>

int main(int argc, char **argv) {
    // The constexpr is resolved on compile time, therefore, there is no memory allocation
	constexpr uint32_t spi_clock_speed = 500000;
	constexpr double rhd2000sampling_rate = 5000;
	Data_Logger data_logger;
	data_logger.data_logging(spi_clock_speed, rhd2000sampling_rate);
	return 0;
}

