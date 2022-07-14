# CIAM Electric Field Mapping
Mapping of underwater cathodic protection currents. 
Code here entails the various programs needed for the initialization and running of 
various data acquisition hardware controllers.

## Minimum requirements
* CMake >= 3.14

## How to build
To build the software one needs to perform the following steps:
1. Checkout the code
   `git clone https://github.com/BastianHarder/CIAM_Electric_Field_Mapping.git`
2. Generate build files and compile
   ```
    cd CIAM_Electric_Field_Mapping
    mkdir build
    cd build
    cmake ..
    make
   ```

## Cross-compile
To cross compile, it is the same as to build, but now one must only pass a toolchain file,
where the directories are set. To compile for raspberry pi, the toolchain file is already given
in the `cmake` directory.
Also, one must have the cross-compiler installed in the machine.

### Cross compiling in Unix machine (Linux MacOS)
A recommended cross-compiler is [Raspi-toolchain](https://github.com/Pro/raspi-toolchain). 
The releases can be found [here](https://github.com/Pro/raspi-toolchain/releases)
To be able to cross compile, you must just extract the contents of the release into `/opt`.

   ```
    cd CIAM_Electric_Field_Mapping
    mkdir build
    cd build
    cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-gcc-rasp.cmake ..
    make
   ```
### Cross compiling in Windows machine
One needs to find a cross-compiler. There are some options available, but must be
explored.

