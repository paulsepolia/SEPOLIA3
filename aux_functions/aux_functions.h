#pragma once

#include <cstdint>
#include <vector>

std::vector<double> built_a_matrix(int32_t dimension);

void print_eigenvalues(const std::vector<double> &eigenvalues,
                       int32_t eigenvalue_start,
                       int32_t eigenvalue_end);


void print_eigenvectors(const std::vector<std::vector<double>> &eigenvectors,
                        int32_t eigenvector_start,
                        int32_t eigenvector_end);