cmake_minimum_required(VERSION 3.10)

# Project definition
project(EasyStr
        VERSION 1.3.0
        DESCRIPTION "A simple and intuitive C string manipulation library"
        LANGUAGES C
)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Library target - Static library
add_library(easystr STATIC
        src/EasyStr.c
)

# Public include directory
target_include_directories(easystr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Set library properties
set_target_properties(easystr PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER include/EasyStr.h
)

# Example/Demo executable
add_executable(demo
        examples/demo.c
)

target_link_libraries(demo PRIVATE easystr)

# Installation rules
include(GNUInstallDirs)

install(TARGETS easystr
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Optional: Create pkg-config file (only if template exists)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/easystr.pc.in")
    configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/easystr.pc.in
            ${CMAKE_CURRENT_BINARY_DIR}/easystr.pc
            @ONLY
    )
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/easystr.pc
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
    )
endif()

# Print build configuration
message(STATUS "EasyStr Library Configuration:")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C Compiler: ${CMAKE_C_COMPILER_ID}")
message(STATUS "  Install prefix: ${CMAKE_INSTALL_PREFIX}")