#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    // any output line to the examples should be 'true'

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value = 123.456;

    dense_container<double> dc(dimension, value);

    std::cout << std::boolalpha;

    for (auto &el: dc) {
        std::cout << (el == value) << std::endl;
    }

    std::cout << (dc.size() == dimension) << std::endl;
    std::cout << dc.allocated() << std::endl;
    std::cout << !dc.deallocated() << std::endl;

    dc.deallocate();

    std::cout << (dc.size() == 0) << std::endl;
    std::cout << !dc.allocated() << std::endl;
    std::cout << dc.deallocated() << std::endl;
}
