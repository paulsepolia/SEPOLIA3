#pragma once

#include "vector_dense_declaration.h"

using sepolia::vector_dense;

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const std::vector<T> &vec_std) {

    const auto dimension = vec_std.size();

    deallocate();
    allocate(dimension);

    std::copy(vec_std.begin(), vec_std.end(), _vdsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(std::vector<T> &&vec_std) {

    const auto dimension = vec_std.size();

    this->deallocate();
    this->allocate(dimension);

    std::move(vec_std.begin(), vec_std.end(), _vdsp.get());

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const vector_dense<T> &vec) {

    set(vec);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(const T &val) {

    set(val);

    return *this;
}

template<typename T>
vector_dense<T> &vector_dense<T>::operator=(vector_dense<T> &&vec) noexcept {

    if (this != &vec) {
        deallocate();
        _vdsp = std::move(vec._vdsp);
        _allocated = vec._allocated;
        _dimension = vec._dimension;
        vec._dimension = 0;
        vec._allocated = false;
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
vector_dense<T> vector_dense<T>::operator+(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.size());
    vec_tmp = plus(vec);

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator+(const T &val) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = plus(val);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator+(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.size());
        vec_tmp = vec.plus(val);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.size());
    vec_tmp = subtract(vec);

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-(const T &val) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = subtract(val);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator-(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.size());
        vec_tmp = vec.subtract(val);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.size());
    vec_tmp = times(vec);

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*(const T &val) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = times(val);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator*(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.size());
        vec_tmp = vec.times(val);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/(const vector_dense<T> &vec) const {

    vector_dense<T> vec_tmp(vec.size());
    vec_tmp = std::move(divide(vec));

    return std::move(vec_tmp);
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/(const T &val) const {

    vector_dense<T> vec_tmp(size());
    vec_tmp = divide(val);

    return std::move(vec_tmp);
}

namespace sepolia {

    template<typename T>
    vector_dense<T> operator/(const T &val, const vector_dense<T> &vec) {

        vector_dense<T> vec_tmp(vec.size(), val);

        vec_tmp = vec_tmp.divide(vec);

        return std::move(vec_tmp);
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::operator+=(const vector_dense<T> &vec) {

    *this = std::move(plus(vec));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator+=(const T &val) {

    *this = std::move(plus(val));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-=(const vector_dense<T> &vec) {

    *this = std::move(subtract(vec));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator-=(const T &val) {

    *this = std::move(subtract(val));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*=(const vector_dense<T> &vec) {

    *this = std::move(times(vec));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator*=(const T &val) {

    *this = std::move(times(val));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/=(const vector_dense<T> &vec) {

    *this = std::move(divide(vec));

    return *this;
}

template<typename T>
vector_dense<T> vector_dense<T>::operator/=(const T &val) {

    *this = std::move(divide(val));

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
bool vector_dense<T1>::operator==(const vector_dense<T1> &vec) const {

    return equal(vec);
}

template<typename T>
bool vector_dense<T>::operator==(const T &val) const {
    return equal(val);
}

template<typename T>
bool vector_dense<T>::operator!=(const vector_dense<T> &vec) const {
    return !equal(vec);
}

template<typename T>
bool vector_dense<T>::operator!=(const T &val) const {
    return !equal(val);
}
