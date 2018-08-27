#!/bin/bash

    g++-8.2.0   -g                  \
                -O0                 \
                -Wall               \
                -std=gnu++17        \
                -fopenmp            \
                ../../dense_container/dense_container_declaration.cpp \
                driver_program.cpp  \
                -o x_gnu_valgrind

    valgrind --leak-check=yes ./x_gnu_valgrind 2>&1 | grep -E '(definitely lost|false)'
