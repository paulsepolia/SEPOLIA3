#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_vector/vector_dense.h"

using sepolia::vector_dense;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 / coeff;

        const vector_dense<double> vd1(dimension, value1);
        vector_dense<double> vd2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (vd2 * coeff == vd1) << std::endl;
        std::cout << (vd1 / coeff == vd2) << std::endl;

        vd2.deallocate();

        vd2 = vd1 * vd1;

        std::cout << (vd1 * vd1 == vd2) << std::endl;
        std::cout << (vd1 == vd2 / vd1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 + coeff;

        const vector_dense<double> vd1(dimension, value1);
        vector_dense<double> vd2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (vd2 - coeff == vd1) << std::endl;
        std::cout << (vd1 + coeff == vd2) << std::endl;

        vd2.deallocate();

        vd2 = vd1 + vd1;

        std::cout << (vd1 + vd1 == vd2) << std::endl;
        std::cout << (vd1 == vd2 - vd1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 - coeff;

        const vector_dense<double> vd1(dimension, value1);
        vector_dense<double> vd2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (vd2 + coeff == vd1) << std::endl;
        std::cout << (vd1 - coeff == vd2) << std::endl;

        vd2.deallocate();

        vd2 = vd1 - vd1;

        std::cout << (vd1 - vd1 == vd2) << std::endl;
        std::cout << (vd1 != vd2 - vd1) << std::endl;
        std::cout << (vd2 == 0.0) << std::endl;
        std::cout << (0.0 == vd2) << std::endl;
        std::cout << (vd1 == value1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 2.0;
        const double value2 = coeff * value1;

        const vector_dense<double> vd1(dimension, value1);
        vector_dense<double> vd2(dimension, value2);

        std::cout << std::boolalpha;

        std::cout << (vd2 == coeff * vd1) << std::endl;
        std::cout << (vd1 == vd2 / coeff) << std::endl;

        vd2.deallocate();

        vd2 = vd1 / vd1;

        std::cout << (1.0 == vd2) << std::endl;
        std::cout << (vd1 == value1) << std::endl;

        vd2.deallocate();

        vd2 = (vd1 / vd1) * vd1;

        std::cout << (vd1 == vd2) << std::endl;
        std::cout << (vd2 == value1) << std::endl;
        std::cout << (vd1 == value1) << std::endl;
    }
}
