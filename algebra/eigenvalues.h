#pragma once

#include "../sepolia/sepolia.h"

namespace sepolia {

    dense_vector<double> Eigenvalues(const dense_matrix<double> &matrix,
                                     std::string diagonalizer = DSYEVD_LAPACKE);
}