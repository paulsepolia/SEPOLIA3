#pragma once

#include <algorithm>
#include "dense_matrix_declaration.h"

using sepolia::dense_matrix;


template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const dense_matrix<T> &matrix) {

    set(matrix);

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(const T &value) {

    set(value);

    return *this;
}

template<typename T>
dense_matrix<T> &dense_matrix<T>::operator=(dense_matrix<T> &&matrix) noexcept {

    if (this != &matrix) {
        deallocate();
        _mdsp = std::move(matrix._mdsp);
        _allocated = matrix._allocated;
        _rows = matrix._rows;
        _columns = matrix._columns;
        matrix._rows = 0;
        matrix._columns = 0;
        matrix._allocated = false;
    }

    return *this;
}

template<typename T>
T &dense_matrix<T>::operator()
        (const uint64_t &row, const uint64_t &column) const {

    return _mdsp.get()[row * _columns + column];
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator+(const dense_matrix<T> &matrix) const {

    dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
    matrix_tmp = plus(matrix);

    return std::move(matrix_tmp);
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator+(const T &value) const {

    dense_matrix<T> matrix_tmp(_rows, _columns);
    matrix_tmp = plus(value);

    return std::move(matrix_tmp);
}

namespace sepolia {

    template<typename T>
    dense_matrix<T> operator+(const T &value, const dense_matrix<T> &matrix) {

        dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
        matrix_tmp = matrix.plus(value);

        return std::move(matrix_tmp);
    }
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator-(const dense_matrix<T> &matrix) const {

    dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
    matrix_tmp = subtract(matrix);

    return std::move(matrix_tmp);
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator-(const T &value) const {

    dense_matrix<T> matrix_tmp(_rows, _columns);
    matrix_tmp = subtract(value);

    return std::move(matrix_tmp);
}

namespace sepolia {

    template<typename T>
    dense_matrix<T> operator-(const T &value, const dense_matrix<T> &matrix) {

        dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
        matrix_tmp = matrix.subtract(value);

        return std::move(matrix_tmp);
    }
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator*(const dense_matrix<T> &matrix) const {

    dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
    matrix_tmp = times(matrix);

    return std::move(matrix_tmp);
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator*(const T &value) const {

    dense_matrix<T> matrix_tmp(_rows, _columns);
    matrix_tmp = times(value);

    return std::move(matrix_tmp);
}

namespace sepolia {

    template<typename T>
    dense_matrix<T> operator*(const T &value, const dense_matrix<T> &matrix) {

        dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
        matrix_tmp = matrix.times(value);

        return std::move(matrix_tmp);
    }
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator/(const dense_matrix<T> &matrix) const {

    dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns);
    matrix_tmp = std::move(divide(matrix));

    return std::move(matrix_tmp);
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator/(const T &value) const {

    dense_matrix<T> matrix_tmp(_rows, _columns);
    matrix_tmp = divide(value);

    return std::move(matrix_tmp);
}

namespace sepolia {

    template<typename T>
    dense_matrix<T> operator/(const T &value, const dense_matrix<T> &matrix) {

        dense_matrix<T> matrix_tmp(matrix._rows, matrix._columns, value);

        matrix_tmp = matrix_tmp.divide(matrix);

        return std::move(matrix_tmp);
    }
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator+=(const dense_matrix<T> &matrix) {

    *this = std::move(plus(matrix));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator+=(const T &value) {

    *this = std::move(plus(value));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator-=(const dense_matrix<T> &matrix) {

    *this = std::move(subtract(matrix));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator-=(const T &value) {

    *this = std::move(subtract(value));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator*=(const dense_matrix<T> &matrix) {

    *this = std::move(times(matrix));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator*=(const T &value) {

    *this = std::move(times(value));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator/=(const dense_matrix<T> &matrix) {

    *this = std::move(divide(matrix));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator/=(const T &value) {

    *this = std::move(divide(value));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator++() {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
const dense_matrix<T> dense_matrix<T>::operator++(int) {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::operator--() {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
const dense_matrix<T> dense_matrix<T>::operator--(int) {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

template<typename T1>
bool dense_matrix<T1>::operator==(const dense_matrix<T1> &matrix) const {

    return equal(matrix);
}

template<typename T>
bool dense_matrix<T>::operator==(const T &value) const {

    return equal(value);
}

namespace sepolia {

    template<typename T>
    bool operator==(const T &value, const dense_matrix<T> &matrix) {

        return matrix.equal(value);
    }
}

template<typename T>
bool dense_matrix<T>::operator!=(const dense_matrix<T> &matrix) const {

    return !equal(matrix);
}

template<typename T>
bool dense_matrix<T>::operator!=(const T &value) const {

    return !equal(value);
}

namespace sepolia {

    template<typename T>
    bool operator!=(const T &value, const dense_matrix<T> &matrix) {

        return !matrix.equal(value);
    }
}