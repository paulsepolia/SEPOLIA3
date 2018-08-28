#!/bin/bash

tests_all="dot transpose"

if [ $1 = 'all' ]; then
    tests=${tests_all}
else
    tests=$1
fi

for var in ${tests}
do

    ls x_gnu_${var} 2> /dev/null

    if [ $? -eq 0 ]; then
        rm x_gnu_${var}
    fi

    g++-8.2.0   -O3                             \
                -Wall                           \
                -std=gnu++17                    \
                -fopenmp                        \
                -isystem                        \
                /opt/gtest/1.7.0/include        \
                -pthread                        \
                test_${var}.cpp                 \
                ../../functions_aux/*.cpp       \
                ../../algebra/*.cpp             \
                driver_program.cpp              \
                -L/opt/_intel/mkl/lib/intel64   \
                -Wl,-R/opt/_intel/mkl/lib/intel64  -lmkl_lapack95_lp64 \
                -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lmkl_sequential -lm \
                /opt/gtest/1.7.0/lib/libgtest.a \
                -o x_gnu_${var}

    ./x_gnu_${var}

done
