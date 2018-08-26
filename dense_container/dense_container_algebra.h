#pragma once

#include <iostream>
#include <complex>
#include "dense_container_declaration.h"
#include "../parameters/parameters.h"

using sepolia::dense_container;
using sepolia::NT1D;

template<typename T>
uint64_t dense_container<T>::rows() const {

    return _rows;
}

template<typename T>
uint64_t dense_container<T>::columns() const {

    return _columns;
}

template<typename T>
void dense_container<T>::set(const T &value) {

    const uint64_t dimension = _dimension;
    const auto sp_dense_out = _dsp.get();

    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = static_cast<T>(value);
        }
    }
}

template<typename T>
void dense_container<T>::set(const dense_container<T> &dense_in) {

    const uint64_t dimension = dense_in.size();

    if (dimension == 0) {
        deallocate();
        return;
    }

    const auto sp_dense_out = _dsp.get();
    const auto sp_dense_in = dense_in._dsp.get();
    _rows = dense_in.rows();
    _columns = dense_in.columns();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_in[i];
        }
    }
}

template<typename T>
dense_container<T> dense_container<T>::plus(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in.size();
    const auto sp_dense_member = _dsp.get();
    const auto sp_dense_in = dense_in._dsp.get();
    dense_container<T> dense_out(dense_in.rows(), dense_in.columns());
    dense_out._rows = dense_in.rows();
    dense_out._columns = dense_in.columns();
    const auto sp_dense_out = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_member[i] + sp_dense_in[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::plus(const T &elem) const {

    const uint64_t dimension = size();
    const auto sp_dense_member = _dsp.get();
    dense_container<T> dense_out(rows(), columns());
    const auto sp_dense_out = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_member[i] + elem;
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::subtract(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in.size();
    const auto sp_dense_member = _dsp.get();
    const auto sp_dense_in = dense_in._dsp.get();
    dense_container<T> dense_out(dense_in.rows(), dense_in.columns());
    dense_out._rows = dense_in.rows();
    dense_out._columns = dense_in.columns();
    const auto sp_dense_out = dense_out._dsp.get();
    dense_out._rows = dense_in.rows();
    dense_out._columns = dense_in.columns();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_member[i] - sp_dense_in[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::subtract(const T &elem) const {

    const uint64_t dimension = size();
    const auto dense_member = _dsp.get();
    dense_container<T> dense_out(rows(), columns());
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(dense_out)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            dense_out._dsp.get()[i] = dense_member[i] - elem;
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::times(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in.size();
    const auto sp_dense_member = _dsp.get();
    const auto sp_dense_in = dense_in._dsp.get();
    dense_container<T> dense_out(dense_in.rows(), dense_in.columns());
    dense_out._rows = dense_in.rows();
    dense_out._columns = dense_in.columns();
    const auto sp_dense_out = dense_out._dsp.get();
    dense_out._rows = dense_in.rows();
    dense_out._columns = dense_in.columns();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_member[i] * sp_dense_in[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::times(const T &elem) const {

    const uint64_t dimension = size();
    const auto dense_member = _dsp.get();
    dense_container<T> dense_out(rows(), columns());
    const auto sp_dense_out = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = dense_member[i] * elem;
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::divide(const dense_container<T> &dense_in) const {

    const uint64_t dimension = dense_in.size();
    const auto sp_dense_member = _dsp.get();
    const auto sp_dense_in = dense_in._dsp.get();
    dense_container<T> dense_out(dense_in.rows(), dense_in.columns());
    dense_out._rows = dense_in.rows();
    dense_out._columns = dense_in.columns();
    const auto sp_dense_out = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_member[i] / sp_dense_in[i];
        }
    }

    return dense_out;
}

template<typename T>
dense_container<T> dense_container<T>::divide(const T &elem) const {

    const uint64_t dimension = size();
    const auto sp_dense_member = _dsp.get();
    dense_container<T> dense_out(rows(), columns());
    const auto sp_dense_out = dense_out._dsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT1D)\
        shared(elem)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            sp_dense_out[i] = sp_dense_member[i] / elem;
        }
    }

    return dense_out;
}

template<typename T>
bool dense_container<T>::equal(const dense_container<T> &dense_in) const {

    if (!dense_in.allocated() || !allocated()) return false;
    if (dense_in.size() != size()) return false;
    if (dense_in.rows() != rows()) return false;
    if (dense_in.columns() != columns()) return false;

    bool flg = std::equal(this->begin(), this->end(), dense_in.begin());

    return flg;
}

template<typename T>
bool dense_container<T>::equal(const T &val) const {

    if (size() == 0)
        return false;

    if (deallocated())
        return false;

    dense_container<T> dense_tmp(rows(), columns());
    dense_tmp.set(val);

    return equal(dense_tmp);
}
