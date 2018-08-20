#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_container<double> vd1(dimension);
        dense_container<double> vd2(dimension);

        for (uint64_t i = 0; i != dimension; i++) {

            vd1[i] = static_cast<double>(i);
            vd2(i) = static_cast<double>(i);
        }

        std::cout << std::boolalpha;
        std::cout << (vd1 == vd2) << std::endl;

        vd1.deallocate();
        vd2.deallocate();

        std::cout << (vd1 != vd2) << std::endl;
        std::cout << !(vd1 == vd2) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        dense_container<double> vd1(dimension, value);
        dense_container<double> vd2(dimension);

        for (uint64_t i = 0; i != dimension; i++) {

            vd2(i) = value;
        }

        std::cout << std::boolalpha;
        std::cout << (vd1 == vd2) << std::endl;

        vd1.deallocate();
        vd2.deallocate();

        std::cout << (vd1 != vd2) << std::endl;
        std::cout << !(vd1 == vd2) << std::endl;
    }
}
