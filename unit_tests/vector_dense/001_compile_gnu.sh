#!/bin/bash

#tests_all="algop constructors exceptions memory oper set_get speed stl_algos stl_members utils"

tests_all="constructors memory operators speed set_get"

if [ $1 = 'all' ]; then
    tests=$tests_all
else
    tests=$1
fi

for var in $tests
do

    ls x_gnu_$var 2> /dev/null

    if [ $? -eq 0 ]; then
        rm x_gnu_$var
    fi

    g++.8.2.0   -O3                             \
                -Wall                           \
                -std=gnu++17                    \
                -fopenmp                        \
                -D_GLIBCXX_PARALLEL             \
                -isystem                        \
                /opt/gtest/1.7.0/include        \
                -pthread                        \
                test_unit_$var.cpp              \
                driver_program.cpp              \
                /opt/gtest/1.7.0/lib/libgtest.a \
                -o x_gnu_$var

    ./x_gnu_$var

done
