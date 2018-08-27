#pragma once

#include "../dense_matrix/dense_matrix.h"

namespace sepolia {

    dense_matrix<float> Dot(const dense_matrix<float> &,
                            const dense_matrix<float> &);

    dense_matrix<double> Dot(const dense_matrix<double> &,
                             const dense_matrix<double> &);

    dense_matrix<std::complex<float>> Dot(const dense_matrix<std::complex<float>> &,
                                          const dense_matrix<std::complex<float>> &);

    dense_matrix<std::complex<double>> Dot(const dense_matrix<std::complex<double>> &,
                                           const dense_matrix<std::complex<double>> &);
}