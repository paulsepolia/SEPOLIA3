#pragma once

#include <vector>
#include <string>
#include "parameters.h"

std::vector<std::vector<double>> eigensystem(const std::vector<double> &matrix,
                                             std::string diagonalizer = DSYEVD_LAPACKE);

std::vector<std::vector<double>> eigenvalues(const std::vector<double> &matrix,
                                             std::string diagonalizer = DSYEVD_LAPACKE);

std::vector<std::vector<double>> eigenvectors(const std::vector<double> &matrix,
                                              std::string diagonalizer = DSYEVD_LAPACKE);
