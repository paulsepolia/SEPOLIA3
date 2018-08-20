#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 / coeff;

        const dense_container<double> dc1(dimension, value1);
        dense_container<double> dc2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (dc2 * coeff == dc1) << std::endl;
        std::cout << (dc1 / coeff == dc2) << std::endl;

        dc2.deallocate();

        dc2 = dc1 * dc1;

        std::cout << (dc1 * dc1 == dc2) << std::endl;
        std::cout << (dc2 / dc1 == dc1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 + coeff;

        const dense_container<double> dc1(dimension, value1);
        dense_container<double> dc2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (dc2 - coeff == dc1) << std::endl;
        std::cout << (dc1 + coeff == dc2) << std::endl;

        dc2.deallocate();

        dc2 = dc1 + dc1;

        std::cout << (dc1 + dc1 == dc2) << std::endl;
        std::cout << (dc1 == dc2 - dc1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 - coeff;

        const dense_container<double> dc1(dimension, value1);
        dense_container<double> dc2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (dc2 + coeff == dc1) << std::endl;
        std::cout << (dc1 - coeff == dc2) << std::endl;

        dc2.deallocate();

        dc2 = dc1 - dc1;

        std::cout << (dc1 - dc1 == dc2) << std::endl;
        std::cout << (dc1 != dc2 - dc1) << std::endl;
        std::cout << (dc2 == 0.0) << std::endl;
        std::cout << (0.0 == dc2) << std::endl;
        std::cout << (dc1 == value1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 2.0;
        const double value2 = coeff * value1;

        const dense_container<double> dc1(dimension, value1);
        dense_container<double> dc2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (dc2 == coeff * dc1) << std::endl;
        std::cout << (dc1 == dc2 / coeff) << std::endl;

        dc2.deallocate();

        dc2 = dc1 / dc1;

        std::cout << (1.0 == dc2) << std::endl;
        std::cout << (dc1 == value1) << std::endl;

        dc2.deallocate();

        dc2 = (dc1 / dc1) * dc1;

        std::cout << (dc1 == dc2) << std::endl;
        std::cout << (dc2 == value1) << std::endl;
        std::cout << (dc1 == value1) << std::endl;
    }
}
