cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 14)

project(Median)
enable_testing()
add_executable(Median src/Median.cpp src/Median.hpp)
add_test(test1 Median)