#pragma once

#include "../dense_container/dense_container.h"
#include "dense_vector_declaration.h"

using sepolia::dense_vector;

template<typename T>
dense_vector<T>::dense_vector():
        dense_container<T>() {}

template<typename T>
dense_vector<T>::dense_vector(const uint64_t &dimension, const T &value):
        dense_container<T>(dimension, value) {

}

template<typename T>
dense_vector<T>::dense_vector(const dense_vector<T> &vector):
        dense_container<T>(vector) {

}

template<typename T>
dense_vector<T>::dense_vector(dense_vector<T> &&vector) noexcept :
        dense_container<T>(std::move(vector)) {

}

template<typename T>
dense_vector<T>::~dense_vector() = default;
