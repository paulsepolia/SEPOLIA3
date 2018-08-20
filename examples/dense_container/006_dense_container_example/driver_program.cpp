#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        const dense_container<double> dcon1(dimension, value);
        dense_container<double> dcon2(dimension);

        dcon2 = dcon1;

        std::cout << std::boolalpha;

        std::cout << (dcon1 == dcon2) << std::endl;
        std::cout << !(dcon1 != dcon2) << std::endl;

        dcon2.deallocate();

        dcon2 = dcon1;

        std::cout << (dcon1 == dcon2) << std::endl;
        std::cout << !(dcon1 != dcon2) << std::endl;

        dcon2.deallocate();

        std::cout << !(dcon1 == dcon2) << std::endl;
        std::cout << (dcon1 != dcon2) << std::endl;
    }
}
