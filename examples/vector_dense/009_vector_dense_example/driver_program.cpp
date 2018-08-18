#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        const vector_dense<double> vd1(dimension, value);
        vector_dense<double> vd2(dimension);

        std::cout << std::boolalpha;

        for (auto &el : vd2) {
            el = value;
        }

        std::cout << (vd2 == vd1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        const vector_dense<double> vd1(dimension, value);
        vector_dense<double> vd2(dimension);

        std::cout << std::boolalpha;

        vd2 = vd1;

        std::cout << (vd2 == vd1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        vector_dense<double> vd1(dimension, value);
        vector_dense<double> vd2(dimension);

        std::cout << std::boolalpha;

        vd2 = std::move(vd1);

        std::cout << (vd2 == value) << std::endl;
        std::cout << vd2.allocated() << std::endl;
        std::cout << vd1.deallocated() << std::endl;

        vd1.deallocate();
        vd2.deallocate();

        std::cout << vd1.deallocated() << std::endl;
        std::cout << vd2.deallocated() << std::endl;
    }
}
