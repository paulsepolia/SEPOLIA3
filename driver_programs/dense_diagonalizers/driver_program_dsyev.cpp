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
        std::cout << DSYEV_LAPACKE << " --> (row-major, high-level)" << std::endl;

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

        auto eigensystem_local = eigensystem(matrix, DSYEV_LAPACKE);

        t2 = std::chrono::high_resolution_clock::now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

        // print eigenvalues

        std::cout << std::endl;
        print_eigenvalues(eigensystem_local[0], 1, 20);

        // print eigenvectors

        std::cout << std::endl;
        print_eigenvectors(eigensystem_local[1], 1, 2);
    }

    {
        // eigenvectors example

        std::cout << std::endl;
        std::cout << DSYEV_LAPACKE << " --> (row-major, high-level)" << std::endl;

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

        auto eigenvectors_local = eigenvectors(matrix, DSYEV_LAPACKE);

        t2 = std::chrono::high_resolution_clock::now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

        // print eigenvectors

        std::cout << std::endl;
        print_eigenvectors(eigenvectors_local, 1, 2);
    }

    {
        // eigenvalues example

        std::cout << std::endl;
        std::cout << DSYEV_LAPACKE << " --> (row-major, high-level)" << std::endl;

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

        auto eigenvalues_local = eigenvalues(matrix, DSYEV_LAPACKE);

        t2 = std::chrono::high_resolution_clock::now();

        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << std::endl;
        std::cout << " --> time to diagonalize the matrix is = " << time_span.count() << std::endl;

        // print eigenvalues

        std::cout << std::endl;
        print_eigenvalues(eigenvalues_local, 1, 20);
    }
}