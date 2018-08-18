#pragma once

#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
uint64_t vector_dense<T>::size() const {

    return _dimension;
}

template<typename T>
T *vector_dense<T>::begin() {

    return _vdsp.get();
}

template<typename T>
const T *vector_dense<T>::begin() const {

    return _vdsp.get();
}

template<typename T>
T *vector_dense<T>::end() {

    return _vdsp.get() + _dimension;
}

template<typename T>
const T *vector_dense<T>::end() const {

    return _vdsp.get() + _dimension;
}