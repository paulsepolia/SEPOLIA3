#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include "aux_functions.h"
#include "../dense_diagonalizers/dense_diagonalizers.h"

decltype(containers::vector) built_a_matrix(int32_t dimension) {

    decltype(containers::vector) matrix(static_cast<uint64_t>(std::pow(dimension, 2.0)));

    for (int32_t i = 0; i != dimension; i++) {
        for (int32_t j = 0; j != dimension; j++) {
            if (std::abs(i - j) < 5) {
                matrix[i * dimension + j] = static_cast<double>(i + j);
            } else if (std::abs(i - j) >= 5) {
                matrix[i * dimension + j] = 0.0;
            }
        }
    }

    return matrix;
}

void print_eigenvalues(const decltype(containers::vector) &eigenvalues,
                       int32_t eigenvalue_start,
                       int32_t eigenvalue_end) {

    std::cout << std::setprecision(10);

    int32_t counter = eigenvalue_start;

    for (int32_t i = eigenvalue_start - 1; i < eigenvalue_end; i++) {

        std::cout << std::right << std::fixed << std::setw(10) << counter
                  << std::right << std::fixed << std::setw(30) << eigenvalues[i] << std::endl;
        counter++;
    }

    std::cout << std::endl;
}

void print_eigenvectors(const decltype(containers::matrix) &eigenvectors,
                        int32_t eigenvector_start,
                        int32_t eigenvector_end) {

    std::cout << std::setprecision(10);

    const auto dimension = static_cast<int32_t>(eigenvectors.size());

    int32_t counter = eigenvector_start;
    uint64_t line_loc = 0;

    for (int32_t i = eigenvector_start - 1; i < eigenvector_end; i++) {

        for (int32_t j = 0; j < dimension; j++) {

            line_loc++;

            std::cout << std::right << std::fixed << std::setw(10) << line_loc
                      << std::right << std::fixed << std::setw(20) << counter
                      << std::right << std::fixed << std::setw(30) << eigenvectors[i][j] << std::endl;
        }

        counter++;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
