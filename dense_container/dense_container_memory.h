#pragma once

#include "dense_container_declaration.h"
#include <iostream>

using sepolia::dense_container;

template<typename T>
void dense_container<T>::allocate(const uint64_t &dimension) {

    _dimension = dimension;
    _dsp.reset(new T[dimension]);
    _allocated = (dimension != 0);
    _rows = _allocated ? 1 : 0;
    _columns = _allocated ? dimension : 0;
}

template<typename T>
void dense_container<T>::allocate(const uint64_t &rows, const uint64_t &columns) {

    const uint64_t dimension = rows * columns;
    _dimension = dimension;
    _dsp.reset(new T[dimension]);
    _allocated = (dimension != 0);
    _rows = _allocated ? rows : 0;
    _columns = _allocated ? columns : 0;
}

template<typename T>
bool dense_container<T>::allocated() const {

    return _allocated;
}

template<typename T>
void dense_container<T>::deallocate() {

    _dimension = 0;
    _rows = 0;
    _columns = 0;
    _dsp.reset();
    _allocated = false;
}

template<typename T>
bool dense_container<T>::deallocated() const {

    return !_allocated;
}
