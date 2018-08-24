#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

int main() {

    // any output line to the examples should be 'true'

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value = 123.456;

    dense_vector<double> vd(dimension);

    vd.set(value);

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
