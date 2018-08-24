#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 / coeff;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (md2 * coeff == md1) << std::endl;
        std::cout << (md1 / coeff == md2) << std::endl;

        md2.deallocate();

        md2 = md1 * md1;

        std::cout << (md1 * md1 == md2) << std::endl;
        std::cout << (md1 == md2 / md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 + coeff;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (md2 - coeff == md1) << std::endl;
        std::cout << (md1 + coeff == md2) << std::endl;

        md2.deallocate();

        md2 = md1 + md1;

        std::cout << (md1 + md1 == md2) << std::endl;
        std::cout << (md1 == md2 - md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 - coeff;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (md2 + coeff == md1) << std::endl;
        std::cout << (md1 - coeff == md2) << std::endl;

        md2.deallocate();

        md2 = md1 - md1;

        std::cout << (md1 - md1 == md2) << std::endl;
        std::cout << (md1 != md2 - md1) << std::endl;
        std::cout << (md2 == 0.0) << std::endl;
        std::cout << (0.0 == md2) << std::endl;
        std::cout << (md1 == value1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double coeff = 2.0;
        const double value2 = coeff * value1;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (md2 == coeff * md1) << std::endl;
        std::cout << (md1 == md2 / coeff) << std::endl;

        md2.deallocate();

        md2 = md1 / md1;

        std::cout << (1.0 == md2) << std::endl;
        std::cout << (md1 == value1) << std::endl;

        md2.deallocate();

        md2 = (md1 / md1) * md1;

        std::cout << (md1 == md2) << std::endl;
        std::cout << (md2 == value1) << std::endl;
        std::cout << (md1 == value1) << std::endl;
    }
}