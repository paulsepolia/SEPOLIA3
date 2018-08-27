#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 123.456789;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value);

        md2 = md1;

        std::cout << std::boolalpha;

        std::cout << (md1 == md2) << std::endl;
        std::cout << !(md1 != md2) << std::endl;

        md2.deallocate();

        md2 = md1;

        std::cout << (md1 == md2) << std::endl;
        std::cout << !(md1 != md2) << std::endl;

        md2.deallocate();

        std::cout << !(md1 == md2) << std::endl;
        std::cout << (md1 != md2) << std::endl;
    }
}
