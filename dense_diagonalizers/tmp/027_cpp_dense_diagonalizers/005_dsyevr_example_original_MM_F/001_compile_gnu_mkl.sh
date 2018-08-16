#!/bin/bash


  g++   -std=c++0x               \
        -Wall                    \
        -O3                      \
        -fopenmp                  \
        driver_program.cpp       \
        -L/opt/_intel/mkl/lib/intel64                                     \
        -Wl,-R/opt/_intel/mkl/lib/intel64  -lmkl_lapack95_lp64            \
        -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lmkl_sequential -lm \
        -o x_gnu_mkl

