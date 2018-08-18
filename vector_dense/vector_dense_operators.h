#pragma once

#include "vector_dense_declaration.h"

template<typename T>
uint64_t sepolia::vector_dense<T>::size() const {

    return _dimension;
}

template<typename T>
sepolia::vector_dense<T> &sepolia::vector_dense<T>::operator=(const std::vector<T> &vec_std) {

    const auto dimension(vec_std.size());

    deallocate();
    allocate(dimension);

    std::copy(vec_std.begin(), vec_std.end(), _vdsp.get());

    return *this;
}

template<typename T>
sepolia::vector_dense<T> &sepolia::vector_dense<T>::operator=(std::vector<T> &&vec_std) {

    const auto dimension(vec_std.size());

    this->deallocate();
    this->allocate(dimension);

    std::move(vec_std.begin(), vec_std.end(), _vdsp.get());

    return *this;
}

template<typename T>
sepolia::vector_dense<T> &sepolia::vector_dense<T>::operator=(const sepolia::vector_dense<T> &vec) {

    set(vec);

    return *this;
}

template<typename T>
sepolia::vector_dense<T> &sepolia::vector_dense<T>::operator=(const T &val) {


    set(val);

    return *this;
}

template<typename T>
sepolia::vector_dense<T> &sepolia::vector_dense<T>::operator=(sepolia::vector_dense<T> &&vec) noexcept {

    if (this != &vec) {
        deallocate();
        _vdsp = std::move(vec._vdsp);
        _allocated = vec._allocated;
        _dimension = vec._dimension;
        vec._dimension = 0;
        vec._allocated = false;
    }

    return *this;
}

template<typename T>
inline T &sepolia::vector_dense<T>::operator()(const uint64_t &index) const {

    return _vdsp.get()[index];
}