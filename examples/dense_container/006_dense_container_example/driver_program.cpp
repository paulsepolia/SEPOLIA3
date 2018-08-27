#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value);
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
