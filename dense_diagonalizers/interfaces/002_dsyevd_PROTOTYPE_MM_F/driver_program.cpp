#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include "dense_diagonalizers.h"
#include "aux_functions.h"

// main program

int main() {

    std::cout << std::endl;
    std::cout << " --> LAPACKE_dsyevd (row-major, high-level)" << std::endl;

    const auto dimension = static_cast<int32_t>(2 * std::pow(10.0, 1.0));

    // container for the eigenvectors

    std::vector<double> eigenvalues(static_cast<uint64_t>(dimension));

    // build a matrix

    auto t1 = std::chrono::high_resolution_clock::now();

    auto matrix(built_a_matrix(dimension));

    auto t2 = std::chrono::high_resolution_clock::now();

    auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << std::endl;
    std::cout << " --> time to build the matrix is = " << time_span.count() << std::endl;

    // diagonalize the matrix

    t1 = std::chrono::high_resolution_clock::now();

    auto eigensystem = diagonalize(matrix);

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
