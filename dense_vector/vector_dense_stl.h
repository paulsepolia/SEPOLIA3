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

template<typename T>
const T &vector_dense<T>::at(const uint64_t &index) const {

    return _vdsp.get()[index];
}

template<typename T>
void vector_dense<T>::swap(vector_dense<T> &vec_in) {

    if (*this == vec_in) {
        return;
    }

    vector_dense<T> vec_tmp(std::move(*this));
    *this = std::move(vec_in);
    vec_in = std::move(vec_tmp);
}

template<typename T>
bool vector_dense<T>::empty() const {

    return _dimension == 0;
}
