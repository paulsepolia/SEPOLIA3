#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    const auto rows = static_cast<uint64_t>(0);
    const auto columns = static_cast<uint64_t>(0);

    dense_matrix<double> md(rows, columns);

    md.set(123.456);

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
