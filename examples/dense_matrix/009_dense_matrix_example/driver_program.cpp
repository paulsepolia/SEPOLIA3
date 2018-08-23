#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 400.0;

        const dense_matrix<double> md1(rows, columns, value);
        dense_matrix<double> md2(rows, columns);

        std::cout << std::boolalpha;

        for (auto &el : md2) {
            el = value;
        }

        std::cout << (md2 == md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 400.0;

        const dense_matrix<double> md1(rows, columns, value);
        dense_matrix<double> md2(rows, columns);

        std::cout << std::boolalpha;

        md2 = md1;

        std::cout << (md2 == md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 400.0;

        dense_matrix<double> md1(rows, columns, value);
        dense_matrix<double> md2(rows, columns);

        std::cout << std::boolalpha;

        md2 = std::move(md1);

        std::cout << (md2 == value) << std::endl;
        std::cout << md2.allocated() << std::endl;
        std::cout << md1.deallocated() << std::endl;

        md1.deallocate();
        md2.deallocate();

        std::cout << md1.deallocated() << std::endl;
        std::cout << md2.deallocated() << std::endl;
    }
}
