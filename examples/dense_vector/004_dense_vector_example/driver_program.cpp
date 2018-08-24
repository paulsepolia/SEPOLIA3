#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value);
        vd2.set(value);

        std::cout << std::boolalpha;

        std::cout << (vd1.size() == vd2.size()) << std::endl;
        std::cout << (vd1.allocated() == vd2.allocated()) << std::endl;
        std::cout << (vd1.deallocated() == vd2.deallocated()) << std::endl;
        std::cout << (vd1 == vd2) << std::endl;
        std::cout << (vd1 == value) << std::endl;
        std::cout << (value == vd1) << std::endl;
        std::cout << (vd2 == value) << std::endl;
        std::cout << (value == vd2) << std::endl;

        vd1.deallocate();
        vd2.deallocate();

        std::cout << (vd1.size() == vd2.size()) << std::endl;
        std::cout << (vd1.allocated() == vd2.allocated()) << std::endl;
        std::cout << (vd1.deallocated() == vd2.deallocated()) << std::endl;
        std::cout << !(vd1 == vd2) << std::endl;
        std::cout << !(vd1 == value) << std::endl;
        std::cout << !(value == vd1) << std::endl;
        std::cout << !(vd2 == value) << std::endl;
        std::cout << !(value == vd2) << std::endl;

    }
}
