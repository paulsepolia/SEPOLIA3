#pragma once

#include "/opt/_intel/mkl/include/mkl_types.h"

bool operator==(const MKL_Complex8 &value1, const MKL_Complex8 &value2);

bool operator==(const MKL_Complex16 &value1, const MKL_Complex16 &value2);

bool operator!=(const MKL_Complex8 &value1, const MKL_Complex8 &value2);

bool operator!=(const MKL_Complex16 &value1, const MKL_Complex16 &value2);
