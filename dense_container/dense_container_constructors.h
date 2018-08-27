#pragma once

#include <iostream>
#include "dense_container_declaration.h"

using sepolia::dense_container;

template<typename T>
dense_container<T>::dense_container():
        _rows(0),
        _columns(0),
        _dimension(0),
        _allocated(false) {

    _dsp.reset();
}

template<typename T>
dense_container<T>::dense_container(const uint64_t &dimension):
        _rows(1),
        _columns(dimension),
        _dimension(dimension),
        _allocated(false) {

    if (dimension == 0) {
        _rows = 0;
        return;
    }

    allocate(_rows, _columns);
}

template<typename T>
dense_container<T>::dense_container(const uint64_t &rows, const uint64_t &columns):
        _rows(rows),
        _columns(columns),
        _dimension(rows * columns),
        _allocated(false) {

    if (_dimension == 0) {
        _rows = 0;
        _columns = 0;
        return;
    }

    allocate(_rows, _columns);
}

template<typename T>
dense_container<T>::dense_container(const dense_container<T> &dense_in):
        _rows(dense_in._rows),
        _columns(dense_in._columns),
        _dimension(dense_in._dimension),
        _allocated(dense_in._allocated) {

    allocate(_rows, _columns);
    set(dense_in);
}

template<typename T>
dense_container<T>::dense_container(dense_container<T> &&dense_in) noexcept :
        _rows(dense_in._rows),
        _columns(dense_in._columns),
        _dimension(dense_in._dimension),
        _allocated(dense_in._allocated) {

    _dsp.reset();
    _dsp = std::move(dense_in._dsp);
    dense_in._allocated = false;
    dense_in._dimension = 0;
    dense_in._rows = 0;
    dense_in._columns = 0;
}

template<typename T>
dense_container<T>::~dense_container() {

    _dsp.reset();
}