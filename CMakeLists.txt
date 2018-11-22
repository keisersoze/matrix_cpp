cmake_minimum_required(VERSION 3.12)
project(matrix_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(test2 main.cpp matrix_impl.h matrix.h)
