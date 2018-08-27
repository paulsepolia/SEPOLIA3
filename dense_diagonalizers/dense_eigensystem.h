#pragma once

#include "../dense_vector/dense_vector.h"
#include "../dense_matrix/dense_matrix.h"

using namespace sepolia;

namespace sepolia {

    template<class T>
    class dense_eigensystem {

    public:

        dense_eigensystem() = default;

        ~dense_eigensystem() = default;

        dense_vector<T> eigenvalues;
        dense_matrix<T> eigenvectors;
    };
}