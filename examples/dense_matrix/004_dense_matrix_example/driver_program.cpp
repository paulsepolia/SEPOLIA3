#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));

        const double value = 123.456;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value);
        md2.set(value);

        std::cout << std::boolalpha;

        std::cout << (md1.rows() == md2.rows()) << std::endl;
        std::cout << (md1.columns() == md2.columns()) << std::endl;
        std::cout << (md1.allocated() == md2.allocated()) << std::endl;
        std::cout << (md1.deallocated() == md2.deallocated()) << std::endl;
        std::cout << (md1 == md2) << std::endl;

        std::cout << (md1 == value) << std::endl;
        std::cout << (value == md1) << std::endl;
        std::cout << (md2 == value) << std::endl;
        std::cout << (value == md2) << std::endl;

        md1.deallocate();
        md2.deallocate();

        std::cout << (md1.rows() == md2.rows()) << std::endl;
        std::cout << (md1.columns() == md2.columns()) << std::endl;
        std::cout << (md1.allocated() == md2.allocated()) << std::endl;
        std::cout << (md1.deallocated() == md2.deallocated()) << std::endl;
        std::cout << !(md1 == md2) << std::endl;
        std::cout << !(md1 == value) << std::endl;
        std::cout << !(value == md1) << std::endl;
        std::cout << !(md2 == value) << std::endl;
        std::cout << !(value == md2) << std::endl;
    }
}
