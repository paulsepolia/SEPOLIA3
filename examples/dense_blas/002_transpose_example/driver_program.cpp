#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/dense_matrix.h"
#include "../../../algebra/wrapper_blas.h"

using sepolia::dense_matrix;

int main() {

    std::cout << std::boolalpha;

    // double

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = rows;

        dense_matrix<double> md(rows, columns);

        // build local test matrix

        for (uint64_t i = 0; i < md.rows(); i++) {
            for (uint64_t j = 0; j < md.columns(); j++) {
                md(i, j) = static_cast<double>(i);
            }
        }

        sepolia::Transpose(md);

        // build the matrix to compare

        dense_matrix<double> md_res(rows, columns);

        for (uint64_t i = 0; i < md.rows(); i++) {
            for (uint64_t j = 0; j < md.columns(); j++) {
                md_res(j, i) = static_cast<double>(i);
            }
        }

        // compare

        std::cout << (md == md_res) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(columns, rows);

        // build local test matrix

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {
                md1(i, j) = static_cast<double>(i);
            }
        }

        const auto md3 = md1;
        md1.deallocate();

        md2 = sepolia::Transpose(md3);

        // build the matrix to compare

        dense_matrix<double> md_res(rows, columns);

        for (uint64_t i = 0; i < md_res.rows(); i++) {
            for (uint64_t j = 0; j < md_res.columns(); j++) {
                md_res(i, j) = static_cast<double>(j);
            }
        }

        // compare

        std::cout << (md2 == md_res) << std::endl;

    }
}