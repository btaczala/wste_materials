project(mv CXX)

cmake_minimum_required(VERSION 3.7)
enable_testing()
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)


if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
endif()

include(cmake/CodeCoverage.cmake)
#add_executable(mv main.cpp FileImpl.cpp)
add_executable(mv main_new.cpp FileImpl.cpp)








#find_package(GMock REQUIRED)
#include_directories(${GMOCK_INCLUDE_DIRS})
#setup_target_for_coverage(tests_coverage mv-tests coverage)
