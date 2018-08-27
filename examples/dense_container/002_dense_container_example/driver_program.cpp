#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    const auto dimension = static_cast<uint64_t>(0);

    dense_container<double> dcon(dimension);

    std::cout << std::boolalpha;

    std::cout << (dcon.size() == dimension) << std::endl;
    std::cout << !dcon.allocated() << std::endl;
    std::cout << dcon.deallocated() << std::endl;

    dcon.deallocate();

    std::cout << (dcon.size() == 0) << std::endl;
    std::cout << !dcon.allocated() << std::endl;
    std::cout << dcon.deallocated() << std::endl;
}
