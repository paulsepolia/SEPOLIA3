#pragma once

#include "../dense_container/dense_container.h"
#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
vector_dense<T>::vector_dense():
        dense_container<T>() {}

template<typename T>
vector_dense<T>::vector_dense(const uint64_t &dimension, const T &value):
        dense_container<T>(dimension, value) {

}

template<typename T>
vector_dense<T>::vector_dense(const vector_dense<T> &vector):
        dense_container<T>(vector) {

}

template<typename T>
vector_dense<T>::vector_dense(vector_dense<T> &&vector) noexcept :
        dense_container<T>(std::move(vector)) {

}

template<typename T>
vector_dense<T>::~vector_dense() = default;
