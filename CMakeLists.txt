cmake_minimum_required(VERSION 3.8)
project(bigint)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES bigint.cpp bigint.hpp test_c_str_ctor.cpp)
add_executable(bigint ${SOURCE_FILES})