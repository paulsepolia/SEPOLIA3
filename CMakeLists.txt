cmake_minimum_required(VERSION 3.12)
project(sepolia3)

set(CMAKE_CXX_STANDARD 17)

add_executable(sepolia3 main.cpp vector_dense/vector_dense_parameters.h vector_dense/vector_dense_functions.h)
