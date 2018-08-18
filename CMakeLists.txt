cmake_minimum_required(VERSION 3.12)
project(sepolia3)

set(CMAKE_CXX_STANDARD 17)

add_executable(sepolia3 fake_main.cpp vector_dense/vector_dense_parameters.h vector_dense/vector_dense_stl.h unit_tests/vector_dense/test_unit_algebra.cpp)
