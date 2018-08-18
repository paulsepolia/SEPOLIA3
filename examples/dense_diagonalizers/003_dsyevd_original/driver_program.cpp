//   ======================
//   LAPACKE_dsyevd Example
//   ======================
//
//   Program computes all eigenvalues and eigenvectors of a real symmetric
//   matrix A using divide and conquer algorithm, where A is:
//
//     6.39   0.13  -8.23   5.71  -3.18
//     0.13   8.37  -4.46  -6.10   7.21
//    -8.23  -4.46  -9.58  -9.25  -7.42
//     5.71  -6.10  -9.25   3.72   8.54
//    -3.18   7.21  -7.42   8.54   2.51
//
//   Description.
//   ============
//
//   The routine computes all eigenvalues and, optionally, eigenvectors of an
//   n-by-n real symmetric matrix A. The eigenvector v(j) of A satisfies
//
//   A*v(j) = lambda(j)*v(j)
//
//   where lambda(j) is its eigenvalue. The computed eigenvectors are
//   orthonormal.
//   If the eigenvectors are requested, then this routine uses a divide and
//   conquer algorithm to compute eigenvalues and eigenvectors.
//
//   Example Program Results.
//   ========================
//
// LAPACKE_dsyevd (row-major, high-level) Example Program Results
//
// Eigenvalues
// -17.44 -11.96   6.72  14.25  19.84
//
// Eigenvectors (stored columnwise)
//  -0.26   0.31  -0.74   0.33   0.42
//  -0.17  -0.39  -0.38  -0.80   0.16
//  -0.89   0.04   0.09   0.03  -0.45
//  -0.29  -0.59   0.34   0.31   0.60
//  -0.19   0.63   0.44  -0.38   0.48


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "/opt/_intel/mkl/include/mkl_lapacke.h"

// help function

void print_matrix(const std::string &desc, MKL_INT m, MKL_INT n, double *a, MKL_INT lda) {

    MKL_INT i;
    MKL_INT j;

    std::cout << desc << std::endl << std::endl;
    std::cout << std::setprecision(5);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            std::cout << std::right << std::fixed << std::setw(10) << a[i * lda + j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

// main program

int main() {

    const MKL_INT n = 5;
    const MKL_INT lda = n;
    MKL_INT info = 0;

    double w[n];

    double a[lda * n] = {
            6.39000, 0.13000, -8.23000, 5.71000, -3.18000,
            0.00000, 8.37000, -4.46000, -6.10000, 7.21000,
            0.00000, 0.00000, -9.58000, -9.25000, -7.42000,
            0.00000, 0.00000, 0.00000, 3.72000, 8.54000,
            0.00000, 0.00000, 0.00000, 0.00000, 2.51000
    };

    std::cout << " --> LAPACKE_dsyevd (row-major, high-level) Example Program Results" << std::endl;
    std::cout << std::endl;

    // solve

    info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR, 'V', 'U', n, a, lda, w);

    // check for convergence

    if (info > 0) {
        std::cout << " --> The algorithm failed to compute eigenvalues." << std::endl;
        exit(1);
    }

    // print eigenvalues

    const std::string desc_eigenvalues = " ==> Eigenvalues";
    print_matrix(desc_eigenvalues, 1, n, w, 1);

    // print eigenvectors

    const std::string desc_eigenvectors = " ==> Eigenvectors (stored columnwise)";
    print_matrix(desc_eigenvectors, n, n, a, lda);
}

