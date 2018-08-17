#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>
#include "dense_diagonalizers.h"
#include "/opt/_intel/mkl/include/mkl_lapacke.h"


eigensystem Eigensystem(const decltype(containers::vector) &matrix,
                        std::string diagonalizer) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

    // local variables

    int32_t info = 0;
    decltype(containers::vector) eigenvalues(static_cast<uint64_t>(dimension));
    decltype(containers::vector) eigenvectors(matrix);

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

    // make space for the the eigensystem

    eigensystem eig_system;

    eig_system.eigenvalues = std::move(eigenvalues);

    eig_system.eigenvectors.resize(static_cast<uint64_t>(dimension));

    for (auto &el: eig_system.eigenvectors) {
        el.resize(static_cast<uint64_t>(dimension));
    }

    // build the eigensystem

    for (int32_t i = 0; i < dimension; i++) {
        for (int32_t j = 0; j < dimension; j++) {

            eig_system.eigenvectors[i][j] = eigenvectors[i + dimension * j];
        }
    }

    return eig_system;
}

decltype(eigensystem::eigenvalues) Eigenvalues(const decltype(containers::vector) &matrix,
                                               std::string diagonalizer) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

    // local variables

    int32_t info = 0;
    decltype(containers::vector) eigenvalues(static_cast<uint64_t>(dimension));
    decltype(containers::vector) eigenvectors(matrix);

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

    eigensystem eig_system;

    eig_system.eigenvalues = std::move(eigenvalues);

    return eig_system.eigenvalues;
}

decltype(eigensystem::eigenvectors) Eigenvectors(const decltype(containers::vector) &matrix,
                                                 std::string diagonalizer) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

    // local variables

    int32_t info = 0;
    decltype(containers::vector) eigenvalues(static_cast<uint64_t>(dimension));
    decltype(containers::vector) eigenvectors(matrix);

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

    // make space for the the eigensystem

    eigensystem eig_system;

    eig_system.eigenvectors.resize(static_cast<uint64_t>(dimension));

    for (auto &el: eig_system.eigenvectors) {
        el.resize(static_cast<uint64_t>(dimension));
    }

    // build the eigensystem

    for (int32_t i = 0; i < dimension; i++) {
        for (int32_t j = 0; j < dimension; j++) {

            eig_system.eigenvectors[i][j] = eigenvectors[i + dimension * j];
        }
    }

    return eig_system.eigenvectors;
}