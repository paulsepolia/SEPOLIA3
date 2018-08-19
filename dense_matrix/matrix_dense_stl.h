#pragma once

#include "matrix_dense_declaration.h"

using sepolia::matrix_dense;

template<typename T>
uint64_t matrix_dense<T>::rows() const {

    return _rows;
}

template<typename T>
uint64_t matrix_dense<T>::columns() const {

    return _columns;
}

template<typename T>
T *matrix_dense<T>::begin() {

    return _mdsp.get();
}

template<typename T>
const T *matrix_dense<T>::begin() const {

    return _mdsp.get();
}

template<typename T>
T *matrix_dense<T>::end() {

    return _mdsp.get() + (_rows * _columns);
}

template<typename T>
const T *matrix_dense<T>::end() const {

    return _mdsp.get() + (_rows * _columns);
}

template<typename T>
const T &matrix_dense<T>::at(const uint64_t &row, const uint64_t &column) const {

    return _mdsp.get()[row * _columns + column];
}

template<typename T>
void matrix_dense<T>::swap(matrix_dense<T> &matrix_in) {

    if (*this == matrix_in) {
        return;
    }

    matrix_dense<T> matrix_tmp(std::move(*this));
    *this = std::move(matrix_in);
    matrix_in = std::move(matrix_tmp);
}

template<typename T>
bool matrix_dense<T>::empty() const {

    return _rows == 0 || _columns == 0;
}
