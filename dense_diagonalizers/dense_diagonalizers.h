#pragma once

#include <string>
#include "../parameters/parameters.h"
#include "../dense_matrix/dense_matrix.h"
#include "../dense_vector/dense_vector.h"
#include "dense_eigensystem.h"

using namespace sepolia;

namespace sepolia {

    dense_eigensystem<double> Eigensystem(const dense_matrix<double> &matrix,
                                          std::string diagonalizer = DSYEVD_LAPACKE);

    dense_vector<double> Eigenvalues(const dense_matrix<double> &matrix,
                                     std::string diagonalizer = DSYEVD_LAPACKE);

    dense_matrix<double> Eigenvectors(const dense_matrix<double> &matrix,
                                      std::string diagonalizer = DSYEVD_LAPACKE);

}
