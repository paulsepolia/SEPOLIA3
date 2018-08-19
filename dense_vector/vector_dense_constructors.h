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
vector_dense<T>::vector_dense(const uint64_t &dimension, const T &value):
        _dimension(dimension),
        _allocated(false) {

    _vdsp.reset(new T[dimension]);

    const auto vector = _vdsp.get();

    for (uint64_t i = 0; i < dimension; i++) {
        vector[i] = static_cast<T>(value);
    }

    _allocated = (dimension != 0);
}

template<typename T>
vector_dense<T>::vector_dense(const vector_dense<T> &vector):
        _dimension(vector._dimension),
        _allocated(vector._allocated) {

    _vdsp.reset(new T[vector._dimension]);

    const auto vector_out = _vdsp.get();
    const auto vector_in = vector._vdsp.get();

    for (uint64_t i = 0; i < _dimension; i++) {
        vector_out[i] = vector_in[i];
    }
}

template<typename T>
vector_dense<T>::vector_dense(vector_dense<T> &&vector) noexcept :
        _dimension(vector._dimension),
        _allocated(vector._allocated) {

    _vdsp.reset();
    _vdsp = std::move(vector._vdsp);
    vector._allocated = false;
    vector._dimension = 0;
}

template<typename T>
vector_dense<T>::~vector_dense() {
    _vdsp.reset();
}