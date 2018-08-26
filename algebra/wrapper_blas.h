#pragma once

#include "../dense_matrix/dense_matrix.h"
#include "../aux_functions/aux_functions.h"
#include <cblas.h>

using sepolia::dense_matrix;
using sepolia::BLAS_INT;
using sepolia::ONE_DBL;
using sepolia::ZERO_DBL;

namespace sepolia {

    dense_matrix<double> Dot(const dense_matrix<double> &matrix_a,
                             const dense_matrix<double> &matrix_b) {

        check_compatibility_for_dot(matrix_a, matrix_b);

        const auto ROWS_A = matrix_a.rows();
        const auto COLS_A = matrix_a.columns();
        const auto COLS_B = matrix_b.columns();

        dense_matrix<double> matrix_tmp(ROWS_A, COLS_B);

        cblas_dgemm(CblasRowMajor,                  //  1 --> CblasRowMajor, CblasColMajor
                    CblasNoTrans,                   //  2 --> CblasNoTrans, CblasTrans
                    CblasNoTrans,                   //  3 --> same as above
                    static_cast<BLAS_INT>(ROWS_A),  //  4 --> m
                    static_cast<BLAS_INT>(COLS_B),  //  5 --> n
                    static_cast<BLAS_INT>(COLS_A),  //  6 --> k
                    ONE_DBL,                        //  7 --> alpha
                    &matrix_a[0],                   //  8 --> *a
                    static_cast<BLAS_INT>(COLS_A),  //  9 --> lda
                    &matrix_b[0],                   // 10 --> *b
                    static_cast<BLAS_INT>(COLS_B),  // 11 --> ldb
                    ZERO_DBL,                       // 12 --> beta
                    &matrix_tmp[0],                 // 13 --> *c
                    static_cast<BLAS_INT>(COLS_B)); // 14 --> ldc

        return matrix_tmp;
    }


    dense_matrix<std::complex<double>> Dot(const dense_matrix<std::complex<double>> &matrix_a,
                                           const dense_matrix<std::complex<double>> &matrix_b) {

        check_compatibility_for_dot(matrix_a, matrix_b);

        const auto ROWS_A = matrix_a.rows();
        const auto COLS_A = matrix_a.columns();
        const auto COLS_B = matrix_b.columns();

        dense_matrix<std::complex<double>> matrix_tmp(ROWS_A, COLS_B);


        cblas_zgemm(CblasRowMajor,                  //  1 --> CblasRowMajor, CblasColMajor
                    CblasNoTrans,                   //  2 --> CblasNoTrans, CblasTrans
                    CblasNoTrans,                   //  3 --> same as above
                    static_cast<BLAS_INT>(ROWS_A),  //  4 --> m
                    static_cast<BLAS_INT>(COLS_B),  //  5 --> n
                    static_cast<BLAS_INT>(COLS_A),  //  6 --> k
                    &ONE_CMPLX,                     //  7 --> alpha
                    &matrix_a[0],                   //  8 --> *a
                    static_cast<BLAS_INT>(COLS_A),  //  9 --> lda
                    &matrix_b[0],                   // 10 --> *b
                    static_cast<BLAS_INT>(COLS_B),  // 11 --> ldb
                    &ZERO_CMPLX,                    // 12 --> beta
                    &matrix_tmp[0],                 // 13 --> *c
                    static_cast<BLAS_INT>(COLS_B)); // 14 --> ldc

        return matrix_tmp;
    }
}