#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        vector_dense<double> vd1(dimension, value);
        vector_dense<double> vd2(dimension);

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
