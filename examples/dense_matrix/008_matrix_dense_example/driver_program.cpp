#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/matrix_dense.h"

using sepolia::matrix_dense;

int main() {

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value = 400.0;

        matrix_dense<double> md(rows, columns, value);

        std::cout << std::boolalpha;

        md++;
        value++;

        std::cout << (md == value) << std::endl;

        ++md;
        ++value;

        std::cout << (md == value) << std::endl;

        --md;
        --value;

        std::cout << (md == value) << std::endl;

        md--;
        value--;

        std::cout << (md == value) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 400.0;

        matrix_dense<double> md(rows, columns, value);

        std::cout << std::boolalpha;

        md += md;

        std::cout << (md == 2 * value) << std::endl;

        md -= md;

        std::cout << (md == 0.0) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 400.0;

        matrix_dense<double> md(rows, columns, value);

        std::cout << std::boolalpha;

        md *= md;

        std::cout << (md == value * value) << std::endl;

        md /= md;

        std::cout << (md == 1.0) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        const matrix_dense<double> md1(rows, columns, value1);
        matrix_dense<double> md2(rows, columns, value2);

        std::cout << std::boolalpha;

        md2 *= md1;

        std::cout << (md2 == value1 * value2) << std::endl;
        std::cout << (md1 == value1) << std::endl;

        md2 /= md1;

        std::cout << (md2 == value2) << std::endl;
        std::cout << (md1 == value1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        const matrix_dense<double> md1(rows, columns, value1);
        matrix_dense<double> md2(rows, columns, value2);

        std::cout << std::boolalpha;

        md2 += md1;

        std::cout << (md2 == value1 + value2) << std::endl;
        std::cout << (md1 == value1) << std::endl;

        md2 -= md1;

        std::cout << (md2 == value2) << std::endl;
        std::cout << (md1 == value1) << std::endl;
    }
}
