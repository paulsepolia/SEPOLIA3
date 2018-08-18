#pragma once

#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
vector_dense<T>::vector_dense():
        _dimension(0),
        _allocated(false) {

    _vdsp.reset();
}

template<typename T>
vector_dense<T>::vector_dense(const uint64_t &dim, const T &val):
        _dimension(dim),
        _allocated(false) {

    _vdsp.reset(new T[dim]);

    const auto vector = _vdsp.get();

    for (uint64_t i = 0; i < dim; i++) {
        vector[i] = static_cast<T>(val);
    }

    _allocated = true;
}

template<typename T>
vector_dense<T>::vector_dense(const vector_dense<T> &vec):
        _dimension(vec._dimension),
        _allocated(vec._allocated) {

    _vdsp.reset(new T[vec._dimension]);

    const auto vector_out = _vdsp.get();
    const auto vector_in = vec._vdsp.get();

    for (uint64_t i = 0; i < _dimension; i++) {
        vector_out[i] = vector_in[i];
    }
}

template<typename T>
vector_dense<T>::vector_dense(vector_dense<T> &&vec) noexcept :
        _dimension(vec._dimension),
        _allocated(vec._allocated) {

    _vdsp.reset();
    _vdsp = std::move(vec._vdsp);
    vec._allocated = false;
    vec._dimension = 0;
}

template<typename T>
vector_dense<T>::~vector_dense() {
    _vdsp.reset();
}