file(GLOB_RECURSE SOURCES
        ./*.hpp
        ./*.cpp
        )

# this creates a library
add_library(CIAMElectricFieldMapping ${SOURCES})

# In case there are some dependencies on other libraries, you can add also the command below:
add_dependencies(CIAMElectricFieldMapping bcm2835)
# Usually when adding the target_link_libraries, it will create a dependency automatically
# We make it private, because only our library needs to know about the bcm2835 library
target_link_libraries(CIAMElectricFieldMapping PRIVATE bcm2835
        PRIVATE intanRhd2000
        PUBLIC spdlog::spdlog
        PUBLIC ${CMAKE_THREAD_LIBS_INIT} )
target_compile_definitions(CIAMElectricFieldMapping PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)
# This set the include paths of the library
# We use the private for the "src", because its headers should not be public
# on the other hand, the "include" is public to whoever wants to include the library,
# meaning that the headers are public, so those include paths will be also included in whoever links this library.
target_include_directories(CIAMElectricFieldMapping PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
            PUBLIC ${PROJECT_SOURCE_DIR}/include)

