cmake_minimum_required(VERSION 3.14)

project(IntanRHD2000Project LANGUAGES CXX VERSION 1.0)

set(INTAN_RHD_2000_SOURCES
        ./rhd2000registers.cpp)

add_library(intanRhd2000 ${INTAN_RHD_2000_SOURCES})
target_include_directories(intanRhd2000 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
