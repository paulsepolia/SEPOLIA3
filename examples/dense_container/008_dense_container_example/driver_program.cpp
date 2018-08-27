#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        double value = 400.0;

        dense_container<double> dcon(dimension);

        dcon.set(value);

        std::cout << std::boolalpha;

        dcon++;
        value++;

        std::cout << (dcon == value) << std::endl;

        ++dcon;
        ++value;

        std::cout << (dcon == value) << std::endl;

        --dcon;
        --value;

        std::cout << (dcon == value) << std::endl;

        dcon--;
        value--;

        std::cout << (dcon == value) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon(dimension);
        dcon.set(value);

        std::cout << std::boolalpha;

        dcon += dcon;

        std::cout << (dcon == 2 * value) << std::endl;

        dcon -= dcon;

        std::cout << (dcon == 0.0) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon(dimension);
        dcon.set(value);

        std::cout << std::boolalpha;

        dcon *= dcon;

        std::cout << (dcon == value * value) << std::endl;

        dcon /= dcon;

        std::cout << (dcon == 1.0) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        std::cout << std::boolalpha;

        dcon2 *= dcon1;

        std::cout << (dcon2 == value1 * value2) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;

        dcon2 /= dcon1;

        std::cout << (dcon2 == value2) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        std::cout << std::boolalpha;

        dcon2 += dcon1;

        std::cout << (dcon2 == value1 + value2) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;

        dcon2 -= dcon1;

        std::cout << (dcon2 == value2) << std::endl;
        std::cout << (dcon1 == value1) << std::endl;
    }
}
