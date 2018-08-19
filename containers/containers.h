#pragma once

#include <vector>
#include "../dense_vector/vector_dense.h"

class containers {

public:

    // NOTE:
    // Dense diagonalizers can get as input for eigenvalues
    // either a std::vector<double> or a sepolia::vector_dense<double>
    // container type

    //std::vector<double> vector;
    sepolia::vector_dense<double> vector;
    std::vector<std::vector<double>> matrix;
};

