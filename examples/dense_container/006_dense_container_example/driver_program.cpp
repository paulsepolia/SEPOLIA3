#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        const dense_container<double> vd1(dimension, value);
        dense_container<double> vd2(dimension);

        vd2 = vd1;

        std::cout << std::boolalpha;

        std::cout << (vd1 == vd2) << std::endl;
        std::cout << !(vd1 != vd2) << std::endl;

        vd2.deallocate();

        vd2 = vd1;

        std::cout << (vd1 == vd2) << std::endl;
        std::cout << !(vd1 != vd2) << std::endl;

        vd2.deallocate();

        std::cout << !(vd1 == vd2) << std::endl;
        std::cout << (vd1 != vd2) << std::endl;
    }
}
