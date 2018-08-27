#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value);

        vd2 = vd1;

        std::cout << std::boolalpha;

        std::cout << (vd1 == vd2) << std::endl;
        std::cout << !(vd1 != vd2) << std::endl;

        vd2.deallocate();

        vd2 = vd1;

        std::cout << (vd1 == vd2) << std::endl;
        std::cout << !(vd1 != vd2) << std::endl;

        vd2.deallocate();

        std::cout << !(vd1 == vd2) << std::endl;
        std::cout << (vd1 != vd2) << std::endl;
    }
}
