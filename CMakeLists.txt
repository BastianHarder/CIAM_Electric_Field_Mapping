cmake_minimum_required(VERSION 3.14)

project(CIAM_ElectricalFieldMapping CXX)


# Used to include Google Test. We could do it different as well, but I think this is the easiest...
include(FetchContent)

# --------- Global compiler options -------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# THIS IS IN CASE YOU WANT TO SET THE BUILD TO HAVE THE DEBUG SYMBOLS AND SO ON.
# The best way is to enable this when generating the CMake files by running
# cmake -DCMAKE_BUILD_TYPE=Debug <PATH-TO-THE-CMakeLists.txt>
option(CMAKE_BUILD_TYPE "Type of build, by default is Debug" Debug)

# --------- specific toolchain options / file --------
# You can set a CMAKE_TOOLCHAIN_FILE option in case you want to cross compile, for example.
# You can do that by running:
# cmake -DCMAKE_TOOLCHAIN_FILE=<CMAKE-TOOLCHAIN-FILE-PATH> <PATH-TO-THE-CMakeLists.txt>

# -------------- CMake options -----------------
option(BUILD_TESTS "Download test frameworks and compile tests." ON)

# Threads ------------------
FIND_PACKAGE(Threads REQUIRED)


# ----------------- Sources -----------------------
# This adds the subdirectories to "load" the other CMakeLists.txt.
add_subdirectory(thirdparty)
add_subdirectory(src)
add_subdirectory(example)
#if(BUILD_TESTS)
#	add_subdirectory(tests)
#endif()

# This is just something that I like to put to have an overview of the options, even though some of these
# are already displayed by default, like compiler VERSION and so on...
message(STATUS "------------------------------------------ CIAM Electric Field Mapping Settings -----------------------------------------------")
message(STATUS "CMAKE_VERSION is set to ${CMAKE_VERSION}")
message(STATUS "BUILD_TESTS is set to ${BUILD_TESTS}")
message(STATUS "------------------------------------------ CIAM Electric Field Mapping Settings -----------------------------------------------")
