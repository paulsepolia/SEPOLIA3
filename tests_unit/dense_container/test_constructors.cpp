#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_container/dense_container.h"

using sepolia::dense_container;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(constructor_with_no_arguments, constructors) {

    dense_container<double> dcon;

    EXPECT_EQ(false, dcon.allocated());
    EXPECT_EQ(true, dcon.deallocated());
}

TEST(constructor_with_one_argument, constructors) {

    dense_container<double> dcon(dimension);

    EXPECT_EQ(true, dcon.allocated());
    EXPECT_EQ(false, dcon.deallocated());
    EXPECT_EQ(dimension, dcon.size());
    EXPECT_EQ(dcon, 0.0);
    EXPECT_EQ(0.0, dcon);
    EXPECT_EQ(dense_container<double>(dimension), dcon);
    EXPECT_EQ(dcon, dense_container<double>(dimension));
}

TEST(constructor_with_two_arguments, constructors) {

    dense_container<double> dcon(dimension);

    dcon.set(value);

    EXPECT_EQ(true, dcon.allocated());
    EXPECT_EQ(false, dcon.deallocated());
    EXPECT_EQ(dimension, dcon.size());
    EXPECT_EQ(dcon, value);
    EXPECT_EQ(value, dcon);

    for (const auto &el: dcon) {
        EXPECT_EQ(value, el);
    }
}

TEST(constructor_all_in_one, constructors) {

    {
        // not equal dimension, equal default value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_container<double> dcon1(dimension1);
        dense_container<double> dcon2(dimension2);

        EXPECT_EQ(true, dcon1.allocated());
        EXPECT_EQ(true, dcon2.allocated());
        EXPECT_EQ(false, dcon1.deallocated());
        EXPECT_EQ(false, dcon2.deallocated());

        EXPECT_EQ(dimension1, dcon1.size());
        EXPECT_EQ(dimension2, dcon2.size());

        EXPECT_EQ(dcon1, 0.0);
        EXPECT_EQ(dcon2, 0.0);

        EXPECT_EQ(0.0, dcon1);
        EXPECT_EQ(0.0, dcon2);

        EXPECT_EQ(dense_container<double>(dimension1), dcon1);
        EXPECT_EQ(dense_container<double>(dimension2), dcon2);

        EXPECT_EQ(dcon1, dense_container<double>(dimension1));
        EXPECT_EQ(dcon2, dense_container<double>(dimension2));

        for (const auto &el: dcon1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: dcon2) {
            EXPECT_EQ(0.0, el);
        }

        EXPECT_NE(dcon1, dcon2);
        EXPECT_NE(dcon2, dcon1);

        EXPECT_NE(dense_container<double>(dimension1), dcon2);
        EXPECT_NE(dense_container<double>(dimension2), dcon1);
        EXPECT_NE(dcon1, dense_container<double>(dimension2));
        EXPECT_NE(dcon2, dense_container<double>(dimension1));
    }

    {
        // not equal dimension, equal value

        const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_container<double> dcon1(dimension1);
        dense_container<double> dcon2(dimension2);

        dcon1.set(value);
        dcon2.set(value);

        EXPECT_EQ(true, dcon1.allocated());
        EXPECT_EQ(true, dcon2.allocated());
        EXPECT_EQ(false, dcon1.deallocated());
        EXPECT_EQ(false, dcon2.deallocated());

        EXPECT_EQ(dimension1, dcon1.size());
        EXPECT_EQ(dimension2, dcon2.size());

        EXPECT_EQ(dcon1, value);
        EXPECT_EQ(dcon2, value);

        EXPECT_EQ(value, dcon1);
        EXPECT_EQ(value, dcon2);


        for (const auto &el: dcon1) {
            EXPECT_EQ(value, el);
        }

        for (const auto &el: dcon2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(dcon1, dcon2);
        EXPECT_NE(dcon2, dcon1);

    }

    {
        // equal dimension, not equal value

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon2.set(value);

        EXPECT_EQ(true, dcon1.allocated());
        EXPECT_EQ(true, dcon2.allocated());
        EXPECT_EQ(false, dcon1.deallocated());
        EXPECT_EQ(false, dcon2.deallocated());

        EXPECT_EQ(dimension, dcon1.size());
        EXPECT_EQ(dimension, dcon2.size());

        EXPECT_EQ(dcon1, 0.0);
        EXPECT_EQ(dcon2, value);

        EXPECT_EQ(0.0, dcon1);
        EXPECT_EQ(value, dcon2);

        EXPECT_EQ(dense_container<double>(dimension), 0.0);

        EXPECT_EQ(0.0, dense_container<double>(dimension));

        for (const auto &el: dcon1) {
            EXPECT_EQ(0.0, el);
        }

        for (const auto &el: dcon2) {
            EXPECT_EQ(value, el);
        }

        EXPECT_NE(dcon1, value);
        EXPECT_NE(dcon2, 0.0);

        EXPECT_NE(value, dcon1);
        EXPECT_NE(0.0, dcon2);

        EXPECT_NE(dcon1, dcon2);
        EXPECT_NE(dcon2, dcon1);

        EXPECT_NE(dense_container<double>(dimension), value);
        EXPECT_NE(value, dense_container<double>(dimension));
    }

    {
        // equal dimension, not equal value

        const double value1 = 123.456;
        const double value2 = 456.789;
        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        EXPECT_EQ(true, dcon1.allocated());
        EXPECT_EQ(true, dcon2.allocated());

        EXPECT_EQ(false, dcon1.deallocated());
        EXPECT_EQ(false, dcon2.deallocated());

        EXPECT_EQ(dimension, dcon1.size());
        EXPECT_EQ(dimension, dcon2.size());

        EXPECT_EQ(dcon1, value1);
        EXPECT_EQ(dcon2, value2);

        EXPECT_EQ(value1, dcon1);
        EXPECT_EQ(value2, dcon2);

        for (const auto &el: dcon1) {
            EXPECT_EQ(value1, el);
        }

        for (const auto &el: dcon2) {
            EXPECT_EQ(value2, el);
        }

        EXPECT_NE(dcon1, value2);
        EXPECT_NE(dcon2, value1);

        EXPECT_NE(value1, dcon2);
        EXPECT_NE(value2, dcon1);

        EXPECT_NE(dcon1, dcon2);
        EXPECT_NE(dcon2, dcon1);
    }
}