#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        const dense_container<double> dc1(dimension, value);
        dense_container<double> dc2(dimension);

        std::cout << std::boolalpha;

        for (auto &el : dc2) {
            el = value;
        }

        std::cout << (dc2 == dc1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        const dense_container<double> dc1(dimension, value);
        dense_container<double> dc2(dimension);

        std::cout << std::boolalpha;

        dc2 = dc1;

        std::cout << (dc2 == dc1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dc1(dimension, value);
        dense_container<double> dc2(dimension);

        std::cout << std::boolalpha;

        dc2 = std::move(dc1);

        std::cout << (dc2 == value) << std::endl;
        std::cout << dc2.allocated() << std::endl;
        std::cout << dc1.deallocated() << std::endl;

        dc1.deallocate();
        dc2.deallocate();

        std::cout << dc1.deallocated() << std::endl;
        std::cout << dc2.deallocated() << std::endl;
    }
}
