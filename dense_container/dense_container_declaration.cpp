#include <memory>
#include <vector>
#include <complex>
#include "dense_container_declaration.h"
#include "/opt/_intel/mkl/include/mkl_types.h"


bool operator==(const MKL_Complex8 &value1, const MKL_Complex8 &value2) {

    return (value1.real == value2.real) && (value1.imag == value2.imag);
}

bool operator==(const MKL_Complex16 &value1, const MKL_Complex16 &value2) {

    return (value1.real == value2.real) && (value1.imag == value2.imag);
}

bool operator!=(const MKL_Complex8 &value1, const MKL_Complex8 &value2) {

    return (value1.real != value2.real) || (value1.imag != value2.imag);
}

bool operator!=(const MKL_Complex16 &value1, const MKL_Complex16 &value2) {

    return (value1.real != value2.real) || (value1.imag != value2.imag);
}
