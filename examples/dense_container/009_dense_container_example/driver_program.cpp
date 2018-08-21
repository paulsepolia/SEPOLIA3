#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_container/dense_container.h"

using sepolia::dense_container;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        const dense_container<double> dcon1(dimension, value);
        dense_container<double> dcon2(dimension);

        std::cout << std::boolalpha;

        for (auto &el : dcon2) {
            el = value;
        }

        std::cout << (dcon2 == dcon1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        const dense_container<double> dcon1(dimension, value);
        dense_container<double> dcon2(dimension);

        std::cout << std::boolalpha;

        dcon2 = dcon1;

        std::cout << (dcon2 == dcon1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon1(dimension, value);
        dense_container<double> dcon2(dimension);

        std::cout << std::boolalpha;

        dcon2 = std::move(dcon1);

        std::cout << (dcon2 == value) << std::endl;
        std::cout << dcon2.allocated() << std::endl;
        std::cout << dcon1.deallocated() << std::endl;

        dcon1.deallocate();
        dcon2.deallocate();

        std::cout << dcon1.deallocated() << std::endl;
        std::cout << dcon2.deallocated() << std::endl;
    }
}