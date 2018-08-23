#pragma once

#include <vector>
#include "../dense_vector/dense_vector.h"

class containers {

public:

    // NOTE:
    // Dense diagonalizers can get as input for eigenvalues
    // either a std::vector<double> or a sepolia::dense_vector<double>
    // container type

    //std::vector<double> vector;
    sepolia::dense_vector<double> vector;
    std::vector<std::vector<double>> matrix;
};

