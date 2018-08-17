#pragma once

#include <cstdint>
#include "../containers/containers.h"

decltype(containers::vector) built_a_matrix(int32_t dimension);

void print_eigenvalues(const decltype(containers::vector) &eigenvalues,
                       int32_t eigenvalue_start,
                       int32_t eigenvalue_end);


void print_eigenvectors(const decltype(containers::matrix) &eigenvectors,
                        int32_t eigenvector_start,
                        int32_t eigenvector_end);