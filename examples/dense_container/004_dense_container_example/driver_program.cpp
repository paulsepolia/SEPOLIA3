#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value);
        dcon2.set(value);

        std::cout << std::boolalpha;

        std::cout << (dcon1.size() == dcon2.size()) << std::endl;
        std::cout << (dcon1.allocated() == dcon2.allocated()) << std::endl;
        std::cout << (dcon1.deallocated() == dcon2.deallocated()) << std::endl;
        std::cout << (dcon1 == dcon2) << std::endl;
        std::cout << (dcon1 == value) << std::endl;
        std::cout << (value == dcon1) << std::endl;
        std::cout << (dcon2 == value) << std::endl;
        std::cout << (value == dcon2) << std::endl;

        dcon1.deallocate();
        dcon2.deallocate();

        std::cout << (dcon1.size() == dcon2.size()) << std::endl;
        std::cout << (dcon1.allocated() == dcon2.allocated()) << std::endl;
        std::cout << (dcon1.deallocated() == dcon2.deallocated()) << std::endl;
        std::cout << !(dcon1 == dcon2) << std::endl;
        std::cout << !(dcon1 == value) << std::endl;
        std::cout << !(value == dcon1) << std::endl;
        std::cout << !(dcon2 == value) << std::endl;
        std::cout << !(value == dcon2) << std::endl;
    }
}
