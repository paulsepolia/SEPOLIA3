#pragma once

#include "../containers/containers.h"

class eigensystem_dense {

public:

    eigensystem_dense();

    ~eigensystem_dense();

    decltype(containers::vector) eigenvalues;
    decltype(containers::matrix) eigenvectors;
};

