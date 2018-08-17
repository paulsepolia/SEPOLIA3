#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>
#include "dense_diagonalizers.h"
#include "/opt/_intel/mkl/include/mkl_lapacke.h"

std::vector<std::vector<double>> eigensystem(const std::vector<double> &matrix,
                                             std::string diagonalizer) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

    // local variables

    int32_t info = 0;
    std::vector<double> eigenvalues(static_cast<uint64_t>(dimension));
    std::vector<double> eigenvectors(matrix);

    // diagonalize here

    if (diagonalizer == DSYEVD_LAPACKE) {

        info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR,
                              'V',
                              'U',
                              dimension,
                              &eigenvectors[0],
                              dimension,
                              &eigenvalues[0]);

    } else if (diagonalizer == DSYEV_LAPACKE) {

        info = LAPACKE_dsyev(LAPACK_ROW_MAJOR,
                             'V',
                             'U',
                             dimension,
                             &eigenvectors[0],
                             dimension,
                             &eigenvalues[0]);
    }

    // check for convergence

    if (info > 0) {
        std::cout << std::endl;
        std::cout << "ERROR: The algorithm failed to compute the eigensystem." << std::endl;
        exit(1);
    }

    // build the eigensystem and add some info for the success of the process

    std::vector<std::vector<double>> eigensystem;

    eigensystem.push_back(std::move(eigenvalues));
    eigensystem.push_back(std::move(eigenvectors));

    return eigensystem;
}

std::vector<double> eigenvalues(const std::vector<double> &matrix,
                                std::string diagonalizer) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

    // local variables

    int32_t info = 0;
    std::vector<double> eigenvalues(static_cast<uint64_t>(dimension));
    std::vector<double> eigenvectors(matrix);

    // diagonalize here

    if (diagonalizer == DSYEVD_LAPACKE) {

        info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR,
                              'V',
                              'U',
                              dimension,
                              &eigenvectors[0],
                              dimension,
                              &eigenvalues[0]);

    } else if (diagonalizer == DSYEV_LAPACKE) {

        info = LAPACKE_dsyev(LAPACK_ROW_MAJOR,
                             'V',
                             'U',
                             dimension,
                             &eigenvectors[0],
                             dimension,
                             &eigenvalues[0]);
    }

    // check for convergence

    if (info > 0) {
        std::cout << std::endl;
        std::cout << "ERROR: The algorithm failed to compute the eigenvalues." << std::endl;
        exit(1);
    }

    return eigenvalues;
}

std::vector<double> eigenvectors(const std::vector<double> &matrix,
                                 std::string diagonalizer) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

    // local variables

    int32_t info = 0;
    std::vector<double> eigenvalues(static_cast<uint64_t>(dimension));
    std::vector<double> eigenvectors(matrix);

    // diagonalize here

    if (diagonalizer == DSYEVD_LAPACKE) {

        info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR,
                              'V',
                              'U',
                              dimension,
                              &eigenvectors[0],
                              dimension,
                              &eigenvalues[0]);

    } else if (diagonalizer == DSYEV_LAPACKE) {

        info = LAPACKE_dsyev(LAPACK_ROW_MAJOR,
                             'V',
                             'U',
                             dimension,
                             &eigenvectors[0],
                             dimension,
                             &eigenvalues[0]);
    }

    // check for convergence

    if (info > 0) {
        std::cout << std::endl;
        std::cout << "ERROR: The algorithm failed to compute the eigenvectors." << std::endl;
        exit(1);
    }

    return eigenvectors;
}