#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    const auto dimension = static_cast<uint64_t>(0);

    dense_container<double> vd(dimension, 123.456);

    std::cout << std::boolalpha;

    std::cout << (vd.size() == dimension) << std::endl;
    std::cout << !vd.allocated() << std::endl;
    std::cout << vd.deallocated() << std::endl;

    vd.deallocate();

    std::cout << (vd.size() == 0) << std::endl;
    std::cout << !vd.allocated() << std::endl;
    std::cout << vd.deallocated() << std::endl;
}
