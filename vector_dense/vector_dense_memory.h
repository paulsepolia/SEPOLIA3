#pragma once

#include "vector_dense_declaration.h"

template<typename T>
inline void sepolia::vector_dense<T>::allocate(const uint64_t &dim) {

    _dimension = dim;
    _vdsp.reset(new T[dim]);
    _allocated = true;
}

template<typename T>
inline bool sepolia::vector_dense<T>::allocated() const {

    return _allocated;
}

template<typename T>
inline void sepolia::vector_dense<T>::deallocate() {

    _dimension = 0;
    _vdsp.reset();
    _allocated = false;
}

template<typename T>
inline bool sepolia::vector_dense<T>::deallocated() const {

    return !_allocated;
}
