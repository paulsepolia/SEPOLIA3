#pragma once

#include <iostream>
#include "dense_container_declaration.h"

using sepolia::dense_container;

template<typename T>
dense_container<T>::dense_container():
        _dimension(0),
        _allocated(false) {

    _dsp.reset();
}

template<typename T>
dense_container<T>::dense_container(const uint64_t &dimension, const T &val):
        _dimension(dimension),
        _allocated(false) {

    set(val);
}

template<typename T>
dense_container<T>::dense_container(const dense_container<T> &dense_in):
        _dimension(dense_in._dimension),
        _allocated(dense_in._allocated) {

    set(dense_in);

}

template<typename T>
dense_container<T>::dense_container(dense_container<T> &&dense_in) noexcept :
        _dimension(dense_in._dimension),
        _allocated(dense_in._allocated) {

    _dsp.reset();
    _dsp = std::move(dense_in._dsp);
    dense_in._allocated = false;
    dense_in._dimension = 0;
}

template<typename T>
dense_container<T>::~dense_container() {

    _dsp.reset();
}