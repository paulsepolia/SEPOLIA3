#pragma once

#include "../dense_matrix/dense_matrix.h"
#include "../aux_functions/aux_functions.h"
#include "../headers/sepolia_headers.h"

using sepolia::dense_matrix;
using sepolia::BLAS_INT;
using sepolia::ONE_DBL;
using sepolia::ZERO_DBL;

namespace sepolia {

    //=============//
    // dot product //
    //=============//

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

    //===========//
    // transpose //
    //===========//

    dense_matrix<double> Transpose(const dense_matrix<double> & matrix_in) {

            const auto rows = matrix_in.rows();
            const auto columns = matrix_in.columns();

            dense_matrix<double> dense_matrix_tmp(columns, rows);

            mkl_domatcopy('R',
                          'T',
                          rows,
                          columns,
                          ONE_DBL,
                          &matrix_in[0],
                          columns,
                          &dense_matrix_tmp[0],
                          rows);

            return dense_matrix_tmp;
    }

    void Transpose(dense_matrix<double> & matrix_in_out) {

        check_square_matrix(matrix_in_out);

        const auto rows = matrix_in_out.rows();
        const auto columns = matrix_in_out.columns();

        mkl_dimatcopy('R',
                      'T',
                      rows,
                      columns,
                      ONE_DBL,
                      &matrix_in_out[0],
                      rows,
                      columns);
    }
}