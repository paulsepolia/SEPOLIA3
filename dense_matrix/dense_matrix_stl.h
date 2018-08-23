#pragma once

#include "dense_matrix_declaration.h"

using sepolia::dense_matrix;

template<typename T>
uint64_t dense_matrix<T>::rows() const {

    return _rows;
}

template<typename T>
uint64_t dense_matrix<T>::columns() const {

    return _columns;
}

template<typename T>
T *dense_matrix<T>::begin() {

    return _mdsp.get();
}

template<typename T>
const T *dense_matrix<T>::begin() const {

    return _mdsp.get();
}

template<typename T>
T *dense_matrix<T>::end() {

    return _mdsp.get() + (_rows * _columns);
}

template<typename T>
const T *dense_matrix<T>::end() const {

    return _mdsp.get() + (_rows * _columns);
}

template<typename T>
const T &dense_matrix<T>::at(const uint64_t &row, const uint64_t &column) const {

    return _mdsp.get()[row * _columns + column];
}

template<typename T>
void dense_matrix<T>::swap(dense_matrix<T> &matrix_in) {

    if (*this == matrix_in) {
        return;
    }

    dense_matrix<T> matrix_tmp(std::move(*this));
    *this = std::move(matrix_in);
    matrix_in = std::move(matrix_tmp);
}

template<typename T>
bool dense_matrix<T>::empty() const {

    return _rows == 0 || _columns == 0;
}
