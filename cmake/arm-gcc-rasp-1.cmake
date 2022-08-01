message(STATUS "ARM GCC Raspberry Pi OS toolchain CMAKE_MAKE_PROGRAM: ${CMAKE_MAKE_PROGRAM}")

#SET(CMAKE_SYSTEM_NAME Linux)
#SET(CMAKE_SYSTEM_PROCESSOR arm)
#SET(CMAKE_SYSTEM_VERSION 1)
#SET(CMAKE_CROSSCOMPILING TRUE)
#
## here is the target environment located
#SET(CMAKE_FIND_ROOT_PATH /opt/cross-pi-gcc/arm-linux-gnueabihf)
#
## which compilers to use for C and C++
#SET(CMAKE_C_COMPILER /opt/cross-pi-gcc/bin/arm-linux-gnueabihf-gcc)
#SET(CMAKE_CXX_COMPILER /opt/cross-pi-gcc/bin/arm-linux-gnueabihf-g++)
#SET(CMAKE_LIBRARY_ARCHITECTURE /opt/cross-pi-gcc/bin/arm-linux-gnueabihf)
#
## adjust the default behaviour of the FIND_XXX() commands:
## search headers and libraries in the target environment, search
## programs in the host environment
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
SET(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --with-arch=armv6 --with-float=hard --with-fpu=vfp")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --with-arch=armv6 --with-float=hard --with-fpu=vfp")
