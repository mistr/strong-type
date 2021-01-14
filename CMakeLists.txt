cmake_minimum_required(VERSION 3.5)

set(PACKAGE_NAME      "libstrong")
set(PACKAGE_VERSION   "0.0.0")
set(PACKAGE_STRING    "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_TARNAME   "${PACKAGE_NAME}-${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "https://github.com/mistr/strong-type/issues/")

set(LibStrong_INSTALL_LIBDIR "lib" CACHE STRING "Installation directory for libraries")
set(LibStrong_INSTALL_INCLUDEDIR "include" CACHE STRING "Installation directory for headers")
set(LibStrong_INSTALL_CMAKEDIR "lib/cmake/${LIBRARY_NAME}" CACHE STRING "Installation directory for cmake config files")

# Options
option(LibStrong_BUILD_TESTS "Build tests" OFF)

cmake_policy(SET CMP0048 NEW)
project(LibStrong
    VERSION "${PACKAGE_VERSION}"
    LANGUAGES CXX)

message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

##############################################
# Create target and set properties
add_library(strong INTERFACE)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(LibStrong::library ALIAS strong)

#Set target properties
target_include_directories(strong
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(strong INTERFACE cxx_decltype_auto)
target_compile_options(strong INTERFACE $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -ggdb -grecord-gcc-switches>)

add_library(strong-static-asserts src/type.cc)
set_target_properties(strong-static-asserts PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
target_link_libraries(strong-static-asserts PRIVATE LibStrong::library)

if(LibStrong_BUILD_TESTS)
    add_subdirectory(test)
endif()
