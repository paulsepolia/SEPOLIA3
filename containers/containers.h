#pragma once

#include <vector>
#include "../vector_dense/vector_dense.h"

class containers {

public:

    containers();

    ~containers();

    sepolia::vector_dense<double> vector;
    std::vector<std::vector<double>> matrix;
};

