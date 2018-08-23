#pragma once

#include <algorithm>
#include "dense_matrix_declaration.h"

using sepolia::dense_matrix;

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const dense_matrix<T> &matrix) {

    dense_matrix<T>::set(matrix);

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(dense_matrix<T> &&matrix) noexcept {

    if (this != &matrix) {
        dense_matrix<T>::deallocate();
        dense_matrix<T>::_dsp = std::move(matrix._dsp);
        dense_matrix<T>::_allocated = matrix._allocated;
        dense_matrix<T>::_rows = matrix._rows;
        dense_matrix<T>::_columns = matrix._columns;
        dense_matrix<T>::_dimension = matrix._columns * matrix._rows;
        matrix._rows = 0;
        matrix._columns = 0;
        matrix._dimension = 0;
        matrix._allocated = false;
    }

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const dense_container<T> &matrix) {

    dense_matrix<T>::set(matrix);

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(dense_container<T> &&matrix) noexcept {

    if (this != &matrix) {
        dense_matrix<T>::deallocate();
        dense_matrix<T>::_dsp = std::move(matrix._dsp);
        dense_matrix<T>::_allocated = matrix._allocated;
        dense_matrix<T>::_dimension = matrix._dimension;
        dense_matrix<T>::_rows = matrix._rows;
        dense_matrix<T>::_columns = matrix._columns;
        matrix._dimension = 0;
        matrix._rows = 0;
        matrix._columns = 0;
        matrix._allocated = false;
    }

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const T &value) {

    dense_matrix<T>::set(value);

    return *this;
}