#pragma once

#include <algorithm>
#include "dense_matrix_declaration.h"

using sepolia::dense_matrix;

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const dense_matrix<T> &matrix) {

    this->allocate(matrix.rows(), matrix.columns());
    this->set(matrix);

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(dense_matrix<T> &&matrix) noexcept {

    if (this != &matrix) {
        this->deallocate();
        this->_dsp = std::move(matrix._dsp);
        this->_allocated = matrix.allocated();
        this->_rows = matrix.rows();
        this->_columns = matrix.columns();
        this->_dimension = matrix.rows() * matrix.columns();
        matrix._rows = 0;
        matrix._columns = 0;
        matrix._dimension = 0;
        matrix._allocated = false;
    }

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const dense_container<T> &matrix) {

    this->allocate(matrix.rows(), matrix.columns());
    this->set(matrix);

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(dense_container<T> &&matrix) noexcept {

    if (this != &matrix) {
        this->deallocate();
        this->_dsp = std::move(matrix._dsp);
        this->_allocated = matrix.allocated();
        this->_dimension = matrix.size();
        this->_rows = matrix.rows();
        this->_columns = matrix.columns();
        matrix._dimension = 0;
        matrix._rows = 0;
        matrix._columns = 0;
        matrix._allocated = false;
    }

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const T &value) {

    this->allocate(this->rows(), this->columns());
    this->set(value);

    return *this;
}