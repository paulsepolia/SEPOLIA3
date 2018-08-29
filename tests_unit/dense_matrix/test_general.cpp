#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

TEST(gen_1, general) {

    const dense_matrix<double> md1;

    EXPECT_TRUE(md1.size() == 0);
    EXPECT_TRUE(!md1.allocated());
    EXPECT_TRUE(md1.deallocated());
}

TEST(gen_2, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 1.0));

    dense_matrix<double> md1(rows, columns);

    EXPECT_TRUE(md1.size() == rows * columns);
    EXPECT_TRUE(md1.allocated());
    EXPECT_TRUE(md1.rows() == rows);
    EXPECT_TRUE(md1.columns() == columns);
    EXPECT_TRUE(!md1.deallocated());
    EXPECT_TRUE(md1 == static_cast<double>(0));
    EXPECT_TRUE(static_cast<double>(0) == md1);

    md1.deallocate();

    EXPECT_TRUE(md1.size() == 0);
    EXPECT_TRUE(!md1.allocated());
    EXPECT_TRUE(md1.rows() == 0);
    EXPECT_TRUE(md1.columns() == 0);
    EXPECT_TRUE(md1.deallocated());
    EXPECT_TRUE(md1 != static_cast<double>(0));
    EXPECT_TRUE(static_cast<double>(0) != md1);
}

TEST(gen_3, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(0);

    dense_matrix<double> md1(rows, columns);

    EXPECT_TRUE(md1.size() == 0);
    EXPECT_TRUE(!md1.allocated());
    EXPECT_TRUE(md1.rows() == 0);
    EXPECT_TRUE(md1.columns() == columns);
    EXPECT_TRUE(md1.deallocated());
    EXPECT_TRUE(!(md1 == 0));
    EXPECT_TRUE(md1 != 0);

    md1.deallocate();

    EXPECT_TRUE(md1.size() == 0);
    EXPECT_TRUE(!md1.allocated());
    EXPECT_TRUE(md1.rows() == 0);
    EXPECT_TRUE(md1.columns() == 0);
    EXPECT_TRUE(md1.deallocated());
    EXPECT_TRUE(!(md1 == 0));
    EXPECT_TRUE(md1 != 0);
}

TEST(gen_4, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const double value = 400.0;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value);

    md2 = md1;

    EXPECT_TRUE(md2 == md1);
    EXPECT_TRUE(md1 == md2);
    EXPECT_TRUE(md1.rows() == md2.rows());
    EXPECT_TRUE(md1.columns() == md2.columns());
    EXPECT_TRUE(md1.size() == md2.size());
    EXPECT_TRUE(md1.size() == rows * columns);
    EXPECT_TRUE(md1 == value);
    EXPECT_TRUE(md2 == value);
    EXPECT_TRUE(value == md1);
    EXPECT_TRUE(value == md2);

    md2.deallocate();

    EXPECT_TRUE(md2 != md1);
    EXPECT_TRUE(md1 != md2);
    EXPECT_TRUE(0 == md2.rows());
    EXPECT_TRUE(0 == md2.columns());
    EXPECT_TRUE(0 == md2.size());
    EXPECT_TRUE(md1.size() == rows * columns);
    EXPECT_TRUE(md1 == value);
    EXPECT_TRUE(md2 != 0.0);
    EXPECT_TRUE(value == md1);
    EXPECT_TRUE(value != md2);
}

TEST(gen_5, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const double value1 = 400.0;
    const double value2 = 500.0;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value2);

    EXPECT_TRUE(md1 == value1);
    EXPECT_TRUE(md2 == value2);
    EXPECT_TRUE(md1.allocated());
    EXPECT_TRUE(md2.allocated());
    EXPECT_TRUE(!md1.deallocated());
    EXPECT_TRUE(!md2.deallocated());
    EXPECT_TRUE(md1 != md2);
}

TEST(gen_6, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    double value1 = 400.0;
    double value2 = 100.0;
    const double coeff = value1 / value2;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value2);

    EXPECT_TRUE(md1 + md1 + md1 == 3 * value1);
    EXPECT_TRUE(3 * value1 == md1 + md1 + md1);

    EXPECT_TRUE(md1 == value2 * coeff);
    EXPECT_TRUE(md2 == value1 / coeff);

    ++md2;
    ++value2;

    EXPECT_TRUE(md2 == value2);

    md2++;
    value2++;

    EXPECT_TRUE(value2 == md2);

    ++md1;
    ++value1;

    EXPECT_TRUE(md1 == value1);

    md1++;
    value1++;

    EXPECT_TRUE(value1 == md1);
}

