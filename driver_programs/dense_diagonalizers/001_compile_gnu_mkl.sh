#!/bin/bash


  g++.8.2.0  -std=gnu++17 \
             -Wall \
             -O3 \
             -fopenmp \
             ../../containers/containers.cpp \
             ../../dense_diagonalizers/eigensystem_dense.cpp \
             ../../aux_functions/aux_functions.cpp \
             ../../dense_diagonalizers/dense_diagonalizers.cpp \
             driver_program_dsyevd.cpp \
             -L/opt/_intel/mkl/lib/intel64 \
             -Wl,-R/opt/_intel/mkl/lib/intel64  -lmkl_lapack95_lp64 \
             -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lmkl_sequential -lm \
             -o x_gnu_dsyevd


  g++.8.2.0  -std=gnu++17 \
             -Wall \
             -O3 \
             -fopenmp \
             ../../containers/containers.cpp \
             ../../dense_diagonalizers/eigensystem_dense.cpp \
             ../../aux_functions/aux_functions.cpp \
             ../../dense_diagonalizers/dense_diagonalizers.cpp \
             driver_program_dsyev.cpp \
             -L/opt/_intel/mkl/lib/intel64 \
             -Wl,-R/opt/_intel/mkl/lib/intel64  -lmkl_lapack95_lp64 \
             -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lmkl_sequential -lm \
             -o x_gnu_dsyev
