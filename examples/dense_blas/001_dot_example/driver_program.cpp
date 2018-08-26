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
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(columns, rows);
        dense_matrix<double> md3(rows, rows);

        // build local test matrices

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {
                md1(i, j) = static_cast<double>((i + j) % 2);
            }
        }

        for (uint64_t i = 0; i < md2.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {
                md2(i, j) = static_cast<double>((i - j) % 2);
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

    // std::complex<double>

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 3.0));

        dense_matrix<std::complex<double>> md1(rows, columns);
        dense_matrix<std::complex<double>> md2(columns, rows);
        dense_matrix<std::complex<double>> md3(rows, rows);

        // build local test matrices

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {

                const std::complex<double> tmp_elem = {static_cast<double>(i%2),
                                                       static_cast<double>(j%2)};

                md1(i, j) = tmp_elem;
            }
        }

        for (uint64_t i = 0; i < md2.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {

                const std::complex<double> tmp_elem = {static_cast<double>(i%2),
                                                       static_cast<double>(-j%2)};
                md2(i, j) = tmp_elem;
            }
        }

        md3 = sepolia::Dot(md1, md2);

        dense_matrix<std::complex<double>> md4(rows, rows);

        // build the result

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {

                std::complex<double> sum = {0.0, 0.0};

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