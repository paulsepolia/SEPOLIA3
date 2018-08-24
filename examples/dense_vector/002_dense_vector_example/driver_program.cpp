#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

int main() {

    const auto dimension = static_cast<uint64_t>(0);

    dense_vector<double> vd(dimension);

    vd.set(123.456);

    std::cout << std::boolalpha;

    std::cout << (vd.size() == dimension) << std::endl;
    std::cout << !vd.allocated() << std::endl;
    std::cout << vd.deallocated() << std::endl;

    vd.deallocate();

    std::cout << (vd.size() == 0) << std::endl;
    std::cout << !vd.allocated() << std::endl;
    std::cout << vd.deallocated() << std::endl;
}
