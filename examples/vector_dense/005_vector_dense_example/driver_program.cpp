#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));

        vector_dense<double> vd1(dimension);
        vector_dense<double> vd2(dimension);

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

        vector_dense<double> vd1(dimension, value);
        vector_dense<double> vd2(dimension);

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
