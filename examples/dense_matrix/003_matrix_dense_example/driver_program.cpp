#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    {
        matrix_dense<double> md;

        md.allocate(0, 0);

        std::cout << std::boolalpha;

        std::cout << (md.rows() == 0) << std::endl;
        std::cout << (md.columns() == 0) << std::endl;
        std::cout << !md.allocated() << std::endl;
        std::cout << md.deallocated() << std::endl;

        md.deallocate();

        std::cout << (md.rows() == 0) << std::endl;
        std::cout << (md.columns() == 0) << std::endl;
        std::cout << !md.allocated() << std::endl;
        std::cout << md.deallocated() << std::endl;
    }

    {
        matrix_dense<double> md;

        md.allocate(100, 200);

        std::cout << std::boolalpha;

        std::cout << (md.rows() == 100) << std::endl;
        std::cout << (md.columns() == 200) << std::endl;
        std::cout << md.allocated() << std::endl;
        std::cout << !md.deallocated() << std::endl;

        md.deallocate();

        std::cout << (md.rows() == 0) << std::endl;
        std::cout << (md.columns() == 0) << std::endl;
        std::cout << !md.allocated() << std::endl;
        std::cout << md.deallocated() << std::endl;
    }
}
