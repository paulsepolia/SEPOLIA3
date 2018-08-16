#include <vector>
#include <cstdint>
#include <cmath>
#include "/opt/_intel/mkl/include/mkl_lapacke.h"

std::vector<std::vector<double>> diagonalize(const std::vector<double> &matrix) {

    // local parameters

    const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));
    const auto lda = dimension;

    // local variables

    int32_t info = 0;
    std::vector<double> eigenvalues(static_cast<uint64_t>(dimension));
    std::vector<double> eigenvectors(matrix);

    // diagonalize here

    info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR, 'V', 'U', dimension, &eigenvectors[0], lda, &eigenvalues[0]);

    // build the eigensystem and add some info for the success of the process

    std::vector<std::vector<double>> eigensystem;

    eigensystem.push_back(std::move(eigenvalues));
    eigensystem.push_back(std::move(eigenvectors));
    eigensystem.push_back(std::vector<double>{static_cast<double>(info)});

    return eigensystem;
}