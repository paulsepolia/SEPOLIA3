#pragma once

#include "dense_container_declaration.h"

using sepolia::dense_container;

template<typename T>
void dense_container<T>::allocate(const uint64_t & dimension) {

    _dimension = dimension;
    _dsp.reset(new T[dimension]);
    _allocated = (dimension != 0);
}

template<typename T>
bool dense_container<T>::allocated() const {

    return _allocated;
}

template<typename T>
void dense_container<T>::deallocate() {

    _dsp.reset();
    _allocated = false;
}

template<typename T>
bool dense_container<T>::deallocated() const {

    return !_allocated;
}
