#pragma once

#include <vector>
#include <string>
#include "parameters.h"

namespace diagonalizers {

    std::vector<std::vector<double>> Eigensystem(const std::vector<double> &matrix,
                                                 std::string diagonalizer = DSYEVD_LAPACKE);

    std::vector<double> Eigenvalues(const std::vector<double> &matrix,
                                    std::string diagonalizer = DSYEVD_LAPACKE);

    std::vector<double> Eigenvectors(const std::vector<double> &matrix,
                                     std::string diagonalizer = DSYEVD_LAPACKE);
}