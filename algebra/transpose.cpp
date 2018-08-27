#include "../sepolia/sepolia.h"

using namespace sepolia;

namespace sepolia {

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
}