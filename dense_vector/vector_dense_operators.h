#pragma once

#include <algorithm>
#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const std::vector<T> &vector_std) {

    const auto dimension = vector_std.size();

    vector_dense<T>::deallocate();
    vector_dense<T>::allocate(dimension);

    std::copy(vector_std.begin(), vector_std.end(), vector_dense<T>::_dsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(std::vector<T> &&vector_std) {

    const auto dimension = vector_std.size();

    vector_dense<T>::deallocate();
    vector_dense<T>::allocate(dimension);

    std::move(vector_std.begin(), vector_std.end(), vector_dense<T>::_dsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const vector_dense<T> &vector) {

    vector_dense<T>::set(vector);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(vector_dense<T> &&vector) noexcept {

    if (this != &vector) {
        vector_dense<T>::deallocate();
        vector_dense<T>::_dsp = std::move(vector._dsp);
        vector_dense<T>::_allocated = vector._allocated;
        vector_dense<T>::_dimension = vector._dimension;
        vector._dimension = 0;
        vector._allocated = false;
    }

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const T &value) {

    vector_dense<T>::set(value);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const dense_container<T> &vector) {

    vector_dense<T>::set(vector);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(dense_container<T> &&vector) noexcept {

    if (this != &vector) {
        vector_dense<T>::deallocate();
        vector_dense<T>::_dsp = std::move(vector._dsp);
        vector_dense<T>::_allocated = vector._allocated;
        vector_dense<T>::_dimension = vector._dimension;
        vector._dimension = 0;
        vector._allocated = false;
    }

    return *this;
}