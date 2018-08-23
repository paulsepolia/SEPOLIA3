#pragma once

#include <algorithm>
#include "dense_vector_declaration.h"

using sepolia::dense_vector;

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const std::vector<T> &vector_std) {

    const auto dimension = vector_std.size();

    dense_vector<T>::deallocate();
    dense_vector<T>::allocate(dimension);

    std::copy(vector_std.begin(), vector_std.end(), dense_vector<T>::_dsp.get());

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(std::vector<T> &&vector_std) {

    const auto dimension = vector_std.size();

    dense_vector<T>::deallocate();
    dense_vector<T>::allocate(dimension);

    std::move(vector_std.begin(), vector_std.end(), dense_vector<T>::_dsp.get());

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const dense_vector<T> &vector) {

    dense_vector<T>::allocate(vector.size());
    dense_vector<T>::set(vector);

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(dense_vector<T> &&vector) noexcept {

    if (this != &vector) {
        dense_vector<T>::deallocate();
        dense_vector<T>::_dsp = std::move(vector._dsp);
        dense_vector<T>::_allocated = vector._allocated;
        dense_vector<T>::_dimension = vector._dimension;
        dense_vector<T>::_rows = vector._rows;
        dense_vector<T>::_columns = vector._columns;
        vector._dimension = 0;
        vector._rows = 0;
        vector._columns = 0;
        vector._allocated = false;
    }

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const T &value) {

    dense_vector<T>::allocate(this->size());
    dense_vector<T>::set(value);

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const dense_container<T> &vector) {

    dense_vector<T>::allocate(vector.size());
    dense_vector<T>::set(vector);

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(dense_container<T> &&vector) noexcept {

    if (this != &vector) {
        dense_vector<T>::deallocate();
        dense_vector<T>::_dsp = std::move(vector._dsp);
        dense_vector<T>::_allocated = vector._allocated;
        dense_vector<T>::_dimension = vector._dimension;
        dense_vector<T>::_rows = vector._rows;
        dense_vector<T>::_columns = vector._columns;
        vector._dimension = 0;
        vector._rows = 0;
        vector._columns = 0;
        vector._allocated = false;
    }

    return *this;
}