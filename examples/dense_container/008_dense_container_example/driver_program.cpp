#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        double value = 400.0;

        dense_container<double> dc(dimension, value);

        std::cout << std::boolalpha;

        dc++;
        value++;

        std::cout << (dc == value) << std::endl;

        ++dc;
        ++value;

        std::cout << (dc == value) << std::endl;

        --dc;
        --value;

        std::cout << (dc == value) << std::endl;

        dc--;
        value--;

        std::cout << (dc == value) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dc(dimension, value);

        std::cout << std::boolalpha;

        dc += dc;

        std::cout << (dc == 2 * value) << std::endl;

        dc -= dc;

        std::cout << (dc == 0.0) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dc(dimension, value);

        std::cout << std::boolalpha;

        dc *= dc;

        std::cout << (dc == value * value) << std::endl;

        dc /= dc;

        std::cout << (dc == 1.0) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        const dense_container<double> dc1(dimension, value1);
        dense_container<double> dc2(dimension, value2);

        std::cout << std::boolalpha;

        dc2 *= dc1;

        std::cout << (dc2 == value1 * value2) << std::endl;
        std::cout << (dc1 == value1) << std::endl;

        dc2 /= dc1;

        std::cout << (dc2 == value2) << std::endl;
        std::cout << (dc1 == value1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        const dense_container<double> dc1(dimension, value1);
        dense_container<double> dc2(dimension, value2);

        std::cout << std::boolalpha;

        dc2 += dc1;

        std::cout << (dc2 == value1 + value2) << std::endl;
        std::cout << (dc1 == value1) << std::endl;

        dc2 -= dc1;

        std::cout << (dc2 == value2) << std::endl;
        std::cout << (dc1 == value1) << std::endl;
    }
}
