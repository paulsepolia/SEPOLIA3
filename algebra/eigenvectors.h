#pragma once

#include "../sepolia/sepolia.h"

namespace sepolia {

    dense_matrix<double> Eigenvectors(const dense_matrix<double> &matrix,
                                      std::string diagonalizer = DSYEVD_LAPACKE);
}