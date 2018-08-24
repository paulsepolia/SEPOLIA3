#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(constructor_with_no_arguments, constructors) {

    dense_vector<double> vd;

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());
}

TEST(constructor_with_one_argument, constructors) {

    dense_vector<double> vd(dimension);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());
    EXPECT_EQ(vd, 0.0);
    EXPECT_EQ(0.0, vd);
    EXPECT_EQ(dense_vector<double>(dimension), vd);
    EXPECT_EQ(vd, dense_vector<double>(dimension));
}

TEST(constructor_with_two_arguments, constructors) {

    dense_vector<double> vd(dimension);

    vd.set(value);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());
    EXPECT_EQ(vd, value);
    EXPECT_EQ(value, vd);

    for (const auto &el: vd) {
        EXPECT_EQ(value, el);
    }
}

TEST(constructor_all_in_one, constructors) {

    {
        // not equal dimension, equal default value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_vector<double> vd1(dimension1);
        dense_vector<double> vd2(dimension2);

        EXPECT_EQ(true, vd1.allocated());
        EXPECT_EQ(true, vd2.allocated());
        EXPECT_EQ(false, vd1.deallocated());
        EXPECT_EQ(false, vd2.deallocated());

        EXPECT_EQ(dimension1, vd1.size());
        EXPECT_EQ(dimension2, vd2.size());

        EXPECT_EQ(vd1, 0.0);
        EXPECT_EQ(vd2, 0.0);

        EXPECT_EQ(0.0, vd1);
        EXPECT_EQ(0.0, vd2);

        for (const auto &el: vd1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: vd2) {
            EXPECT_EQ(0.0, el);
        }

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);

        EXPECT_NE(dense_vector<double>(dimension1), vd2);
        EXPECT_NE(dense_vector<double>(dimension2), vd1);
        EXPECT_NE(vd1, dense_vector<double>(dimension2));
        EXPECT_NE(vd2, dense_vector<double>(dimension1));
    }

    {
        // not equal dimension, equal value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_vector<double> vd1(dimension1);
        dense_vector<double> vd2(dimension2);

        vd1.set(value);
        vd2.set(value);

        EXPECT_EQ(true, vd1.allocated());
        EXPECT_EQ(true, vd2.allocated());
        EXPECT_EQ(false, vd1.deallocated());
        EXPECT_EQ(false, vd2.deallocated());

        EXPECT_EQ(dimension1, vd1.size());
        EXPECT_EQ(dimension2, vd2.size());

        EXPECT_EQ(vd1, value);
        EXPECT_EQ(vd2, value);

        EXPECT_EQ(value, vd1);
        EXPECT_EQ(value, vd2);

        for (const auto &el: vd1) {
            EXPECT_EQ(value, el);
        }

        for (const auto &el: vd2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);
    }

    {
        // equal dimension, not equal value

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd2.set(value);

        EXPECT_EQ(true, vd1.allocated());
        EXPECT_EQ(true, vd2.allocated());
        EXPECT_EQ(false, vd1.deallocated());
        EXPECT_EQ(false, vd2.deallocated());

        EXPECT_EQ(dimension, vd1.size());
        EXPECT_EQ(dimension, vd2.size());

        EXPECT_EQ(vd1, 0.0);
        EXPECT_EQ(vd2, value);

        EXPECT_EQ(0.0, vd1);
        EXPECT_EQ(value, vd2);

        for (const auto &el: vd1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: vd2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(vd1, value);
        EXPECT_NE(vd2, 0.0);

        EXPECT_NE(value, vd1);
        EXPECT_NE(0.0, vd2);

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);
    }

    {
        // equal dimension, not equal value

        const double value1 = 123.456;
        const double value2 = 456.789;
        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        EXPECT_EQ(true, vd1.allocated());
        EXPECT_EQ(true, vd2.allocated());

        EXPECT_EQ(false, vd1.deallocated());
        EXPECT_EQ(false, vd2.deallocated());

        EXPECT_EQ(dimension, vd1.size());
        EXPECT_EQ(dimension, vd2.size());

        EXPECT_EQ(vd1, value1);
        EXPECT_EQ(vd2, value2);

        EXPECT_EQ(value1, vd1);
        EXPECT_EQ(value2, vd2);

        for (const auto &el: vd1) {
            EXPECT_EQ(value1, el);
        }

        for (const auto &el: vd2) {
            EXPECT_EQ(value2, el);
        }

        EXPECT_NE(vd1, value2);
        EXPECT_NE(vd2, value1);

        EXPECT_NE(value1, vd2);
        EXPECT_NE(value2, vd1);

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);
    }
}