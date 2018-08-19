#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 123.456789;

        const matrix_dense<double> md1(rows, columns, value);
        matrix_dense<double> md2(rows, columns);

        md2 = md1;

        std::cout << std::boolalpha;

        std::cout << (md1 == md2) << std::endl;
        std::cout << !(md1 != md2) << std::endl;

        md2.deallocate();

        md2 = md1;

        std::cout << (md1 == md2) << std::endl;
        std::cout << !(md1 != md2) << std::endl;

        md2.deallocate();

        std::cout << !(md1 == md2) << std::endl;
        std::cout << (md1 != md2) << std::endl;
    }
}
