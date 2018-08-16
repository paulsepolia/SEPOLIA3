#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include "/opt/_intel/mkl/include/mkl_lapacke.h"

// help functions

std::vector<double> built_a_matrix(int32_t dimension) {

    std::vector<double> matrix_loc;
    matrix_loc.resize(static_cast<uint64_t>(std::pow(dimension, 2.0)));

    // build matrix here

    for (int32_t i = 0; i != dimension; i++) {
        for (int32_t j = 0; j != dimension; j++) {
            if (std::abs(i - j) < 5) {
                matrix_loc[i * dimension + j] = static_cast<double>(i + j);
            } else if (std::abs(i - j) >= 5) {
                matrix_loc[i * dimension + j] = 0.0;
            }
        }
    }

    return matrix_loc;
}

std::vector<std::vector<double>> diagonalize_matrix(const std::vector<double> &matrix) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));
    const auto lda = dimension;

    // local variables

    int32_t info = 0;

    std::vector<double> eigenvalues;
    eigenvalues.resize(static_cast<uint64_t>(dimension));

    std::vector<double> eigenvectors(matrix);

    // diagonalize here

    info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR, 'V', 'U', dimension, &eigenvectors[0], lda, &eigenvalues[0]);

    // build the eigensystem and info for the success of the process

    std::vector<std::vector<double>> eigensystem;

    eigensystem.push_back(std::move(eigenvalues));
    eigensystem.push_back(std::move(eigenvectors));
    eigensystem.push_back(std::vector<double>{static_cast<double>(info)});

    return eigensystem;
}

void print_eigenvalues(const std::vector<double> &eigenvectors,
                       int32_t eigenvalue_start,
                       int32_t eigenvalue_end) {

    std::cout << std::setprecision(10);

    int32_t counter = eigenvalue_start;

    for (int32_t i = eigenvalue_start - 1; i < eigenvalue_end; i++) {

        std::cout << std::right << std::fixed << std::setw(10) << counter
                  << std::right << std::fixed << std::setw(30) << eigenvectors[i] << std::endl;
        counter++;
    }

    std::cout << std::endl;
}

void print_eigenvectors(const std::vector<double> &matrix,
                        int32_t eigenvector_start,
                        int32_t eigenvector_end) {

    std::cout << std::setprecision(10);

    const auto dimension = static_cast<int32_t>(std::sqrt(static_cast<double>(matrix.size())));

    int32_t counter = eigenvector_start;
    uint64_t line_loc = 0;

    for (int32_t i = eigenvector_start - 1; i < eigenvector_end; i++) {

        for (int32_t j = 0; j < dimension; j++) {

            line_loc++;

            std::cout << std::right << std::fixed << std::setw(10) << line_loc
                      << std::right << std::fixed << std::setw(20) << counter
                      << std::right << std::fixed << std::setw(30) << matrix[j * dimension + i] << std::endl;
        }

        counter++;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


// main program

int main() {

    std::cout << std::endl;
    std::cout << " --> LAPACKE_dsyevd (row-major, high-level)" << std::endl;

    const auto dimension = static_cast<int32_t>(2 * std::pow(10.0, 1.0));

    // container for the eigenvectors

    std::vector<double> eigenvalues;
    eigenvalues.resize(static_cast<uint64_t>(dimension));

    // build a matrix

    auto t1 = std::chrono::high_resolution_clock::now();

    std::vector<double> matrix(built_a_matrix(dimension));

    auto t2 = std::chrono::high_resolution_clock::now();

    auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << std::endl;
    std::cout << " --> time to build the matrix is = " << time_span.count() << std::endl;

    // diagonalize the matrix

    t1 = std::chrono::high_resolution_clock::now();

    auto eigensystem = diagonalize_matrix(matrix);

    t2 = std::chrono::high_resolution_clock::now();

    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << std::endl;
    std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

    // check for convergence

    if (eigensystem[2][0] > 0) {
        std::cout << std::endl;
        std::cout << " --> The algorithm failed to compute eigenvalues." << std::endl;
        exit(1);
    }

    // print eigenvalues

    std::cout << std::endl;
    print_eigenvalues(eigensystem[0], 1, 20);

    // print eigenvectors

    std::cout << std::endl;
    print_eigenvectors(eigensystem[1], 1, 2);
}
