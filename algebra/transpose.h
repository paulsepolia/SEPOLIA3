#pragma once

#include <complex>
#include "../dense_matrix/dense_matrix.h"

namespace sepolia {

    dense_matrix<float> Transpose(const dense_matrix<float> &);

    dense_matrix<double> Transpose(const dense_matrix<double> &);

//    dense_matrix<std::complex<float>>
//    Transpose(const dense_matrix<std::complex<float>> &);

//    dense_matrix<std::complex<double>>
//    Transpose(const dense_matrix<std::complex<double>> &);

//    dense_matrix<MKL_Complex8>
//    Transpose(const dense_matrix<MKL_Complex8> &);
//
//    dense_matrix<MKL_Complex16>
//    Transpose(const dense_matrix<MKL_Complex16> &);

    void Transpose(dense_matrix<float> &);

    void Transpose(dense_matrix<double> &);

//    void Transpose(dense_matrix<std::complex<float>> &);
//
//    void Transpose(dense_matrix<std::complex<double>> &);

//    void Transpose(dense_matrix<MKL_Complex8> &);
//
//    void Transpose(dense_matrix<MKL_Complex16> &);
}