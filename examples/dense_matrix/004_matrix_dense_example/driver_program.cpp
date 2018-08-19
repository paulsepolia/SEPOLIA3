#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        const double value = 123.456;

        matrix_dense<double> md1(rows, columns, value);
        matrix_dense<double> md2(rows, columns, value);

        std::cout << std::boolalpha;

        std::cout << (md1.rows() == md2.rows()) << std::endl;
        std::cout << (md1.columns() == md2.columns()) << std::endl;
        std::cout << (md1.allocated() == md2.allocated()) << std::endl;
        std::cout << (md1.deallocated() == md2.deallocated()) << std::endl;
        std::cout << (md1 == md2) << std::endl;
        std::cout << (md1 == value) << std::endl;
        std::cout << (value == md1) << std::endl;
        std::cout << (md2 == value) << std::endl;
        std::cout << (value == md2) << std::endl;

        md1.deallocate();
        md2.deallocate();

        std::cout << (md1.rows() == md2.rows()) << std::endl;
        std::cout << (md1.columns() == md2.columns()) << std::endl;
        std::cout << (md1.allocated() == md2.allocated()) << std::endl;
        std::cout << (md1.deallocated() == md2.deallocated()) << std::endl;
        std::cout << !(md1 == md2) << std::endl;
        std::cout << !(md1 == value) << std::endl;
        std::cout << !(value == md1) << std::endl;
        std::cout << !(md2 == value) << std::endl;
        std::cout << !(value == md2) << std::endl;
    }
}
