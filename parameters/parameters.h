#pragma once

#include <string>
#include <complex>

namespace sepolia {

    // OPENMP

    const uint32_t NT1D = 6;

    // LAPACK

    const std::string DSYEVD_LAPACKE = "dsyevd_lapacke";
    const std::string DSYEV_LAPACKE = "dsyev_lapacke";

    // Error messages

    // arguments

    const std::string E_ARG_LESS_TOT_ELEMS =
            "ERROR:ARG:THE ARGUMENT MUST BE LESS THAN THE TOTAL NUMBER OF ELEMENTS";

    const std::string E_ARG_POS =
            "ERROR:ARG:THE ARGUMENT MUST BE POSITIVE";

    // dense vector

    const std::string E_VEC_ALLOC_NOT =
            "ERROR:DENSE:VEC:NOT ALLOCATED";

    const std::string E_VEC_LIB_TYPE_NOT =
            "ERROR:DENSE:VECTOR:NOT VALID LIBRARY TYPE";

    const std::string E_VEC_MAT_CONFORM_NOT =
            "ERROR:DENSE:VECTOR:MATRIX:THEY DO NOT CONFORM";

    const std::string E_VEC_VEC_CONFORM_NOT =
            "ERROR:DENSE:VEC:lhs VECTOR DO NOT CONFORM WITH rhs VECTOR";

    // dense matrix

    const std::string E_MAT_ALLOC_NOT =
            "ERROR:DENSE:MATRIX:NOT ALLOCATED";

    const std::string E_MAT_HERMITIAN_NOT =
            "ERROR:DENSE:MATRIX:NOT HERMITIAN";

    const std::string E_MAT_LIB_TYPE_NOT =
            "ERROR:DENSE:MATRIX:NOT VALID LIBRARY TYPE";

    const std::string E_MAT_MAT_COLS_NE =
            "ERROR:DENSE:MATRIX:NOT EQUAL NUMBER OF COLUMNS";

    const std::string E_MAT_MAT_COLS_ROWS_NE =
            "ERROR:DENSE:MATRIX:lhs NUMBER OF COLS NOT EQUAL rhs NUMBER OF ROWS";

    const std::string E_MAT_MAT_CONFORM_NOT =
            "ERROR:DENSE:MATRIX:lhs MATRIX DO NOT CONFORM WITH rhs MATRIX";

    const std::string E_MAT_MAT_DIAG_TYPE_NOT =
            "ERROR:DENSE:MATRIX:NOT VALID DIAGONALIZATION METHOD";

    const std::string E_MAT_MAT_DOT_TYPE_NOT =
            "ERROR:DENSE:MATRIX:NOT VALID DOT-PRODUCT TYPE";

    const std::string E_MAT_MAT_ROWS_NE =
            "ERROR:DENSE:MATRIX:NOT EQUAL NUMBER OF ROWS";

    const std::string E_MAT_MAT_ROWS_COLS_NE =
            "ERROR:DENSE:MATRIX:lhs NUMBER OF ROWS NOT EQUAL rhs NUMBER OF COLS";

    const std::string E_MAT_SQUARE_NOT =
            "ERROR:DENSE:MATRIX:NOT SQUARE";

    const std::string E_MAT_SYMMETRIC_NOT =
            "ERROR:DENSE:MATRIX:NOT SYMMETRIC";

    const std::string E_MAT_VEC_COL_TYPE_NOT =
            "ERROR:DENSE:MATRIX:MATRIX IN NOT VECTOR-COLUMN-LIKE";

    const std::string E_MAT_VEC_CONFORM_NOT =
            "ERROR:DENSE:MATRIX:VECTOR:THEY DO NOT CONFORM";

    const std::string E_MAT_VEC_DOT_TYPE_NOT =
            "ERROR:DENSE:MATRIX:VECTOR:NOT VALID DOT-PRODUCT TYPE";

    const std::string E_MAT_VEC_ROW_TYPE_NOT =
            "ERROR:DENSE:MATRIX:MATRIX IN NOT VECTOR-ROW-LIKE";

    // double

    const double ZERO_DBL = static_cast<double>(0.0);
    const double ONE_DBL = static_cast<double>(1.0);
    const long double ZERO_DBL_MAX = static_cast<long double>(0.0L);
    const long double ONE_DBL_MAX = static_cast<long double>(1.0L);

    // complex

    const std::complex<double> ZERO_CMPLX = {0.0, 0.0};
    const std::complex<double> ONE_CMPLX = {1.0, 0.0};
    const std::complex<long double> ZERO_CMPLX_MAX = {0.0L, 0.0L};
    const std::complex<long double> ONE_CMPLX_MAX = {1.0L, 0.0L};

    typedef int BLAS_INT;
    const std::string BLAS_LIB = "BLAS";
}

