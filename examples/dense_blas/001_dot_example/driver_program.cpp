#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/dense_matrix.h"
#include "../../../wrappers/blas_lapack_gsl.h"

using sepolia::dense_matrix;

int main() {

    std::cout << std::boolalpha;

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = rows;
        const double value = 2.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);
        dense_matrix<double> md3(rows, columns);

        md1 = value;
        md2 = value;

        md3 = sepolia::Dot(md1, md2);

        std::cout << (md3(0, 0) == value * value * md3.rows()) << std::endl;
        std::cout << (md3(1, 1) == value * value * md3.rows()) << std::endl;
        std::cout << (md3 == value * value * md3.rows()) << std::endl;
        std::cout << (value * value * md3.rows() == md3) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);
        dense_matrix<double> md3(rows, columns);

        // build local test matrices

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {
                md1(i, j) = static_cast<double>(i + j);
            }
        }

        for (uint64_t i = 0; i < md2.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {
                md2(i, j) = static_cast<double>(i - j);
            }
        }

        md3 = sepolia::Dot(md1, md2);

        dense_matrix<double> md4(rows, columns);

        // build the result

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {

                double sum = 0.0;

                for (uint64_t k = 0; k < md2.rows(); k++) {
                    sum = sum + md1(i, k) * md2(k, j);
                }

                md4(i, j) = sum;
            }
        }

        // compare

        std::cout << (md3 == md4) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 3.0));

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(columns, rows);
        dense_matrix<double> md3(rows, rows);

        // build local test matrices

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {
                md1(i, j) = static_cast<double>(i + j);
            }
        }

        for (uint64_t i = 0; i < md2.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {
                md2(i, j) = static_cast<double>(i - j);
            }
        }

        md3 = sepolia::Dot(md1, md2);

        dense_matrix<double> md4(rows, rows);

        // build the result

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {

                double sum = 0.0;

                for (uint64_t k = 0; k < md2.rows(); k++) {
                    sum = sum + md1(i, k) * md2(k, j);
                }

                md4(i, j) = sum;
            }
        }

        // compare

        std::cout << (md3 == md4) << std::endl;
    }
}