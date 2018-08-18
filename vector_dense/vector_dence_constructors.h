#pragma once

#include <memory>
#include "vector_dense_declaration.h"


template<typename T>
sepolia::vector_dense<T>::vector_dense():
        _dimension(0),
        _allocated(false) {

    _vdsp.reset();
}

template<typename T>
sepolia::vector_dense<T>::vector_dense(const uint64_t &dim, const T &val):
        _dimension(dim),
        _allocated(false) {

    _vdsp.reset(new T[dim]);

    const auto tmp = _vdsp.get();

    for (uint64_t i = 0; i < dim; i++) {
        tmp[i] = static_cast<T>(val);
    }

    _allocated = true;
}

template<typename T>
sepolia::vector_dense<T>::vector_dense(const sepolia::vector_dense<T> &vec):
        _dimension(vec._dimension),
        _allocated(vec._allocated) {

    _vdsp.reset(new T[vec._dimension]);

    const auto tmp1 = _vdsp.get();
    const auto tmp2 = vec._vdsp.get();

    for (uint64_t i = 0; i < _dimension; i++) {
        tmp1[i] = tmp2[i];
    }
}

template<typename T>
sepolia::vector_dense<T>::vector_dense(sepolia::vector_dense<T> &&vec) noexcept :
        _dimension(vec._dimension),
        _allocated(vec._allocated) {

    _vdsp.reset();
    _vdsp = std::move(vec._vdsp);
    vec._allocated = false;
    vec._dimension = 0;
}

template<typename T>
sepolia::vector_dense<T>::~vector_dense() {
    _vdsp.reset();
}