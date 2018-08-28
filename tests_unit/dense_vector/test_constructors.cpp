#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(constructor_no_arguments, constructors) {

    dense_vector<double> vd;

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());
}

TEST(constructor_one_arguments_value, constructors) {

    dense_vector<double> vd(dimension);

    vd = value;

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
    }

    {
        // not equal dimension, equal value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_vector<double> vd1(dimension1);
        dense_vector<double> vd2(dimension2);

        vd1 = value;
        vd2 = value;

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

        vd2 = value;

        EXPECT_EQ(true, vd1.allocated());
        EXPECT_EQ(true, vd2.allocated());
        EXPECT_EQ(false, vd1.deallocated());
        EXPECT_EQ(false, vd2.deallocated());

        EXPECT_EQ(dimension, vd1.size());
        EXPECT_EQ(dimension, vd2.size());

        EXPECT_EQ(vd2, value);

        EXPECT_EQ(value, vd2);

        for (const auto &el: vd2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(vd1, value);

        EXPECT_NE(value, vd1);

        EXPECT_NE(vd1, vd2);
        EXPECT_NE(vd2, vd1);
    }

    {
        // equal dimension, not equal value

        const double value1 = 123.456;
        const double value2 = 456.789;
        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1 = value1;
        vd2 = value2;

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