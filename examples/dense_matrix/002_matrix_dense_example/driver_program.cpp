#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    const auto rows = static_cast<uint64_t>(0);
    const auto columns = static_cast<uint64_t>(0);

    matrix_dense<double> md(rows, columns, 123.456);

    std::cout << std::boolalpha;

    std::cout << (md.rows() == rows) << std::endl;
    std::cout << (md.columns() == columns) << std::endl;

    std::cout << !md.allocated() << std::endl;
    std::cout << md.deallocated() << std::endl;

    md.deallocate();

    std::cout << (md.rows() == 0) << std::endl;
    std::cout << (md.columns() == 0) << std::endl;
    std::cout << !md.allocated() << std::endl;
    std::cout << md.deallocated() << std::endl;
}
