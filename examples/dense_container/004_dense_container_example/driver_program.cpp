#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456;

        dense_container<double> dc1(dimension, value);
        dense_container<double> dc2(dimension, value);

        std::cout << std::boolalpha;

        std::cout << (dc1.size() == dc2.size()) << std::endl;
        std::cout << (dc1.allocated() == dc2.allocated()) << std::endl;
        std::cout << (dc1.deallocated() == dc2.deallocated()) << std::endl;
        std::cout << (dc1 == dc2) << std::endl;
        std::cout << (dc1 == value) << std::endl;
        std::cout << (value == dc1) << std::endl;
        std::cout << (dc2 == value) << std::endl;
        std::cout << (value == dc2) << std::endl;

        dc1.deallocate();
        dc2.deallocate();

        std::cout << (dc1.size() == dc2.size()) << std::endl;
        std::cout << (dc1.allocated() == dc2.allocated()) << std::endl;
        std::cout << (dc1.deallocated() == dc2.deallocated()) << std::endl;
        std::cout << !(dc1 == dc2) << std::endl;
        std::cout << !(dc1 == value) << std::endl;
        std::cout << !(value == dc1) << std::endl;
        std::cout << !(dc2 == value) << std::endl;
        std::cout << !(value == dc2) << std::endl;

    }
}
