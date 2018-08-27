#include "../sepolia/sepolia.h"

using namespace sepolia;

namespace sepolia {

    // float

    dense_matrix<float> Dot(const dense_matrix<float> &matrix_a,
                            const dense_matrix<float> &matrix_b) {

        check_compatibility_for_dot(matrix_a, matrix_b);

        const auto ROWS_A = matrix_a.rows();
        const auto COLS_A = matrix_a.columns();
        const auto COLS_B = matrix_b.columns();

        dense_matrix<float> matrix_tmp(ROWS_A, COLS_B);

        cblas_sgemm(CblasRowMajor,                  //  1 --> CblasRowMajor, CblasColMajor
                    CblasNoTrans,                   //  2 --> CblasNoTrans, CblasTrans
                    CblasNoTrans,                   //  3 --> same as above
                    static_cast<BLAS_INT>(ROWS_A),  //  4 --> m
                    static_cast<BLAS_INT>(COLS_B),  //  5 --> n
                    static_cast<BLAS_INT>(COLS_A),  //  6 --> k
                    ONE_FLT,                        //  7 --> alpha
                    &matrix_a[0],                   //  8 --> *a
                    static_cast<BLAS_INT>(COLS_A),  //  9 --> lda
                    &matrix_b[0],                   // 10 --> *b
                    static_cast<BLAS_INT>(COLS_B),  // 11 --> ldb
                    ZERO_FLT,                       // 12 --> beta
                    &matrix_tmp[0],                 // 13 --> *c
                    static_cast<BLAS_INT>(COLS_B)); // 14 --> ldc

        return matrix_tmp;
    }

    // double

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

    // complex float

    dense_matrix<std::complex<float>> Dot(const dense_matrix<std::complex<float>> &matrix_a,
                                          const dense_matrix<std::complex<float>> &matrix_b) {

        check_compatibility_for_dot(matrix_a, matrix_b);

        const auto ROWS_A = matrix_a.rows();
        const auto COLS_A = matrix_a.columns();
        const auto COLS_B = matrix_b.columns();

        dense_matrix<std::complex<float>> matrix_tmp(ROWS_A, COLS_B);

        cblas_cgemm(CblasRowMajor,                  //  1 --> CblasRowMajor, CblasColMajor
                    CblasNoTrans,                   //  2 --> CblasNoTrans, CblasTrans
                    CblasNoTrans,                   //  3 --> same as above
                    static_cast<BLAS_INT>(ROWS_A),  //  4 --> m
                    static_cast<BLAS_INT>(COLS_B),  //  5 --> n
                    static_cast<BLAS_INT>(COLS_A),  //  6 --> k
                    &ONE_FLT_C,                     //  7 --> alpha
                    &matrix_a[0],                   //  8 --> *a
                    static_cast<BLAS_INT>(COLS_A),  //  9 --> lda
                    &matrix_b[0],                   // 10 --> *b
                    static_cast<BLAS_INT>(COLS_B),  // 11 --> ldb
                    &ZERO_FLT_C,                    // 12 --> beta
                    &matrix_tmp[0],                 // 13 --> *c
                    static_cast<BLAS_INT>(COLS_B)); // 14 --> ldc

        return matrix_tmp;
    }

    // complex double

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
                    &ONE_DBL_C,                     //  7 --> alpha
                    &matrix_a[0],                   //  8 --> *a
                    static_cast<BLAS_INT>(COLS_A),  //  9 --> lda
                    &matrix_b[0],                   // 10 --> *b
                    static_cast<BLAS_INT>(COLS_B),  // 11 --> ldb
                    &ZERO_DBL_C,                    // 12 --> beta
                    &matrix_tmp[0],                 // 13 --> *c
                    static_cast<BLAS_INT>(COLS_B)); // 14 --> ldc

        return matrix_tmp;
    }
}