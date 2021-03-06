#pragma once

#include <algorithm>
#include "dense_container_declaration.h"
#include "../functions_aux/overloaded_operators.h"

using sepolia::dense_container;

template<typename T>
dense_container<T> &dense_container<T>::operator=(const std::vector<T> &vector_std) {

    const auto dimension = vector_std.size();

    deallocate();
    allocate(dimension);

    std::copy(vector_std.begin(), vector_std.end(), _dsp.get());

    return *this;
}

template<typename T>
dense_container<T> &dense_container<T>::operator=(std::vector<T> &&vector_std) {

    const auto dimension = vector_std.size();

    deallocate();
    allocate(dimension);

    std::move(vector_std.begin(), vector_std.end(), _dsp.get());

    return *this;
}

template<typename T>
dense_container<T> &dense_container<T>::operator=(const dense_container<T> &dense_in) {

    allocate(dense_in.rows(), dense_in.columns());
    set(dense_in);

    return *this;
}

template<typename T>
dense_container<T> &dense_container<T>::operator=(const T &value) {

    allocate(rows(), columns());
    set(value);

    return *this;
}

template<typename T>
dense_container<T> &dense_container<T>::operator=(dense_container<T> &&dense_in) noexcept {

    if (this != &dense_in) {
        deallocate();
        _dsp = std::move(dense_in._dsp);
        _allocated = dense_in.allocated();
        _dimension = dense_in.size();
        _rows = dense_in.rows();
        _columns = dense_in.columns();
        dense_in._dimension = 0;
        dense_in._rows = 0;
        dense_in._columns = 0;
        dense_in._allocated = false;
    }

    return *this;
}

template<typename T>
T &dense_container<T>::operator()(const uint64_t &index) const {

    return _dsp.get()[index];
}

template<typename T>
T &dense_container<T>::operator()(const uint64_t &row, const uint64_t &column) const {

    const uint64_t COLS = columns();

    return _dsp.get()[row * COLS + column];
}

template<typename T>
T &dense_container<T>::operator[](const uint64_t &index) const {

    return _dsp.get()[index];
}

template<typename T>
dense_container<T> dense_container<T>::operator+(const dense_container<T> &dense_in) const {

    dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());
    dense_tmp = plus(dense_in);

    return std::move(dense_tmp);
}

template<typename T>
dense_container<T> dense_container<T>::operator+(const T &value) const {

    dense_container<T> dense_tmp(rows(), columns());
    dense_tmp = plus(value);

    return std::move(dense_tmp);
}

namespace sepolia {

    template<typename T>
    dense_container<T> operator+(const T &value, const dense_container<T> &dense_in) {

        dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());
        dense_tmp = dense_in.plus(value);

        return std::move(dense_tmp);
    }
}

template<typename T>
dense_container<T> dense_container<T>::operator-(const dense_container<T> &dense_in) const {

    dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());
    dense_tmp = subtract(dense_in);

    return std::move(dense_tmp);
}

template<typename T>
dense_container<T> dense_container<T>::operator-(const T &value) const {

    dense_container<T> dense_tmp(rows(), columns());
    dense_tmp = subtract(value);

    return std::move(dense_tmp);
}

namespace sepolia {

    template<typename T>
    dense_container<T> operator-(const T &value, const dense_container<T> &dense_in) {

        dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());

        for (uint64_t i = 0; i != dense_in.size(); i++) {
            dense_tmp[i] = value - dense_in[i];
        }

        return std::move(dense_tmp);
    }
}

template<typename T>
dense_container<T> dense_container<T>::operator*(const dense_container<T> &dense_in) const {

    dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());
    dense_tmp = times(dense_in);

    return std::move(dense_tmp);
}

template<typename T>
dense_container<T> dense_container<T>::operator*(const T &value) const {

    dense_container<T> dense_tmp(rows(), columns());
    dense_tmp = times(value);

    return std::move(dense_tmp);
}

namespace sepolia {

    template<typename T>
    dense_container<T> operator*(const T &value, const dense_container<T> &dense_in) {

        dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());
        dense_tmp = dense_in.times(value);

        return std::move(dense_tmp);
    }
}

template<typename T>
dense_container<T> dense_container<T>::operator/(const dense_container<T> &dense_in) const {

    dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());
    dense_tmp = std::move(divide(dense_in));

    return std::move(dense_tmp);
}

template<typename T>
dense_container<T> dense_container<T>::operator/(const T &value) const {

    dense_container<T> dense_tmp(rows(), columns());
    dense_tmp = divide(value);

    return std::move(dense_tmp);
}

namespace sepolia {

    template<typename T>
    dense_container<T> operator/(const T &value, const dense_container<T> &dense_in) {

        dense_container<T> dense_tmp(dense_in.rows(), dense_in.columns());

        for (uint64_t i = 0; i != dense_in.size(); i++) {
            dense_tmp[i] = value / dense_in[i];
        }

        return std::move(dense_tmp);
    }
}

template<typename T>
dense_container<T> dense_container<T>::operator+=(const dense_container<T> &dense_in) {

    *this = std::move(plus(dense_in));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator+=(const T &value) {

    *this = std::move(plus(value));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator-=(const dense_container<T> &dense_in) {

    *this = std::move(subtract(dense_in));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator-=(const T &value) {

    *this = std::move(subtract(value));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator*=(const dense_container<T> &dense_in) {

    *this = std::move(times(dense_in));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator*=(const T &value) {

    *this = std::move(times(value));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator/=(const dense_container<T> &dense_in) {

    *this = std::move(divide(dense_in));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator/=(const T &value) {

    *this = std::move(divide(value));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator++() {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
const dense_container<T> dense_container<T>::operator++(int) {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
dense_container<T> dense_container<T>::operator--() {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
const dense_container<T> dense_container<T>::operator--(int) {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

template<typename T1>
bool dense_container<T1>::operator==(const dense_container<T1> &dense_in) const {

    return equal(dense_in);
}

template<typename T>
bool dense_container<T>::operator==(const T &value) const {

    return equal(value);
}

namespace sepolia {

    template<typename T>
    bool operator==(const T &value, const dense_container<T> &dense_in) {

        return dense_in.equal(value);
    }
}

template<typename T>
bool dense_container<T>::operator!=(const dense_container<T> &dense_in) const {

    return !equal(dense_in);
}

template<typename T>
bool dense_container<T>::operator!=(const T &value) const {

    return !equal(value);
}

namespace sepolia {

    template<typename T>
    bool operator!=(const T &value, const dense_container<T> &dense_in) {

        return !dense_in.equal(value);
    }
}