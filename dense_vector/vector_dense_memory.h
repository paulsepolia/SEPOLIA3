#pragma once

#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
void vector_dense<T>::allocate(const uint64_t &dimension) {

    _dimension = dimension;
    _vdsp.reset(new T[dimension]);
    _allocated = (dimension != 0);
}

template<typename T>
bool vector_dense<T>::allocated() const {

    return _allocated;
}

template<typename T>
void vector_dense<T>::deallocate() {

    _dimension = 0;
    _vdsp.reset();
    _allocated = false;
}

template<typename T>
bool vector_dense<T>::deallocated() const {

    return !_allocated;
}
