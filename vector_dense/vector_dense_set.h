#pragma once

#include "vector_dense_declaration.h"

namespace sepolia {
    const uint32_t NT1D = 2;

}
// set vector to an element

template<typename T>
void sepolia::vector_dense<T>::set(const T &value) {

    const uint64_t dimension(_dimension);
    const auto tmp = _vdsp.get();
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(sepolia::NT1D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            tmp[i] = static_cast<T>(value);
        }
    }
}

// set vector to another vector

template<typename T>
void sepolia::vector_dense<T>::set(const sepolia::vector_dense<T> &vec) {

    const uint64_t dimension(vec._dimension);
    deallocate();
    allocate(dimension);
    const auto tmp1 = _vdsp.get();
    const auto tmp2 = vec._vdsp.get();
    uint64_t i(0);

#pragma omp parallel default(none)\
        num_threads(sepolia::NT1D)\
        shared(vec)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            tmp1[i] = tmp2[i];
        }
    }
}
