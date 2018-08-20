#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    const auto dimension = static_cast<uint64_t>(0);

    dense_container<double> dcon(dimension, 123.456);

    std::cout << std::boolalpha;

    std::cout << (dcon.size() == dimension) << std::endl;
    std::cout << !dcon.allocated() << std::endl;
    std::cout << dcon.deallocated() << std::endl;

    dcon.deallocate();

    std::cout << (dcon.size() == 0) << std::endl;
    std::cout << !dcon.allocated() << std::endl;
    std::cout << dcon.deallocated() << std::endl;
}
