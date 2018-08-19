cmake_minimum_required(VERSION 3.12)
project(sepolia3)

set(CMAKE_CXX_STANDARD 17)

add_executable(sepolia3 fake_main.cpp dense_vector/vector_dense_parameters.h dense_vector/vector_dense_stl.h tests_unit/dense_vector/test_algebra.cpp tests_unit/dense_vector/test_stl_compatibility.cpp)
