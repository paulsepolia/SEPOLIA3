#pragma once

#include "vector_dense_declaration.h"
#include "vector_dense_parameters.h"

template<typename T>
void sepolia::vector_dense<T>::set(const T &value) {

    const uint64_t dimension = _dimension;
    const auto vector_out = _vdsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(sepolia::NT1D)\
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
void sepolia::vector_dense<T>::set(const sepolia::vector_dense<T> &vec) {

    const uint64_t dimension = vec._dimension;
    deallocate();
    allocate(dimension);
    const auto vector_out = _vdsp.get();
    const auto vector_in = vec._vdsp.get();
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(sepolia::NT1D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            vector_out[i] = vector_in[i];
        }
    }
}
