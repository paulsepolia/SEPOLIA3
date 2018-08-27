#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 / coeff;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (dcon2 * coeff == dcon1) << std::endl;
        std::cout << (dcon1 / coeff == dcon2) << std::endl;

        dcon2.deallocate();

        dcon2 = dcon1 * dcon1;

        std::cout << (dcon1 * dcon1 == dcon2) << std::endl;
        std::cout << (dcon2 / dcon1 == dcon1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 + coeff;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (dcon2 - coeff == dcon1) << std::endl;
        std::cout << (dcon1 + coeff == dcon2) << std::endl;

        dcon2.deallocate();

        dcon2 = dcon1 + dcon1;

        std::cout << (dcon1 + dcon1 == dcon2) << std::endl;
        std::cout << (dcon1 == dcon2 - dcon1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 - coeff;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (dcon2 + coeff == dcon1) << std::endl;
        std::cout << (dcon1 - coeff == dcon2) << std::endl;

        dcon2.deallocate();

        dcon2 = dcon1 - dcon1;

        std::cout << (dcon1 - dcon1 == dcon2) << std::endl;
        std::cout << (dcon1 != dcon2 - dcon1) << std::endl;
        std::cout << (dcon2 == 0.0) << std::endl;
        std::cout << (0.0 == dcon2) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 2.0;
        const double value2 = coeff * value1;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (dcon2 == coeff * dcon1) << std::endl;
        std::cout << (dcon1 == dcon2 / coeff) << std::endl;

        dcon2.deallocate();

        dcon2 = dcon1 / dcon1;

        std::cout << (1.0 == dcon2) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;

        dcon2.deallocate();

        dcon2 = (dcon1 / dcon1) * dcon1;

        std::cout << (dcon1 == dcon2) << std::endl;
        std::cout << (dcon2 == value1) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;
    }
}
