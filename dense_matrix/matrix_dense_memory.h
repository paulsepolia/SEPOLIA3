#pragma once

#include "matrix_dense_declaration.h"

using sepolia::matrix_dense;

template<typename T>
void matrix_dense<T>::allocate(const uint64_t &rows,
                               const uint64_t &columns) {

    _rows = rows;
    _columns = columns;
    const uint64_t dimension = rows * columns;
    _mdsp.reset(new T[dimension]);
    _allocated = (dimension != 0);
}

template<typename T>
bool matrix_dense<T>::allocated() const {

    return _allocated;
}

template<typename T>
void matrix_dense<T>::deallocate() {

    _rows = 0;
    _columns = 0;
    _mdsp.reset();
    _allocated = false;
}

template<typename T>
bool matrix_dense<T>::deallocated() const {

    return !_allocated;
}