TEST(gen_7, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    double value1 = 400.0;
    double value2 = 100.0;
    const double coeff = value1 / value2;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value2);

    EXPECT_TRUE(coeff == md1 / md2);
    EXPECT_TRUE(1 / coeff == md2 / md1);
}


TEST(gen_8, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    double value1 = 400.0;
    double value2 = 100.0;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value2);

    EXPECT_TRUE(value1 + value2 == md1 + md2);
    EXPECT_TRUE(value2 + value1 == md2 + md1);

    EXPECT_TRUE(value1 - value2 == md1 - md2);
    EXPECT_TRUE(value2 - value1 == md2 - md1);

    EXPECT_TRUE(value1 * value2 == md1 * md2);
    EXPECT_TRUE(value1 * value2 == md2 * md1);

    EXPECT_TRUE(value1 / value2 == md1 / md2);
    EXPECT_TRUE(value2 / value1 == md2 / md1);
}

TEST(gen_9, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    double value1 = 400.0;
    double value2 = 100.0;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value2);

    EXPECT_TRUE(value1 + value2 == md1 + md2);
    EXPECT_TRUE(value2 + value1 == md2 + md1);

    EXPECT_TRUE(value1 - value2 == md1 - md2);
    EXPECT_TRUE(value2 - value1 == md2 - md1);

    EXPECT_TRUE(value1 * value2 == md1 * md2);
    EXPECT_TRUE(value1 * value2 == md2 * md1);

    EXPECT_TRUE(value1 / value2 == md1 / md2);
    EXPECT_TRUE(value2 / value1 == md2 / md1);
}


TEST(gen_10, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    double value1 = 400.0;
    double value2 = 100.0;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1.set(value1);
    md2.set(value2);

    md3 = md1 + md2;

    EXPECT_TRUE(value1 + value2 == md3);

    md3 = md1 - md2;

    EXPECT_TRUE(value1 - value2 == md3);

    md3 = md1 * md2;

    EXPECT_TRUE(value1 * value2 == md3);

    md3 = md1 / md2;

    EXPECT_TRUE(value1 / value2 == md3);
}

TEST(gen_11, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
    double value1 = 400.0;
    double value2 = 100.0;

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1.set(value1);
    md2.set(value2);

    md3 = md1 + md2 + md2 + md1;

    EXPECT_TRUE(2 * value1 + 2 * value2 == md3);

    md3 = md1 - md2 + md2 - md1;

    EXPECT_TRUE(0.0 == md3);

    md3 = (md1 * md2) / (md2 * md1);

    EXPECT_TRUE(1.0 == md3);

    md3 = (md1 / md2) * (md2 / md1);

    EXPECT_TRUE(1.0 == md3);
}


TEST(gen_12, general) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value = 123.456;

    dense_matrix<double> md(rows, columns);


    // test --> 1

    for (auto &el : md) {
        el = value;
    }

    EXPECT_TRUE(value == md);

    // test --> 2

    for (uint64_t i = 0; i != md.size(); i++) {
        md(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_TRUE(md(i) == static_cast<double>(i));
    }

    // test --> 3

    for (uint64_t i = 0; i != md.size(); i++) {
        md[i] = static_cast<double>(i + 1);
    }

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_TRUE(md[i] == static_cast<double>(i + 1));
    }

    // test --> 4

    for (uint64_t i = 0; i != md.rows(); i++) {
        for (uint64_t j = 0; j != md.columns(); j++) {
            md(i, j) = static_cast<double>(i + j);
        }
    }

    for (uint64_t i = 0; i != md.rows(); i++) {
        for (uint64_t j = 0; j != md.columns(); j++) {
            EXPECT_TRUE(md(i, j) == static_cast<double>(i + j));
        }
    }

    for (uint64_t i = 0; i != md.rows(); i++) {
        for (uint64_t j = 0; j != md.columns(); j++) {
            EXPECT_TRUE(md.at(i, j) == static_cast<double>(i + j));
        }
    }

    for (uint64_t i = 0; i != md.rows(); i++) {
        for (uint64_t j = 0; j != md.columns(); j++) {

            uint64_t index = i * md.rows() + j;
            EXPECT_TRUE(md.at(index) == static_cast<double>(i + j));
        }
    }
}
