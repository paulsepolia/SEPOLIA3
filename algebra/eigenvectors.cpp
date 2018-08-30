#include "eigenvectors.h"

namespace sepolia {

    dense_matrix<double> Eigenvectors(const dense_matrix<double> &matrix,
                                      std::string diagonalizer) {

        // local parameters

        const auto dimension = static_cast<int32_t>(std::sqrt(matrix.size()));

        // local variables

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
            std::cout << "ERROR: The algorithm failed to compute the eigenvectors." << std::endl;
            exit(1);
        }

        return eigenvectors;
    }
}