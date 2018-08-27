#pragma once

#include "../dense_matrix/dense_matrix.h"

namespace sepolia {

    dense_matrix<double> Dot(const dense_matrix<double> &,
                             const dense_matrix<double> &);

    dense_matrix<std::complex<double>> Dot(const dense_matrix<std::complex<double>> &,
                                           const dense_matrix<std::complex<double>> &);
}