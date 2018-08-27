#pragma once

#include "../dense_matrix/dense_matrix.h"

namespace sepolia {

    dense_matrix<double> Transpose(const dense_matrix<double> &);

    void Transpose(dense_matrix<double> &);
}