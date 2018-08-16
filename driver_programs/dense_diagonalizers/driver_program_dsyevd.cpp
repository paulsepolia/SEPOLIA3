#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include "../../dense_diagonalizers/dense_diagonalizers.h"
#include "../../aux_functions/aux_functions.h"

// main program

int main() {

    {
        // eigensystem example

        std::cout << std::endl;
        std::cout << " --> LAPACKE_dsyevd (row-major, high-level)" << std::endl;

        const auto dimension = static_cast<int32_t>(2 * std::pow(10.0, 1.0));

        // build a matrix

        auto t1 = std::chrono::high_resolution_clock::now();

        auto matrix(built_a_matrix(dimension));

        auto t2 = std::chrono::high_resolution_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to build the matrix is = " << time_span.count() << std::endl;

        // diagonalize the matrix

        t1 = std::chrono::high_resolution_clock::now();

        auto eigensystem_and_status = eigensystem(matrix);

        t2 = std::chrono::high_resolution_clock::now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

        // check for convergence

        if (eigensystem_and_status[2][0] > 0) {
            std::cout << std::endl;
            std::cout << " --> The algorithm failed to compute eigenvalues." << std::endl;
            exit(1);
        }

        // print eigenvalues

        std::cout << std::endl;
        print_eigenvalues(eigensystem_and_status[0], 1, 20);

        // print eigenvectors

        std::cout << std::endl;
        print_eigenvectors(eigensystem_and_status[1], 1, 2);
    }

    {
        // eigenvectors example

        std::cout << std::endl;
        std::cout << " --> LAPACKE_dsyevd (row-major, high-level)" << std::endl;

        const auto dimension = static_cast<int32_t>(2 * std::pow(10.0, 1.0));

        // build a matrix

        auto t1 = std::chrono::high_resolution_clock::now();

        auto matrix(built_a_matrix(dimension));

        auto t2 = std::chrono::high_resolution_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to build the matrix is = " << time_span.count() << std::endl;

        // diagonalize the matrix

        t1 = std::chrono::high_resolution_clock::now();

        auto eigenvectors_and_status = eigenvectors(matrix);

        t2 = std::chrono::high_resolution_clock::now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

        // check for convergence

        if (eigenvectors_and_status[1][0] > 0) {
            std::cout << std::endl;
            std::cout << " --> The algorithm failed to compute eigenvalues." << std::endl;
            exit(1);
        }

        // print eigenvectors

        std::cout << std::endl;
        print_eigenvectors(eigenvectors_and_status[0], 1, 2);
    }

    {
        // eigenvalues example

        std::cout << std::endl;
        std::cout << " --> LAPACKE_dsyevd (row-major, high-level)" << std::endl;

        const auto dimension = static_cast<int32_t>(2 * std::pow(10.0, 1.0));

        // build a matrix

        auto t1 = std::chrono::high_resolution_clock::now();

        auto matrix(built_a_matrix(dimension));

        auto t2 = std::chrono::high_resolution_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to build the matrix is = " << time_span.count() << std::endl;

        // diagonalize the matrix

        t1 = std::chrono::high_resolution_clock::now();

        auto eigenvalues_and_status = eigenvalues(matrix);

        t2 = std::chrono::high_resolution_clock::now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

        // check for convergence

        if (eigenvalues_and_status[1][0] > 0) {
            std::cout << std::endl;
            std::cout << " --> The algorithm failed to compute eigenvalues." << std::endl;
            exit(1);
        }

        // print eigenvalues

        std::cout << std::endl;
        print_eigenvalues(eigenvalues_and_status[0], 1, 20);
    }
}