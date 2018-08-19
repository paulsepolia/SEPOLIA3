#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_vector/vector_dense.h"

using sepolia::vector_dense;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(constructor_with_no_arguments, constructors) {

    vector_dense<double> vd;

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());
}

TEST(constructor_with_one_argument, constructors) {

    vector_dense<double> vd(dimension);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());
    EXPECT_EQ(vd, 0.0);
    EXPECT_EQ(0.0, vd);
    EXPECT_EQ(vector_dense<double>(dimension, 0.0), vd);
    EXPECT_EQ(vd, vector_dense<double>(dimension, 0.0));
}

TEST(constructor_with_two_arguments, constructors) {

    vector_dense<double> vd(dimension, value);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());
    EXPECT_EQ(vd, value);
    EXPECT_EQ(value, vd);
    EXPECT_EQ(vector_dense<double>(dimension, value), value);
    EXPECT_EQ(value, vector_dense<double>(dimension, value));
    EXPECT_EQ(vector_dense<double>(dimension, value), vd);
    EXPECT_EQ(vd, vector_dense<double>(dimension, value));

    for (const auto &el: vd) {
        EXPECT_EQ(value, el);
    }
}

TEST(constructor_all_in_one, constructors) {

    {
        // not equal dimension, equal default value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        vector_dense<double> vd1(dimension1);
        vector_dense<double> vd2(dimension2);

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

        EXPECT_EQ(vector_dense<double>(dimension1), vd1);
        EXPECT_EQ(vector_dense<double>(dimension2), vd2);

        EXPECT_EQ(vd1, vector_dense<double>(dimension1));
        EXPECT_EQ(vd2, vector_dense<double>(dimension2));

        for (const auto &el: vd1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: vd2) {
            EXPECT_EQ(0.0, el);
        }

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);

        EXPECT_NE(vector_dense<double>(dimension1), vd2);
        EXPECT_NE(vector_dense<double>(dimension2), vd1);
        EXPECT_NE(vd1, vector_dense<double>(dimension2));
        EXPECT_NE(vd2, vector_dense<double>(dimension1));
    }

    {
        // not equal dimension, equal value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        vector_dense<double> vd1(dimension1, value);
        vector_dense<double> vd2(dimension2, value);

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

        EXPECT_EQ(vector_dense<double>(dimension1, value), vd1);
        EXPECT_EQ(vector_dense<double>(dimension2, value), vd2);

        EXPECT_EQ(value, vector_dense<double>(dimension1, value));
        EXPECT_EQ(value, vector_dense<double>(dimension2, value));

        for (const auto &el: vd1) {
            EXPECT_EQ(value, el);
        }

        for (const auto &el: vd2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);

        EXPECT_NE(vector_dense<double>(dimension1, value), vd2);
        EXPECT_NE(vector_dense<double>(dimension2, value), vd1);
        EXPECT_NE(vd1, vector_dense<double>(dimension2, value));
        EXPECT_NE(vd2, vector_dense<double>(dimension1, value));
    }

    {
        // equal dimension, not equal value

        vector_dense<double> vd1(dimension);
        vector_dense<double> vd2(dimension, value);

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

        EXPECT_EQ(vector_dense<double>(dimension, 0.0), 0.0);
        EXPECT_EQ(vector_dense<double>(dimension, value), vd2);

        EXPECT_EQ(0.0, vector_dense<double>(dimension, 0.0));
        EXPECT_EQ(value, vector_dense<double>(dimension, value));

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

        EXPECT_NE(vector_dense<double>(dimension, 0.0), value);
        EXPECT_NE(vector_dense<double>(dimension, value), 0.0);
        EXPECT_NE(value, vector_dense<double>(dimension, 0.0));
        EXPECT_NE(0.0, vector_dense<double>(dimension, value));
    }

    {
        // equal dimension, not equal value

        const double value1 = 123.456;
        const double value2 = 456.789;
        vector_dense<double> vd1(dimension, value1);
        vector_dense<double> vd2(dimension, value2);

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

        EXPECT_EQ(vector_dense<double>(dimension, value1), value1);
        EXPECT_EQ(vector_dense<double>(dimension, value2), value2);

        EXPECT_EQ(value1, vector_dense<double>(dimension, value1));
        EXPECT_EQ(value2, vector_dense<double>(dimension, value2));

        EXPECT_EQ(vector_dense<double>(dimension, value1), vd1);
        EXPECT_EQ(vector_dense<double>(dimension, value2), vd2);

        EXPECT_EQ(vd1, vector_dense<double>(dimension, value1));
        EXPECT_EQ(vd2, vector_dense<double>(dimension, value2));

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

        EXPECT_NE(vector_dense<double>(dimension, value1), value2);
        EXPECT_NE(vector_dense<double>(dimension, value2), value1);

        EXPECT_NE(value1, vector_dense<double>(dimension, value2));
        EXPECT_NE(value2, vector_dense<double>(dimension, value1));

        EXPECT_NE(vector_dense<double>(dimension, value1), vd2);
        EXPECT_NE(vector_dense<double>(dimension, value2), vd1);

        EXPECT_NE(vd1, vector_dense<double>(dimension, value2));
        EXPECT_NE(vd2, vector_dense<double>(dimension, value1));
    }
}