#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

int main() {

    // any output line to the examples should be 'true'

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value = 123.456;

    vector_dense<double> vd(dimension, value);

    std::cout << std::boolalpha;

    for (auto &el: vd) {
        std::cout << (el == value) << std::endl;
    }

    std::cout << (vd.size() == dimension) << std::endl;
    std::cout << vd.allocated() << std::endl;
    std::cout << !vd.deallocated() << std::endl;

    vd.deallocate();

    std::cout << (vd.size() == 0) << std::endl;
    std::cout << !vd.allocated() << std::endl;
    std::cout << vd.deallocated() << std::endl;
}
