cmake_minimum_required(VERSION 3.12)
project(matrix_cpp)

set(CMAKE_CXX_STANDARD 14)

add_library(matrix_cpp library.cpp library.h Matrix.cpp Matrix.h)