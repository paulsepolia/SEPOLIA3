#include <cstdint>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "aux_functions.h"
#include "../dense_diagonalizers/dense_diagonalizers.h"

dense_matrix<double> built_a_matrix(const uint64_t &rows, const uint64_t &columns) {

    dense_matrix<double> matrix(rows, columns);

    for (uint64_t i = 0; i < rows; i++) {
        for (uint64_t j = 0; j < columns; j++) {
            if (i + j < 5) {
                matrix[i * columns + j] = static_cast<double>(i + j);
            } else if (i + j >= 5) {
                matrix[i * columns + j] = 0.0;
            }
        }
    }

    return matrix;
}

void print_eigenvalues(const dense_vector<double> &eigenvalues,
                       uint64_t eigenvalue_start,
                       uint64_t eigenvalue_end) {

    std::cout << std::setprecision(10);

    uint64_t counter = eigenvalue_start;

    for (uint64_t i = eigenvalue_start; i <= eigenvalue_end; i++) {

        std::cout << std::right << std::fixed << std::setw(10) << counter
                  << std::right << std::fixed << std::setw(30)
                  << eigenvalues[i] << std::endl;
        counter++;
    }

    std::cout << std::endl;
}

void print_eigenvectors(const dense_matrix<double> &eigenvectors,
                        uint64_t eigenvector_start,
                        uint64_t eigenvector_end) {

    std::cout << std::setprecision(10);

    uint64_t counter = eigenvector_start;
    uint64_t line_loc = 0;

    for (uint64_t i = eigenvector_start; i <= eigenvector_end; i++) {

        for (uint64_t j = 0; j < eigenvectors.columns(); j++) {

            line_loc++;

            std::cout << std::right << std::fixed << std::setw(10) << line_loc
                      << std::right << std::fixed << std::setw(20) << counter
                      << std::right << std::fixed << std::setw(30)
                      << eigenvectors.at(i, j) << std::endl;
        }

        counter++;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void print_error_and_exit(const std::string &message) {

    std::cout << message << std::endl;
    exit(-1);
}
