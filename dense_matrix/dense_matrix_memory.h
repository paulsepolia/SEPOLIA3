#pragma once

#include "dense_matrix_declaration.h"

using sepolia::dense_matrix;

template<typename T>
void dense_matrix<T>::allocate(const uint64_t &rows,
                               const uint64_t &columns) {

    _rows = rows;
    _columns = columns;
    const uint64_t dimension = rows * columns;
    _mdsp.reset(new T[dimension]);
    _allocated = (dimension != 0);
}

template<typename T>
bool dense_matrix<T>::allocated() const {

    return _allocated;
}

template<typename T>
void dense_matrix<T>::deallocate() {

    _rows = 0;
    _columns = 0;
    _mdsp.reset();
    _allocated = false;
}

template<typename T>
bool dense_matrix<T>::deallocated() const {

    return !_allocated;
}
