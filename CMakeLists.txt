cmake_minimum_required(VERSION 3.8)
project(bigint)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp bigint.cpp bigint.hpp intplace.cpp intplace.h)
add_executable(bigint ${SOURCE_FILES})