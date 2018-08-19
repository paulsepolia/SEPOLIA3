#pragma once

#include "vector_dense_declaration.h"
#include "vector_dense_parameters.h"

using sepolia::vector_dense;
using sepolia::NT1D;

template<typename T>
void vector_dense<T>::set(const T &value) {

    const uint64_t dimension = _dimension;
    const auto vector_out = _vdsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = static_cast<T>(value);
        }
    }
}

template<typename T>
void vector_dense<T>::set(const vector_dense<T> &vector) {

    if(*this == vector) {
        return;
    }

    const uint64_t dimension = vector._dimension;
    deallocate();
    allocate(dimension);
    const auto vector_out = _vdsp.get();
    const auto vector_in = vector._vdsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_in[i];
        }
    }
}

template<typename T>
vector_dense<T> vector_dense<T>::plus(const vector_dense<T> &vector) const {

    const uint64_t dimension = vector._dimension;
    const auto vector_member = _vdsp.get();
    const auto vector_in = vector._vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] + vector_in[i];
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::plus(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto vector_member = _vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] + elem;
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::subtract(const vector_dense<T> &vector) const {

    const uint64_t dimension = vector._dimension;
    const auto vector_member = _vdsp.get();
    const auto vector_in = vector._vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] - vector_in[i];
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::subtract(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto vector_member = _vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] - elem;
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::times(const vector_dense<T> &vector) const {

    const uint64_t dimension = vector._dimension;
    const auto vector_member = _vdsp.get();
    const auto vector_in = vector._vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] * vector_in[i];
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::times(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto vector_member = _vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] * elem;
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::divide(const vector_dense<T> &vector) const {

    const uint64_t dimension = vector._dimension;
    const auto vector_member = _vdsp.get();
    const auto vector_in = vector._vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] / vector_in[i];
        }
    }

    return vector_out;
}

template<typename T>
vector_dense<T> vector_dense<T>::divide(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto vector_member = _vdsp.get();
    vector_dense<T> vector_out(dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(vector_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_member[i] / elem;
        }
    }

    return vector_out;
}

template<typename T>
bool vector_dense<T>::equal(const vector_dense<T> &vector) const {

    if (_dimension != vector._dimension) return false;

    bool flg = false;
    const uint64_t dimension = _dimension;
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)\
        shared(vector)\
        shared(flg)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {

            if (!(_vdsp.get()[i] < vector._vdsp.get()[i]) &&
                !(_vdsp.get()[i] > vector._vdsp.get()[i])) {
#pragma omp critical
                flg = true;
#pragma omp cancel for
            }
#pragma omp cancellation point for
        }
    }

    return flg;
}

template<typename T>
bool vector_dense<T>::equal(const T &value) const {

    if (_dimension == 0) return false;

    vector_dense<T> vec_tmp(_dimension, value);

    return equal(vec_tmp);
}
