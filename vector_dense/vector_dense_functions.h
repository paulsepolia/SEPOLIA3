#pragma once

#include "vector_dense_declaration.h"

template<typename T>
uint64_t sepolia::vector_dense<T>::size() const {

    return _dimension;
}

template<typename T>
T *sepolia::vector_dense<T>::begin() {

    return _vdsp.get();
}

template<typename T>
const T *sepolia::vector_dense<T>::begin() const {

    return _vdsp.get();
}

template<typename T>
T *sepolia::vector_dense<T>::end() {

    return _vdsp.get() + _dimension;
}

template<typename T>
const T *sepolia::vector_dense<T>::end() const {

    return _vdsp.get() + _dimension;
}