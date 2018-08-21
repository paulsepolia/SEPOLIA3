#pragma once

#include <algorithm>
#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const std::vector<T> &vector_std) {

    const auto dimension = vector_std.size();

    dense_container<T>::deallocate();
    dense_container<T>::allocate(dimension);

    std::copy(vector_std.begin(), vector_std.end(), dense_container<T>::_dsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(std::vector<T> &&vector_std) {

    const auto dimension = vector_std.size();

    dense_container<T>::deallocate();
    dense_container<T>::allocate(dimension);

    std::move(vector_std.begin(), vector_std.end(), dense_container<T>::_dsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const vector_dense<T> &vector) {

    dense_container<T>::set(vector);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const T &value) {

    dense_container<T>::set(value);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(vector_dense<T> &&vector) noexcept {

    if (this != &vector) {
        dense_container<T>::deallocate();
        dense_container<T>::_dsp = std::move(vector._dsp);
        dense_container<T>::_allocated = vector._allocated;
        dense_container<T>::_dimension = vector._dimension;
        vector._dimension = 0;
        vector._allocated = false;
    }

    return *this;
}