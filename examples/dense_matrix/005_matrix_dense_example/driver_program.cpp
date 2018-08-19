#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        matrix_dense<double> md1(rows, columns);
        matrix_dense<double> md2(rows, columns);

        for (uint64_t i = 0; i != rows; i++) {
            for (uint64_t j = 0; j != columns; j++) {

                md1(i, j) = static_cast<double>(i + j);
                md2(i, j) = static_cast<double>(i + j);
            }
        }

        std::cout << std::boolalpha;
        std::cout << (md1 == md2) << std::endl;

        md1.deallocate();
        md2.deallocate();

        std::cout << (md1 != md2) << std::endl;
        std::cout << !(md1 == md2) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 123.456789;

        matrix_dense<double> md1(rows, columns, value);
        matrix_dense<double> md2(rows, columns);

        for (uint64_t i = 0; i != rows; i++) {
            for (uint64_t j = 0; j != columns; j++) {

                md2(i, j) = value;
            }
        }


        std::cout << std::boolalpha;
        std::cout << (md1 == md2) << std::endl;

        md1.deallocate();
        md2.deallocate();

        std::cout << (md1 != md2) << std::endl;
        std::cout << !(md1 == md2) << std::endl;
    }
}
