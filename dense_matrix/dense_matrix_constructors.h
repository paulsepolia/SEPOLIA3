#pragma once

#include "dense_matrix_declaration.h"

using sepolia::dense_matrix;

template<typename T>
dense_matrix<T>::dense_matrix():
        dense_container<T>() {}

template<typename T>
dense_matrix<T>::dense_matrix(const uint64_t &rows,
                              const uint64_t &columns):
        dense_container<T>(rows, columns) {}

template<typename T>
dense_matrix<T>::dense_matrix(const dense_matrix<T> &matrix):
        dense_container<T>(matrix) {}

template<typename T>
dense_matrix<T>::dense_matrix(dense_matrix<T> &&matrix) noexcept :
        dense_container<T>(std::move(matrix)) {}

template<typename T>
dense_matrix<T>::~dense_matrix() = default;