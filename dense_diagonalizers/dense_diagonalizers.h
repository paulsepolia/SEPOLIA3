#pragma once

#include <vector>
#include <string>
#include "parameters.h"

namespace diagonalizers {

    struct eigensystem {

        eigensystem();

        ~eigensystem();

        std::vector<double> eigenvalues;
        std::vector<double> eigenvectors;
    };

    eigensystem Eigensystem(const std::vector<double> &matrix,
                            std::string diagonalizer = DSYEVD_LAPACKE);

    std::vector<double> Eigenvalues(const std::vector<double> &matrix,
                                    std::string diagonalizer = DSYEVD_LAPACKE);

    std::vector<double> Eigenvectors(const std::vector<double> &matrix,
                                     std::string diagonalizer = DSYEVD_LAPACKE);
}