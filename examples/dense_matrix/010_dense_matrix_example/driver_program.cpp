#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

int main() {

    std::cout << std::boolalpha;

    {
        const dense_matrix<double> md1;

        std::cout << (md1.size() == 0) << std::endl;
        std::cout << (!md1.allocated()) << std::endl;
        std::cout << (md1.deallocated()) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 1.0));

        dense_matrix<double> md1(rows, columns);

        std::cout << (md1.size() == rows * columns) << std::endl;
        std::cout << (md1.allocated()) << std::endl;
        std::cout << (md1.rows() == rows) << std::endl;
        std::cout << (md1.columns() == columns) << std::endl;
        std::cout << (!md1.deallocated()) << std::endl;
        std::cout << (md1 == static_cast<double>(0)) << std::endl;
        std::cout << (static_cast<double>(0) == md1) << std::endl;

        md1.deallocate();

        std::cout << (md1.size() == 0) << std::endl;
        std::cout << (!md1.allocated()) << std::endl;
        std::cout << (md1.rows() == 0) << std::endl;
        std::cout << (md1.columns() == 0) << std::endl;
        std::cout << (md1.deallocated()) << std::endl;
        std::cout << (md1 != static_cast<double>(0)) << std::endl;
        std::cout << (static_cast<double>(0) != md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(0);

        dense_matrix<double> md1(rows, columns);

        std::cout << (md1.size() == 0) << std::endl;
        std::cout << (!md1.allocated()) << std::endl;
        std::cout << (md1.rows() == 0) << std::endl;
        std::cout << (md1.columns() == columns) << std::endl;
        std::cout << (md1.deallocated()) << std::endl;
        std::cout << !(md1 == 0) << std::endl;
        std::cout << (md1 != 0) << std::endl;

        md1.deallocate();

        std::cout << (md1.size() == 0) << std::endl;
        std::cout << (!md1.allocated()) << std::endl;
        std::cout << (md1.rows() == 0) << std::endl;
        std::cout << (md1.columns() == 0) << std::endl;
        std::cout << (md1.deallocated()) << std::endl;
        std::cout << !(md1 == 0) << std::endl;
        std::cout << (md1 != 0) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value = 400.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value);

        std::cout << std::boolalpha;

        md2 = md1;

        std::cout << (md2 == md1) << std::endl;
        std::cout << (md1 == md2) << std::endl;
        std::cout << (md1.rows() == md2.rows()) << std::endl;
        std::cout << (md1.columns() == md2.columns()) << std::endl;
        std::cout << (md1.size() == md2.size()) << std::endl;
        std::cout << (md1.size() == rows * columns) << std::endl;
        std::cout << (md1 == value) << std::endl;
        std::cout << (md2 == value) << std::endl;
        std::cout << (value == md1) << std::endl;
        std::cout << (value == md2) << std::endl;

        md2.deallocate();

        std::cout << (md2 != md1) << std::endl;
        std::cout << (md1 != md2) << std::endl;
        std::cout << (0 == md2.rows()) << std::endl;
        std::cout << (0 == md2.columns()) << std::endl;
        std::cout << (0 == md2.size()) << std::endl;
        std::cout << (md1.size() == rows * columns) << std::endl;
        std::cout << (md1 == value) << std::endl;
        std::cout << (md2 != 0.0) << std::endl;
        std::cout << (value == md1) << std::endl;
        std::cout << (value != md2) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const double value1 = 400.0;
        const double value2 = 500.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (md1 == value1) << std::endl;
        std::cout << (md2 == value2) << std::endl;
        std::cout << md1.allocated() << std::endl;
        std::cout << md2.allocated() << std::endl;
        std::cout << !md1.deallocated() << std::endl;
        std::cout << !md2.deallocated() << std::endl;
        std::cout << (md1 != md2) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value1 = 400.0;
        double value2 = 100.0;
        const double coeff = value1 / value2;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (md1 + md1 + md1 == 3 * value1) << std::endl;
        std::cout << (3 * value1 == md1 + md1 + md1) << std::endl;

        std::cout << (md1 == value2 * coeff) << std::endl;
        std::cout << (md2 == value1 / coeff) << std::endl;

        ++md2;
        ++value2;

        std::cout << (md2 == value2) << std::endl;

        md2++;
        value2++;

        std::cout << (value2 == md2) << std::endl;

        ++md1;
        ++value1;

        std::cout << (md1 == value1) << std::endl;

        md1++;
        value1++;

        std::cout << (value1 == md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value1 = 400.0;
        double value2 = 100.0;
        const double coeff = value1 / value2;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (coeff == md1 / md2) << std::endl;
        std::cout << (1 / coeff == md2 / md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value1 = 400.0;
        double value2 = 100.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (value1 + value2 == md1 + md2) << std::endl;
        std::cout << (value2 + value1 == md2 + md1) << std::endl;

        std::cout << (value1 - value2 == md1 - md2) << std::endl;
        std::cout << (value2 - value1 == md2 - md1) << std::endl;

        std::cout << (value1 * value2 == md1 * md2) << std::endl;
        std::cout << (value1 * value2 == md2 * md1) << std::endl;

        std::cout << (value1 / value2 == md1 / md2) << std::endl;
        std::cout << (value2 / value1 == md2 / md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value1 = 400.0;
        double value2 = 100.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        std::cout << (value1 + value2 == md1 + md2) << std::endl;
        std::cout << (value2 + value1 == md2 + md1) << std::endl;

        std::cout << (value1 - value2 == md1 - md2) << std::endl;
        std::cout << (value2 - value1 == md2 - md1) << std::endl;

        std::cout << (value1 * value2 == md1 * md2) << std::endl;
        std::cout << (value1 * value2 == md2 * md1) << std::endl;

        std::cout << (value1 / value2 == md1 / md2) << std::endl;
        std::cout << (value2 / value1 == md2 / md1) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value1 = 400.0;
        double value2 = 100.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);
        dense_matrix<double> md3;

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        md3 = md1 + md2;

        std::cout << (value1 + value2 == md3) << std::endl;

        md3 = md1 - md2;

        std::cout << (value1 - value2 == md3) << std::endl;

        md3 = md1 * md2;

        std::cout << (value1 * value2 == md3) << std::endl;

        md3 = md1 / md2;

        std::cout << (value1 / value2 == md3) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
        double value1 = 400.0;
        double value2 = 100.0;

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);
        dense_matrix<double> md3;

        md1.set(value1);
        md2.set(value2);

        std::cout << std::boolalpha;

        md3 = md1 + md2 + md2 + md1;

        std::cout << (2 * value1 + 2 * value2 == md3) << std::endl;

        md3 = md1 - md2 + md2 - md1;

        std::cout << (0.0 == md3) << std::endl;

        md3 = (md1 * md2) / (md2 * md1);

        std::cout << (1.0 == md3) << std::endl;

        md3 = (md1 / md2) * (md2 / md1);

        std::cout << (1.0 == md3) << std::endl;
    }

    {
        const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const auto columns = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const double value = 123.456;

        dense_matrix<double> md(rows, columns);

        std::cout << std::boolalpha;

        // test --> 1

        for (auto &el : md) {
            el = value;
        }

        std::cout << (value == md) << std::endl;

        // test --> 2

        for (uint64_t i = 0; i != md.size(); i++) {
            md(i) = static_cast<double>(i);
        }

        for (uint64_t i = 0; i != md.size(); i++) {
            std::cout << (md(i) == static_cast<double>(i)) << std::endl;
        }

        // test --> 3

        for (uint64_t i = 0; i != md.size(); i++) {
            md[i] = static_cast<double>(i + 1);
        }

        for (uint64_t i = 0; i != md.size(); i++) {
            std::cout << (md[i] == static_cast<double>(i + 1)) << std::endl;
        }

        // test --> 4

        for (uint64_t i = 0; i != md.rows(); i++) {
            for (uint64_t j = 0; j != md.columns(); j++) {
                md(i, j) = static_cast<double>(i + j);
            }
        }

        for (uint64_t i = 0; i != md.rows(); i++) {
            for (uint64_t j = 0; j != md.columns(); j++) {
                std::cout << (md(i, j) == static_cast<double>(i + j)) << std::endl;
            }
        }

        for (uint64_t i = 0; i != md.rows(); i++) {
            for (uint64_t j = 0; j != md.columns(); j++) {
                std::cout << (md.at(i, j) == static_cast<double>(i + j)) << std::endl;
            }
        }

        for (uint64_t i = 0; i != md.rows(); i++) {
            for (uint64_t j = 0; j != md.columns(); j++) {

                uint64_t index = i * md.rows() + j;
                std::cout << (md.at(index) == static_cast<double>(i + j)) << std::endl;
            }
        }

    }
}
