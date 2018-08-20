#pragma once

#include "dense_container_declaration.h"

using sepolia::dense_container;

template<typename T>
uint64_t dense_container<T>::rows() const {

    return _rows;
}

template<typename T>
uint64_t dense_container<T>::columns() const {

    return _columns;
}

template<typename T>
T *dense_container<T>::begin() {

    return _mdsp.get();
}

template<typename T>
const T *dense_container<T>::begin() const {

    return _mdsp.get();
}

template<typename T>
T *dense_container<T>::end() {

    return _mdsp.get() + (_rows * _columns);
}

template<typename T>
const T *dense_container<T>::end() const {

    return _mdsp.get() + (_rows * _columns);
}

template<typename T>
const T &dense_container<T>::at(const uint64_t &row, const uint64_t &column) const {

    return _mdsp.get()[row * _columns + column];
}

template<typename T>
void dense_container<T>::swap(dense_container<T> &matrix_in) {

    if (*this == matrix_in) {
        return;
    }

    dense_container<T> matrix_tmp(std::move(*this));
    *this = std::move(matrix_in);
    matrix_in = std::move(matrix_tmp);
}

template<typename T>
bool dense_container<T>::empty() const {

    return _rows == 0 || _columns == 0;
}
