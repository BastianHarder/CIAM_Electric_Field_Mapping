add_subdirectory(bcm2835-1.71)
add_subdirectory(intanrhd2000)

set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "Force STATIC library build in spdlog add_subdirectory")
set(SPDLOG_NO_EXCEPTIONS ON CACHE BOOL "Force SPDLOG_NO_EXCEPTIONS in spdlog library in spdlog add_subdirectory")
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.10.0
)
FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()
