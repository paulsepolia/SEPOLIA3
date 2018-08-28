#!/bin/bash

    g++-8.2.0   -O3                 \
                -Wall               \
                -std=gnu++17        \
                -fopenmp            \
                -pthread            \
                ../../../functions_aux/*.cpp \
                ../../../algebra/dot.cpp \
                driver_program.cpp  \
                -L/opt/_intel/mkl/lib/intel64 \
                -Wl,-R/opt/_intel/mkl/lib/intel64  -lmkl_lapack95_lp64 \
                -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lmkl_sequential -lm \
                -o x_gnu

