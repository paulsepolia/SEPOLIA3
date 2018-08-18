#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include "/opt/_intel/mkl/include/mkl_lapacke.h"

// help functions

std::vector<double> built_a_matrix(int32_t dimen) {

    std::vector<double> matrix_loc;
    matrix_loc.resize(static_cast<uint64_t>(std::pow(dimen, 2.0)));

    // build matrix here

    for (int32_t i = 0; i != dimen; i++) {
        for (int32_t j = 0; j != dimen; j++) {
            if (std::abs(i - j) < 5) {
                matrix_loc[i * dimen + j] = static_cast<double>(i + j);
            } else if (std::abs(i - j) >= 5) {
                matrix_loc[i * dimen + j] = 0.0;
            }
        }
    }

    return matrix_loc;
}

int32_t diagonalize_matrix(std::vector<double> &matrix,
                           std::vector<double> &eigenvalues,
                           std::vector<double> &eigenvectors,
                           int32_t &num_eigenvalues_found) {

    auto dimen = static_cast<int32_t>(eigenvalues.size());
    auto lda = dimen;
    auto nselect = static_cast<int32_t>(eigenvectors.size() / dimen);
    int32_t info = 0;
    auto ldz = nselect;
    int32_t il = 1;
    int32_t iu = nselect;
    int32_t m = 0;
    double abstol = -1.0;
    double vl = 0.0;
    double vu = 0.0;
    int32_t isuppz[dimen];

    info = LAPACKE_dsyevr(LAPACK_ROW_MAJOR, 'V', 'I', 'U',
                          dimen, &matrix[0], lda,
                          vl, vu, il, iu, abstol, &m,
                          &eigenvalues[0], &eigenvectors[0], ldz, isuppz);

    num_eigenvalues_found = m;

    return info;
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

void print_eigenvectors(const std::vector<double> &eigenvectors,
                        int32_t eigenvector_start,
                        int32_t eigenvector_end) {

    std::cout << std::setprecision(10);

    const auto dimen = static_cast<int32_t>(std::sqrt(static_cast<double>(eigenvectors.size())));

    int32_t counter = eigenvector_start;
    uint64_t line_loc = 0;

    for (int32_t i = eigenvector_start - 1; i < eigenvector_end; i++) {

        for (int32_t j = 0; j < dimen; j++) {

            line_loc++;

            std::cout << std::right << std::fixed << std::setw(10) << line_loc
                      << std::right << std::fixed << std::setw(20) << counter
                      << std::right << std::fixed << std::setw(30) << eigenvectors[j * dimen + i] << std::endl;
        }

        counter++;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

// main program

int main() {

    std::cout << std::endl;
    std::cout << " --> LAPACKE_dsyevr (row-major, high-level)" << std::endl;

    const auto DIMEN = static_cast<int32_t>(2 * std::pow(10.0, 1.0));
    const auto NSELECT = DIMEN;

    // container for the eigenvalues

    std::vector<double> eigenvalues;
    eigenvalues.resize(static_cast<uint64_t>(DIMEN));

    // container for the eigenvectors

    std::vector<double> eigenvectors;
    eigenvectors.resize(static_cast<uint64_t>(NSELECT) * static_cast<uint64_t>(DIMEN));

    // var to hold the number of eigenvalues found

    int32_t num_eigenvalues_found = 0;

    // build the matrix

    auto t1 = std::chrono::high_resolution_clock::now();

    std::vector<double> matrix(built_a_matrix(DIMEN));

    auto t2 = std::chrono::high_resolution_clock::now();

    auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << std::endl;
    std::cout << " --> time to build the matrix is = " << time_span.count() << std::endl;

    // diagonalize the matrix

    t1 = std::chrono::high_resolution_clock::now();

    auto info = diagonalize_matrix(matrix, eigenvalues, eigenvectors, num_eigenvalues_found);

    t2 = std::chrono::high_resolution_clock::now();

    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << std::endl;
    std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

    // check for convergence

    if (info > 0) {
        std::cout << std::endl;
        std::cout << " --> The algorithm failed to compute eigenvalues." << std::endl;
        exit(1);
    }

    // print the number of eigenvalues found

    std::cout << std::endl;
    std::cout << " --> number of eigenvalues found = " << num_eigenvalues_found << std::endl;

    // print eigenvalues

    std::cout << std::endl;
    print_eigenvalues(eigenvalues, 1, 20);

    // print eigenvectors

    std::cout << std::endl;
    print_eigenvectors(eigenvectors, 1, 2);
}
