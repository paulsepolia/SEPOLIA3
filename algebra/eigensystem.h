#pragma once

#include "../sepolia/sepolia.h"

namespace sepolia {

    template<class T>
    struct eigensystem {

        dense_vector<T> eigenvalues;
        dense_matrix<T> eigenvectors;
    };

    eigensystem<double> Eigensystem(const dense_matrix<double> &matrix,
                                    std::string diagonalizer = DSYEVD_LAPACKE);
}
