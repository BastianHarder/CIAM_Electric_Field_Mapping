file(GLOB_RECURSE SOURCES
        ./*.hpp
        ./*.cpp
        )

# this creates an executable
add_executable(CIAMElectricFieldMappingExample ${SOURCES})

target_link_libraries(CIAMElectricFieldMappingExample PRIVATE CIAMElectricFieldMapping)

# This set the include paths of the library
# We use the public here, because this include path is public to whoever wants to include the library, meaning that
# those include paths will be also included in whoever links this library.
# If the headers were not public, we could set as PRIVATE. We can also do an example on that, if you want.
target_include_directories(CIAMElectricFieldMappingExample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


