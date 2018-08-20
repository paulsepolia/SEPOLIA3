#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        const dense_container<double> dc1(dimension, value);
        dense_container<double> dc2(dimension);

        dc2 = dc1;

        std::cout << std::boolalpha;

        std::cout << (dc1 == dc2) << std::endl;
        std::cout << !(dc1 != dc2) << std::endl;

        dc2.deallocate();

        dc2 = dc1;

        std::cout << (dc1 == dc2) << std::endl;
        std::cout << !(dc1 != dc2) << std::endl;

        dc2.deallocate();

        std::cout << !(dc1 == dc2) << std::endl;
        std::cout << (dc1 != dc2) << std::endl;
    }
}
