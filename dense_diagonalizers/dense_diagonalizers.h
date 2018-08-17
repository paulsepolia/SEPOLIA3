#pragma once

#include <vector>
#include <string>
#include "parameters.h"


struct eigensystem {

    eigensystem();

    ~eigensystem();

    std::vector<double> eigenvalues;
    std::vector<std::vector<double>> eigenvectors;
};

eigensystem Eigensystem(const std::vector<double> &matrix,
                        std::string diagonalizer = DSYEVD_LAPACKE);

std::vector<double> Eigenvalues(const std::vector<double> &matrix,
                                std::string diagonalizer = DSYEVD_LAPACKE);

std::vector<std::vector<double>> Eigenvectors(const std::vector<double> &matrix,
                                              std::string diagonalizer = DSYEVD_LAPACKE);
