#pragma once

#include "dense_container_declaration.h"

using sepolia::dense_container;

template<typename T>
uint64_t dense_container<T>::size() const {

    return _dimension;
}

template<typename T>
T *dense_container<T>::begin() {

    return _dsp.get();
}

template<typename T>
const T *dense_container<T>::begin() const {

    return _dsp.get();
}

template<typename T>
T *dense_container<T>::end() {

    return _dsp.get() + _dimension;
}

template<typename T>
const T *dense_container<T>::end() const {

    return _dsp.get() + _dimension;
}

template<typename T>
const T &dense_container<T>::at(const uint64_t &index) const {

    return _dsp.get()[index];
}

template<typename T>
const T &dense_container<T>::at(const uint64_t & row, const uint64_t & column) const {

    return _dsp.get()[row * _dimension + column];
}

template<typename T>
void dense_container<T>::swap(dense_container<T> &dense_in) {

    if (*this == dense_in) {
        return;
    }

    dense_container<T> dense_tmp(std::move(*this));
    *this = std::move(dense_in);
    dense_in = std::move(dense_tmp);
}

template<typename T>
bool dense_container<T>::empty() const {

    return _dimension == 0;
}
