#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        for (uint64_t i = 0; i != dimension; i++) {

            dcon1[i] = static_cast<double>(i);
            dcon2(i) = static_cast<double>(i);
        }

        std::cout << std::boolalpha;
        std::cout << (dcon1 == dcon2) << std::endl;

        dcon1.deallocate();
        dcon2.deallocate();

        std::cout << (dcon1 != dcon2) << std::endl;
        std::cout << !(dcon1 == dcon2) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        dense_container<double> dcon1(dimension);

        dcon1.set(value);

        dense_container<double> dcon2(dimension);

        for (uint64_t i = 0; i != dimension; i++) {

            dcon2(i) = value;
        }

        std::cout << std::boolalpha;
        std::cout << (dcon1 == dcon2) << std::endl;

        dcon1.deallocate();
        dcon2.deallocate();

        std::cout << (dcon1 != dcon2) << std::endl;
        std::cout << !(dcon1 == dcon2) << std::endl;
    }
}
