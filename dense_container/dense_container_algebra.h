#pragma once

#include "dense_container_declaration.h"
#include "dense_container_parameters.h"

using sepolia::dense_container;
using sepolia::NT1D;

template<typename T>
void dense_container<T>::set(const T &value) {

    const uint64_t dimension = _dimension;

    if(dimension == 0) {
        _allocated = false;
        return;
    }

    const auto dense_out = _dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out[i] = static_cast<T>(value);
        }
    }

    _allocated = true;
}

template<typename T>
void dense_container<T>::set(const dense_container<T> &dense_in) {

    if (*this == dense_in) {
        return;
    }

    const uint64_t dimension = dense_in._dimension;

    if(dimension == 0) {
        _allocated = false;
        return;
    }

    deallocate();
    allocate(dimension);
    const auto dense_out = _dsp.get();
    const auto dense_in_tmp = dense_in._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out[i] = dense_in_tmp[i];
        }
    }

    _allocated = true;
}

template<typename T>
dense_container<T> dense_container<T>::plus(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in._dimension;
    const auto matrix_member_p = _dsp.get();
    const auto dense_in_p = dense_in._dsp.get();
    dense_container<T> dense_out(dimension);
    const auto dense_out_p = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out_tmp)\
        private(i)

    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out_p[i] = matrix_member_p[i] + dense_in_p[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::plus(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto matrix_member = _dsp.get();
    dense_container<T> dense_out(_dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out._dsp.get()[i] = matrix_member[i] + elem;
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::subtract(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in._dimension;
    const auto matrix_member_p = _dsp.get();
    const auto dense_in_p = dense_in._dsp.get();
    dense_container<T> dense_out(dimension);
    const auto dense_out_p = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out_tmp)\
        private(i)

    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out_p[i] = matrix_member_p[i] - dense_in_p[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::subtract(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto matrix_member = _dsp.get();
    dense_container<T> dense_out(_dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out._dsp.get()[i] = matrix_member[i] - elem;
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::times(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in._dimension;
    const auto matrix_member_p = _dsp.get();
    const auto dense_in_p = dense_in._dsp.get();
    dense_container<T> dense_out(dimension);
    const auto dense_out_p = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out_tmp)\
        private(i)

    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out_p[i] = matrix_member_p[i] - dense_in_p[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::times(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto matrix_member = _dsp.get();
    dense_container<T> dense_out(_dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out._dsp.get()[i] = matrix_member[i] * elem;
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::divide(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in._dimension;
    const auto matrix_member_p = _dsp.get();
    const auto dense_in_p = dense_in._dsp.get();
    dense_container<T> dense_out(dimension);
    const auto dense_out_p = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out_tmp)\
        private(i)

    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out_p[i] = matrix_member_p[i] / dense_in_p[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::divide(const T &elem) const {

    const uint64_t dimension = _dimension;
    const auto matrix_member = _dsp.get();
    dense_container<T> dense_out(_dimension);
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out._dsp.get()[i] = matrix_member[i] / elem;
        }
    }

    return dense_out;
}

template<typename T>
bool dense_container<T>::equal(const dense_container<T> &dense_in) const {

    // dummy implementation
    return false;
}

template<typename T>
bool dense_container<T>::equal(const T &val) const {

    if (_dimension == 0) return false;

    dense_container<T> dense_tmp(_dimension, val);

    return equal(dense_tmp);
}
