#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_container/dense_container.h"

using sepolia::dense_container;

const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value1 = 123.456;
const double value2 = 345.678;

TEST(dcon_swap_preallocated, stl) {

    dense_container<double> dcon1(dimension1);
    dense_container<double> dcon2(dimension2);

    dcon1.set(value1);
    dcon2.set(value2);

    EXPECT_EQ(value1, dcon1);
    EXPECT_EQ(value2, dcon2);

    dcon1.swap(dcon2);

    EXPECT_EQ(value1, dcon2);
    EXPECT_EQ(value2, dcon1);
}

TEST(dcon_swap_one_preallocated, stl) {

    dense_container<double> dcon1(dimension1);
    dense_container<double> dcon2;

    dcon1.set(value1);

    EXPECT_EQ(value1, dcon1);
    EXPECT_TRUE(dcon2.deallocated());

    dcon1.swap(dcon2);

    EXPECT_EQ(value1, dcon2);
    EXPECT_TRUE(dcon1.deallocated());
}

TEST(dcon_swap_same_vector, stl) {

    dense_container<double> dcon1(dimension1);

    dcon1.set(value1);

    EXPECT_EQ(value1, dcon1);
    EXPECT_TRUE(dcon1.allocated());

    dcon1.swap(dcon1);

    EXPECT_EQ(value1, dcon1);
    EXPECT_TRUE(dcon1.allocated());
}

TEST(dcon_empty_preallocated_value, stl) {

    dense_container<double> dcon1(dimension1);

    dcon1.set(value1);

    EXPECT_FALSE(dcon1.empty());

    dcon1.deallocate();

    EXPECT_TRUE(dcon1.empty());
}

TEST(dcon_empty_preallocated_default_value, stl) {

    dense_container<double> dcon1(dimension1);

    EXPECT_FALSE(dcon1.empty());

    dcon1.deallocate();

    EXPECT_TRUE(dcon1.empty());
}

TEST(dcon_empty_not_preallocated, stl) {

    dense_container<double> dcon1;

    EXPECT_TRUE(dcon1.empty());

    dcon1.allocate(dimension1);

    EXPECT_FALSE(dcon1.empty());
}

TEST(dcon_at, stl) {

    dense_container<double> dcon1(dimension1);
    dense_container<double> dcon2(dimension2);

    dcon1.set(value1);
    dcon2.set(value2);

    EXPECT_EQ(value1, dcon1);
    EXPECT_EQ(value2, dcon2);

    for (uint64_t i = 0; i != dcon1.size(); i++) {
        EXPECT_EQ(value1, dcon1.at(i));
    }

    for (uint64_t i = 0; i != dcon2.size(); i++) {
        EXPECT_EQ(value2, dcon2.at(i));
    }

    for (auto &el: dcon1) {
        el = value2;
    }

    for (auto &el: dcon2) {
        el = value1;
    }

    EXPECT_EQ(value2, dcon1);
    EXPECT_EQ(value1, dcon2);

    for (uint64_t i = 0; i != dcon1.size(); i++) {
        EXPECT_EQ(value2, dcon1.at(i));
    }

    for (uint64_t i = 0; i != dcon2.size(); i++) {
        EXPECT_EQ(value1, dcon2.at(i));
    }
}