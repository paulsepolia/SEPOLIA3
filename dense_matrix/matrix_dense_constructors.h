#pragma once

#include "matrix_dense_declaration.h"

using sepolia::matrix_dense;

template<typename T>
matrix_dense<T>::matrix_dense():
        _rows(0),
        _columns(0),
        _allocated(false) {

    _mdsp.reset();
}

template<typename T>
matrix_dense<T>::matrix_dense(const uint64_t &rows,
                              const uint64_t &columns,
                              const T &val):
        _rows(rows),
        _columns(columns),
        _allocated(false) {

    const uint64_t dimension = rows * columns;
    _mdsp.reset(new T[dimension]);

    const auto matrix = _mdsp.get();

    for (uint64_t i = 0; i < dimension; i++) {
        matrix[i] = static_cast<T>(val);
    }

    _allocated = (dimension != 0);
}

template<typename T>
matrix_dense<T>::matrix_dense(const matrix_dense<T> &matrix):
        _rows(matrix._rows),
        _columns(matrix._columns),
        _allocated(matrix._allocated) {

    const uint64_t dimension = _rows * _columns;

    _mdsp.reset(new T[dimension]);

    const auto matrix_in = matrix._mdsp.get();
    const auto matrix_out = _mdsp.get();

    for (uint64_t i = 0; i < dimension; i++) {
        matrix_out[i] = matrix_in[i];
    }
}

template<typename T>
matrix_dense<T>::matrix_dense(matrix_dense<T> &&matrix) noexcept :
        _rows(matrix._rows),
        _columns(matrix._columns),
        _allocated(matrix._allocated) {

    _mdsp.reset();
    _mdsp = std::move(matrix._mdsp);
    matrix._allocated = false;
    matrix._rows = 0;
    matrix._columns = 0;
}

template<typename T>
matrix_dense<T>::~matrix_dense() {
    _mdsp.reset();
}