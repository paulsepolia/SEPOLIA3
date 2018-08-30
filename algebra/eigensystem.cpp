#include "eigensystem.h"

namespace sepolia {

    eigensystem<double> Eigensystem(const dense_matrix<double> &matrix,
                                    std::string diagonalizer) {

        // local parameters and variables

        const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));
        int32_t info = 0;
        dense_vector<double> eigenvalues(static_cast<uint64_t>(dimension));
        dense_matrix<double> eigenvectors(matrix);

        // diagonalize here

        if (diagonalizer == DSYEVD_LAPACKE) {

            info = LAPACKE_dsyevd(LAPACK_ROW_MAJOR,
                                  'V',
                                  'U',
                                  dimension,
                                  &eigenvectors[0],
                                  dimension,
                                  &eigenvalues[0]);

        } else if (diagonalizer == DSYEV_LAPACKE) {

            info = LAPACKE_dsyev(LAPACK_ROW_MAJOR,
                                 'V',
                                 'U',
                                 dimension,
                                 &eigenvectors[0],
                                 dimension,
                                 &eigenvalues[0]);
        }

        // check for convergence

        if (info > 0) {
            std::cout << std::endl;
            std::cout << "ERROR: The algorithm failed to compute the eigensystem." << std::endl;
            exit(1);
        }

        // get the eigensystem

        eigensystem<double> eig_system;
        eig_system.eigenvalues = std::move(eigenvalues);
        eig_system.eigenvectors = std::move(eigenvectors);

        return eig_system;
    }
}
