#pragma once

#include <algorithm>
#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const std::vector<T> &vector_std) {

    const auto dimension = vector_std.size();

    deallocate();
    allocate(dimension);

    std::copy(vector_std.begin(), vector_std.end(), _vdsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(std::vector<T> &&vector_std) {

    const auto dimension = vector_std.size();

    this->deallocate();
    this->allocate(dimension);

    std::move(vector_std.begin(), vector_std.end(), _vdsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const vector_dense<T> &vector) {

    set(vector);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const T &value) {

    set(value);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(vector_dense<T> &&vector) noexcept {

    if (this != &vector) {
        deallocate();
        _vdsp = std::move(vector._vdsp);
        _allocated = vector._allocated;
        _dimension = vector._dimension;
        vector._dimension = 0;
        vector._allocated = false;
    }

    return *this;
}

template<typename T>
T &vector_dense<T>::operator()(const uint64_t &index) const {

    return _vdsp.get()[index];
}

template<typename T>
T &vector_dense<T>::operator[](const uint64_t &index) const {

    return _vdsp.get()[index];
}


template<typename T>
vector_dense<T> vector_dense<T>::operator+(const vector_dense<T> &vector) const {

    vector_dense<T> vec_tmp(vector.size());
    vec_tmp = plus(vector);

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator+(const T &value) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = plus(value);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator+(const T &value, const vector_dense<T> &vector) {

        vector_dense<T> vec_tmp(vector.size());
        vec_tmp = vector.plus(value);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-(const vector_dense<T> &vector) const {

    vector_dense<T> vec_tmp(vector.size());
    vec_tmp = subtract(vector);

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-(const T &value) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = subtract(value);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator-(const T &value, const vector_dense<T> &vector) {

        vector_dense<T> vec_tmp(vector.size());
        vec_tmp = vector.subtract(value);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*(const vector_dense<T> &vector) const {

    vector_dense<T> vec_tmp(vector.size());
    vec_tmp = times(vector);

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*(const T &value) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = times(value);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator*(const T &value, const vector_dense<T> &vector) {

        vector_dense<T> vec_tmp(vector.size());
        vec_tmp = vector.times(value);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/(const vector_dense<T> &vector) const {

    vector_dense<T> vec_tmp(vector.size());
    vec_tmp = std::move(divide(vector));

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/(const T &value) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = divide(value);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator/(const T &value, const vector_dense<T> &vector) {

        vector_dense<T> vec_tmp(vector.size(), value);

        vec_tmp = vec_tmp.divide(vector);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator+=(const vector_dense<T> &vector) {

    *this = std::move(plus(vector));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator+=(const T &value) {

    *this = std::move(plus(value));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-=(const vector_dense<T> &vector) {

    *this = std::move(subtract(vector));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-=(const T &value) {

    *this = std::move(subtract(value));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*=(const vector_dense<T> &vector) {

    *this = std::move(times(vector));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*=(const T &value) {

    *this = std::move(times(value));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/=(const vector_dense<T> &vector) {

    *this = std::move(divide(vector));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/=(const T &value) {

    *this = std::move(divide(value));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator++() {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
const vector_dense<T> vector_dense<T>::operator++(int) {

    *this = std::move(plus(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator--() {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

template<typename T>
const vector_dense<T> vector_dense<T>::operator--(int) {

    *this = std::move(subtract(static_cast<T>(1.0)));

    return *this;
}

template<typename T1>
bool vector_dense<T1>::operator==(const vector_dense<T1> &vector) const {

    return equal(vector);
}

template<typename T>
bool vector_dense<T>::operator==(const T &value) const {

    return equal(value);
}

namespace sepolia {

    template<typename T>
    bool operator==(const T &value, const vector_dense<T> &vector) {

        return vector.equal(value);
    }
}

template<typename T>
bool vector_dense<T>::operator!=(const vector_dense<T> &vector) const {

    return !equal(vector);
}

template<typename T>
bool vector_dense<T>::operator!=(const T &value) const {

    return !equal(value);
}

namespace sepolia {

    template<typename T>
    bool operator!=(const T &value, const vector_dense<T> &vector) {

        return !vector.equal(value);
    }
}