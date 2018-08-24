#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        dense_matrix<double> md1(rows, columns);;
        dense_matrix<double> md2(rows, columns);

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

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value);

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
