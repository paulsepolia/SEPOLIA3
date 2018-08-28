#pragma once

// blas and lapack

#include "/opt/_intel/mkl/include/mkl_lapacke.h"
#include "/opt/_intel/mkl/include/mkl.h"

// parameters

#include "../parameters/parameters.h"

// auxiliary function

#include "../functions_aux/functions_aux.h"
#include "../functions_aux/overloaded_operators.h"

// dense containers

#include "../dense_vector/dense_vector.h"
#include "../dense_matrix/dense_matrix.h"

// dense diagonalizers

#include "../dense_diagonalizers/dense_diagonalizers.h"
#include "../dense_diagonalizers/dense_eigensystem.h"

// algebra

#include "../algebra/algrebra.h"
