#include "../sepolia/sepolia.h"

using namespace sepolia;

namespace sepolia {

    // outplace transpose float

    dense_matrix<float> Transpose(const dense_matrix<float> &matrix_in) {

        const auto rows = matrix_in.rows();
        const auto columns = matrix_in.columns();

        dense_matrix<float> dense_matrix_tmp(columns, rows);

        mkl_somatcopy('R',
                      'T',
                      rows,
                      columns,
                      ONE_FLT,
                      &matrix_in[0],
                      columns,
                      &dense_matrix_tmp[0],
                      rows);

        return dense_matrix_tmp;
    }

    // outplace transpose double

    dense_matrix<double> Transpose(const dense_matrix<double> &matrix_in) {

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

//    // outplace transpose complex float
//
//    dense_matrix<MKL_Complex8>
//    Transpose(const dense_matrix<MKL_Complex8> &matrix_in) {
//
//        const auto rows = matrix_in.rows();
//        const auto columns = matrix_in.columns();
//
//        dense_matrix<MKL_Complex8> dense_matrix_tmp(columns, rows);
//
//        mkl_comatcopy('R',
//                      'T',
//                      rows,
//                      columns,
//                      MKL_ONE_FLT_C,
//                      &matrix_in[0],
//                      columns,
//                      &dense_matrix_tmp[0],
//                      rows);
//
//        return dense_matrix_tmp;
//    }

//    // outplace transpose complex double
//
//    dense_matrix<MKL_Complex16>
//    Transpose(const dense_matrix<MKL_Complex16> &matrix_in) {
//
//        const auto rows = matrix_in.rows();
//        const auto columns = matrix_in.columns();
//
//        dense_matrix<MKL_Complex16> dense_matrix_tmp(columns, rows);
//
//        mkl_zomatcopy('R',
//                      'T',
//                      rows,
//                      columns,
//                      MKL_ONE_DBL_C,
//                      &matrix_in[0],
//                      columns,
//                      &dense_matrix_tmp[0],
//                      rows);
//
//        return dense_matrix_tmp;
//    }

    // inplace transpose float

    void Transpose(dense_matrix<float> &matrix_in_out) {

        check_square_matrix(matrix_in_out);

        const auto rows = matrix_in_out.rows();
        const auto columns = matrix_in_out.columns();

        mkl_simatcopy('R',
                      'T',
                      rows,
                      columns,
                      ONE_FLT,
                      &matrix_in_out[0],
                      rows,
                      columns);
    }

    // inplace transpose double

    void Transpose(dense_matrix<double> &matrix_in_out) {

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

//    // inplace transpose complex float
//
//    void Transpose(dense_matrix<MKL_Complex8> &matrix_in_out) {
//
//        check_square_matrix(matrix_in_out);
//
//        const auto rows = matrix_in_out.rows();
//        const auto columns = matrix_in_out.columns();
//
//        mkl_cimatcopy('R',
//                      'T',
//                      rows,
//                      columns,
//                      MKL_ONE_FLT_C,
//                      &matrix_in_out[0],
//                      rows,
//                      columns);
//    }
//
//    // inplace transpose complex double
//
//    void Transpose(dense_matrix<MKL_Complex16> &matrix_in_out) {
//
//        check_square_matrix(matrix_in_out);
//
//        const auto rows = matrix_in_out.rows();
//        const auto columns = matrix_in_out.columns();
//
//        mkl_zimatcopy('R',
//                      'T',
//                      rows,
//                      columns,
//                      MKL_ONE_DBL_C,
//                      &matrix_in_out[0],
//                      rows,
//                      columns);
//    }
}