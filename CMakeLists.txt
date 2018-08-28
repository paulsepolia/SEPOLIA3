cmake_minimum_required(VERSION 3.12)
project(sepolia3)

set(CMAKE_CXX_STANDARD 17)

add_executable(sepolia3 fake_main.cpp tests_unit/dense_vector/test_algebra.cpp tests_unit/dense_vector/test_stl_compatibility.cpp parameters/parameters.h dense_diagonalizers/dense_eigensystem.h sepolia/sepolia.h algebra/algrebra.h functions_aux/overloaded_operators.cpp functions_aux/overloaded_operators.h)
