#!/bin/bash

    g++-8.2.0   -O3                 \
                -Wall               \
                -std=gnu++17        \
                -fopenmp            \
                -pthread            \
                driver_program.cpp  \
                -o x_gnu

