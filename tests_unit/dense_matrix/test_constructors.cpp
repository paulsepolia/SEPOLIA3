#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
const double value = 123.456;

TEST(constructor_no_arguments, constructors) {

    dense_matrix<double> md;

    EXPECT_EQ(false, md.allocated());
    EXPECT_EQ(true, md.deallocated());
}

TEST(constructor_one_argument_zero_value, constructors) {

    dense_matrix<double> md(rows, columns);

    EXPECT_EQ(true, md.allocated());
    EXPECT_EQ(false, md.deallocated());
    EXPECT_EQ(rows * columns, md.size());
    EXPECT_EQ(md, 0.0);
    EXPECT_EQ(0.0, md);
    EXPECT_EQ(dense_matrix<double>(rows, columns), md);
    EXPECT_EQ(md, dense_matrix<double>(rows, columns));
}

TEST(constructor_one_arguments_value, constructors) {

    dense_matrix<double> md(rows, columns);

    md = value;

    EXPECT_EQ(true, md.allocated());
    EXPECT_EQ(false, md.deallocated());
    EXPECT_EQ(rows * columns, md.size());
    EXPECT_EQ(md, value);
    EXPECT_EQ(value, md);

    for (const auto &el: md) {
        EXPECT_EQ(value, el);
    }
}

TEST(constructor_all_in_one, constructors) {

    {
        // not equal dimensions, equal default value

        const auto rows1 = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const auto columns1 = static_cast<uint64_t>(std::pow(10.0, 2.0));

        const auto rows2 = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns2 = static_cast<uint64_t>(std::pow(10.0, 2.0));

        dense_matrix<double> md1(rows1, columns1);
        dense_matrix<double> md2(rows2, columns2);

        EXPECT_EQ(true, md1.allocated());
        EXPECT_EQ(true, md2.allocated());
        EXPECT_EQ(false, md1.deallocated());
        EXPECT_EQ(false, md2.deallocated());

        EXPECT_EQ(rows1 * columns1, md1.size());
        EXPECT_EQ(rows2 * columns2, md2.size());

        EXPECT_EQ(md1, 0.0);
        EXPECT_EQ(md2, 0.0);

        EXPECT_EQ(0.0, md1);
        EXPECT_EQ(0.0, md2);

        for (const auto &el: md1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: md2) {
            EXPECT_EQ(0.0, el);
        }

        EXPECT_NE(md1, md2);
        EXPECT_NE(md2, md1);

        EXPECT_NE(dense_matrix<double>(rows1, columns1), md2);
        EXPECT_NE(dense_matrix<double>(rows2, columns2), md1);
        EXPECT_NE(md1, dense_matrix<double>(rows2, columns2));
        EXPECT_NE(md2, dense_matrix<double>(rows1, columns1));
    }

    {
        // not equal dimension, equal value

        const auto rows1 = static_cast<uint64_t>(std::pow(10.0, 1.0));
        const auto columns1 = static_cast<uint64_t>(std::pow(10.0, 2.0));

        const auto rows2 = static_cast<uint64_t>(std::pow(10.0, 2.0));
        const auto columns2 = static_cast<uint64_t>(std::pow(10.0, 2.0));

        dense_matrix<double> md1(rows1, columns1);
        dense_matrix<double> md2(rows2, columns2);

        md1 = value;
        md2 = value;

        EXPECT_EQ(true, md1.allocated());
        EXPECT_EQ(true, md2.allocated());
        EXPECT_EQ(false, md1.deallocated());
        EXPECT_EQ(false, md2.deallocated());

        EXPECT_EQ(rows1 * columns1, md1.size());
        EXPECT_EQ(rows2 * columns2, md2.size());

        EXPECT_EQ(md1, value);
        EXPECT_EQ(md2, value);

        EXPECT_EQ(value, md1);
        EXPECT_EQ(value, md2);

        for (const auto &el: md1) {
            EXPECT_EQ(value, el);
        }

        for (const auto &el: md2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(md1, md2);
        EXPECT_NE(md2, md1);
    }

    {
        // equal dimension, not equal value

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md2 = value;

        EXPECT_EQ(true, md1.allocated());
        EXPECT_EQ(true, md2.allocated());
        EXPECT_EQ(false, md1.deallocated());
        EXPECT_EQ(false, md2.deallocated());

        EXPECT_EQ(rows * columns, md1.size());
        EXPECT_EQ(rows * columns, md2.size());

        EXPECT_EQ(md1, 0.0);
        EXPECT_EQ(md2, value);

        EXPECT_EQ(0.0, md1);
        EXPECT_EQ(value, md2);

        for (const auto &el: md1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: md2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(md1, value);
        EXPECT_NE(md2, 0.0);

        EXPECT_NE(value, md1);
        EXPECT_NE(0.0, md2);

        EXPECT_NE(md1, md2);
        EXPECT_NE(md2, md1);
    }

    {
        // equal dimension, not equal value

        const double value1 = 123.456;
        const double value2 = 456.789;
        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2(rows, columns);

        md1 = value1;
        md2 = value2;

        EXPECT_EQ(true, md1.allocated());
        EXPECT_EQ(true, md2.allocated());

        EXPECT_EQ(false, md1.deallocated());
        EXPECT_EQ(false, md2.deallocated());

        EXPECT_EQ(rows * columns, md1.size());
        EXPECT_EQ(rows * columns, md2.size());

        EXPECT_EQ(md1, value1);
        EXPECT_EQ(md2, value2);

        EXPECT_EQ(value1, md1);
        EXPECT_EQ(value2, md2);

        for (const auto &el: md1) {
            EXPECT_EQ(value1, el);
        }

        for (const auto &el: md2) {
            EXPECT_EQ(value2, el);
        }

        EXPECT_NE(md1, value2);
        EXPECT_NE(md2, value1);

        EXPECT_NE(value1, md2);
        EXPECT_NE(value2, md1);

        EXPECT_NE(md1, md2);
        EXPECT_NE(md2, md1);
    }
}