#!/bin/bash

tests_all="constructors memory operators speed set_get algebra stl_compatibility stl general"

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
                ../../functions_aux/overloaded_operators.cpp \
                driver_program.cpp              \
                /opt/gtest/1.7.0/lib/libgtest.a \
                -o x_gnu_${var}

    ./x_gnu_${var}

done
