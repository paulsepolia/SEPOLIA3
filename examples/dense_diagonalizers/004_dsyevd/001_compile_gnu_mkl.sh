#!/bin/bash

  g++-8.2.0  -std=gnu++17 \
             -Wall \
             -O3 \
             -fopenmp \
             ../../../functions_aux/functions_aux.cpp \
             ../../../dense_diagonalizers/dense_diagonalizers.cpp \
             driver_program_dsyevd.cpp \
             -L/opt/_intel/mkl/lib/intel64 \
             -Wl,-R/opt/_intel/mkl/lib/intel64  -lmkl_lapack95_lp64 \
             -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lmkl_sequential -lm \
             -o x_gnu_dsyevd
