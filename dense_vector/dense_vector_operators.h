#pragma once

#include <algorithm>
#include "dense_vector_declaration.h"

using sepolia::dense_vector;

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const std::vector<T> &vector_std) {

    const auto dimension = vector_std.size();

    this->deallocate();
    this->allocate(dimension);

    std::copy(vector_std.begin(), vector_std.end(), this->begin());

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(std::vector<T> &&vector_std) {

    const auto dimension = vector_std.size();

    this->deallocate();
    this->allocate(dimension);

    std::move(vector_std.begin(), vector_std.end(), this->begin());

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const dense_vector<T> &vector) {

    this->allocate(vector.size());
    this->set(vector);

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(dense_vector<T> &&vector) noexcept {

    if (this != &vector) {
        this->deallocate();
        this->_dsp = std::move(vector._dsp);
        this->_allocated = vector.allocated();
        this->_dimension = vector.size();
        this->_rows = vector.rows();
        this->_columns = vector.columns();
        vector._dimension = 0;
        vector._rows = 0;
        vector._columns = 0;
        vector._allocated = false;
    }

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const T &value) {

    this->allocate(this->size());
    this->set(value);

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(const dense_container<T> &vector) {

    this->allocate(vector.size());
    this->set(vector);

    return *this;
}

template<typename T>
dense_vector<T> &dense_vector<T>::operator=(dense_container<T> &&vector) noexcept {

    if (this != &vector) {
        this->deallocate();
        this->_dsp = std::move(vector._dsp);
        this->_allocated = vector.allocated();
        this->_dimension = vector.size();
        this->_rows = vector.rows();
        this->_columns = vector.columns();
        vector._dimension = 0;
        vector._rows = 0;
        vector._columns = 0;
        vector._allocated = false;
    }

    return *this;
}