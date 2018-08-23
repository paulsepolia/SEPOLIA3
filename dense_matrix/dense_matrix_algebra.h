#pragma once

#include "dense_matrix_declaration.h"
#include "dense_matrix_parameters.h"

using sepolia::dense_matrix;
using sepolia::NT2D;


template<typename T>
void dense_matrix<T>::set(const T &value) {

    const uint64_t dimension = _rows * _columns;
    const auto matrix_out = _mdsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(value)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            matrix_out[i] = static_cast<T>(value);
        }
    }
}

template<typename T>
void dense_matrix<T>::set(const dense_matrix<T> &matrix) {

    if (*this == matrix) {
        return;
    }

    const uint64_t dimension = matrix._rows * matrix._columns;
    deallocate();
    allocate(matrix._rows, matrix._columns);
    const auto matrix_out = _mdsp.get();
    const auto matrix_in = matrix._mdsp.get();
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        private(i)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {
            matrix_out[i] = matrix_in[i];
        }
    }
}

template<typename T>
dense_matrix<T> dense_matrix<T>::plus(const dense_matrix<T> &matrix) const {

    const uint64_t rows = matrix._rows;
    const uint64_t columns = matrix._columns;
    const auto matrix_member = _mdsp.get();
    const auto matrix_in = matrix._mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        private(i)\
        private(j)

    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                matrix_out(i, j) = matrix_member[i * columns + j] +
                                   matrix_in[i * columns + j];
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::plus(const T &elem) const {

    const uint64_t rows = _rows;
    const uint64_t columns = _columns;
    const auto matrix_member = _mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        shared(elem)\
        private(i)\
        private(j)
    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {

                matrix_out(i, j) = matrix_member[i * columns + j] + elem;
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::subtract(const dense_matrix<T> &matrix) const {

    const uint64_t rows = matrix._rows;
    const uint64_t columns = matrix._columns;
    const auto matrix_member = _mdsp.get();
    const auto matrix_in = matrix._mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        private(i)\
        private(j)

    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                matrix_out(i, j) = matrix_member[i * columns + j] -
                                   matrix_in[i * columns + j];
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::subtract(const T &elem) const {

    const uint64_t rows = _rows;
    const uint64_t columns = _columns;
    const auto matrix_member = _mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        shared(elem)\
        private(i)\
        private(j)
    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {

                matrix_out(i, j) = matrix_member[i * columns + j] - elem;
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::times(const dense_matrix<T> &matrix) const {

    const uint64_t rows = matrix._rows;
    const uint64_t columns = matrix._columns;
    const auto matrix_member = _mdsp.get();
    const auto matrix_in = matrix._mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        private(i)\
        private(j)

    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                matrix_out(i, j) = matrix_member[i * columns + j] *
                                   matrix_in[i * columns + j];
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::times(const T &elem) const {

    const uint64_t rows = _rows;
    const uint64_t columns = _columns;
    const auto matrix_member = _mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        shared(elem)\
        private(i)\
        private(j)
    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {

                matrix_out(i, j) = matrix_member[i * columns + j] * elem;
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::divide(const dense_matrix<T> &matrix) const {

    const uint64_t rows = matrix._rows;
    const uint64_t columns = matrix._columns;
    const auto matrix_member = _mdsp.get();
    const auto matrix_in = matrix._mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        private(i)\
        private(j)

    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                matrix_out(i, j) = matrix_member[i * columns + j] /
                                   matrix_in[i * columns + j];
            }
        }
    }

    return matrix_out;
}

template<typename T>
dense_matrix<T> dense_matrix<T>::divide(const T &elem) const {
    const uint64_t rows = _rows;
    const uint64_t columns = _columns;
    const auto matrix_member = _mdsp.get();
    dense_matrix<T> matrix_out(rows, columns);
    uint64_t i = 0;
    uint64_t j = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        shared(matrix_out)\
        shared(elem)\
        private(i)\
        private(j)
    {
#pragma omp for
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {

                matrix_out(i, j) = matrix_member[i * columns + j] / elem;
            }
        }
    }

    return matrix_out;
}

template<typename T>
bool dense_matrix<T>::equal(const dense_matrix<T> &matrix) const {

    if (_rows != matrix._rows) return false;
    if (_columns != matrix._columns) return false;

    bool flg = false;
    const uint64_t dimension = matrix._rows * matrix._columns;
    uint64_t i = 0;

#pragma omp parallel default(none)\
        num_threads(NT2D)\
        private(i)\
        shared(matrix)\
        shared(flg)
    {
#pragma omp for
        for (i = 0; i < dimension; i++) {

            if (!(_mdsp.get()[i] < matrix._mdsp.get()[i]) &&
                !(_mdsp.get()[i] > matrix._mdsp.get()[i])) {
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
bool dense_matrix<T>::equal(const T &val) const {

    if (_rows == 0) return false;
    if (_columns == 0) return false;

    dense_matrix<T> matrix(_rows, _columns, val);

    return equal(matrix);
}
