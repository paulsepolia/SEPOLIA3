#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    // any output line to the examples should be 'true'

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const double value = 123.456;

    matrix_dense<double> md(rows, columns, value);

    std::cout << std::boolalpha;

    for (auto &el: md) {
        std::cout << (el == value) << std::endl;
    }

    std::cout << (md.rows() == rows) << std::endl;
    std::cout << (md.columns() == columns) << std::endl;

    std::cout << md.allocated() << std::endl;
    std::cout << !md.deallocated() << std::endl;

    md.deallocate();

    std::cout << (md.rows() == 0) << std::endl;
    std::cout << (md.columns() == 0) << std::endl;
    std::cout << !md.allocated() << std::endl;
    std::cout << md.deallocated() << std::endl;
}
