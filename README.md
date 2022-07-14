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
    cmake ..
    make
   ```

## Cross-compile
To cross compile, it is the same as to build, but now one must only pass a toolchain file,
where the directories are set. To compile for raspberry pi, the toolchain file is already given
in the `cmake` directory.

   ```
    cd CIAM_Electric_Field_Mapping
    mkdir build
    cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-gcc-rasp.cmake ..
    make
   ```
