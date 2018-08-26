#pragma once

#include <cstdint>
#include "../parameters/parameters.h"
#include "../dense_vector/dense_vector.h"
#include "../dense_matrix/dense_matrix.h"

using sepolia::dense_vector;
using sepolia::dense_matrix;

namespace sepolia {

    dense_matrix<double> built_a_matrix(const uint64_t &rows,
                                        const uint64_t &columns);

    void print_eigenvalues(const dense_vector<double> &eigenvalues,
                           uint64_t eigenvalue_start,
                           uint64_t eigenvalue_end);


    void print_eigenvectors(const dense_matrix<double> &eigenvectors,
                            uint64_t eigenvector_start,
                            uint64_t eigenvector_end);

    void print_error_and_exit(const std::string &message);


    template<typename T>
    void check_compatibility_for_dot(const dense_matrix<T> &matrix_a,
                                     const dense_matrix<T> &matrix_b) {

        if (matrix_a.columns() != matrix_b.rows()) {
            print_error_and_exit(sepolia::E_MAT_MAT_COLS_ROWS_NE);
        }
    }

    template<typename T>
    void check_square_matrix(const dense_matrix<T> &matrix) {

        if (matrix.columns() != matrix.rows()) {
            print_error_and_exit(sepolia::E_MAT_SQUARE_NOT);
        }
    }
}