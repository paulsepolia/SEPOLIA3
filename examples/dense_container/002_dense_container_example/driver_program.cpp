#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    const auto dimension = static_cast<uint64_t>(0);

    dense_container<double> dc(dimension, 123.456);

    std::cout << std::boolalpha;

    std::cout << (dc.size() == dimension) << std::endl;
    std::cout << !dc.allocated() << std::endl;
    std::cout << dc.deallocated() << std::endl;

    dc.deallocate();

    std::cout << (dc.size() == 0) << std::endl;
    std::cout << !dc.allocated() << std::endl;
    std::cout << dc.deallocated() << std::endl;
}
