#pragma once

#include <string>
#include "eigensystem_dense.h"
#include "parameters.h"
#include "../containers/containers.h"


eigensystem_dense Eigensystem(const decltype(containers::vector) &matrix,
                        std::string diagonalizer = DSYEVD_LAPACKE);

decltype(eigensystem_dense::eigenvalues) Eigenvalues(const decltype(containers::vector) &matrix,
                                               std::string diagonalizer = DSYEVD_LAPACKE);

decltype(eigensystem_dense::eigenvectors) Eigenvectors(const decltype(containers::vector) &matrix,
                                                 std::string diagonalizer = DSYEVD_LAPACKE);
