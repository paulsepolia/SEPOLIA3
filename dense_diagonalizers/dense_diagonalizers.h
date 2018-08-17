#pragma once

#include <vector>
#include <string>
#include "parameters.h"


struct containers {

    containers() = default;

    ~containers() = default;

    std::vector<double> vector;
    std::vector<std::vector<double>> matrix;
};

struct eigensystem {

    eigensystem() = default;

    ~eigensystem() = default;

    std::vector<double> eigenvalues;
    std::vector<std::vector<double>> eigenvectors;
};

eigensystem Eigensystem(const decltype(containers::vector) &matrix,
                        std::string diagonalizer = DSYEVD_LAPACKE);

decltype(eigensystem::eigenvalues) Eigenvalues(const decltype(containers::vector) &matrix,
                                               std::string diagonalizer = DSYEVD_LAPACKE);

decltype(eigensystem::eigenvectors) Eigenvectors(const decltype(containers::vector) &matrix,
                                                 std::string diagonalizer = DSYEVD_LAPACKE);
