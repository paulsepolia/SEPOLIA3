#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_vector/vector_dense.h"

using sepolia::vector_dense;

const auto dimension1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
const auto dimension2 = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value1 = 123.456;
const double value2 = 345.678;

TEST(vd_swap_preallocated, stl) {

    vector_dense<double> vd1(dimension1, value1);
    vector_dense<double> vd2(dimension2, value2);

    EXPECT_EQ(value1, vd1);
    EXPECT_EQ(value2, vd2);

    vd1.swap(vd2);

    EXPECT_EQ(value1, vd2);
    EXPECT_EQ(value2, vd1);
}

TEST(vd_swap_one_preallocated, stl) {

    vector_dense<double> vd1(dimension1, value1);
    vector_dense<double> vd2;

    EXPECT_EQ(value1, vd1);
    EXPECT_TRUE(vd2.deallocated());

    vd1.swap(vd2);

    EXPECT_EQ(value1, vd2);
    EXPECT_TRUE(vd1.deallocated());
}

TEST(vd_swap_same_vector, stl) {

    vector_dense<double> vd1(dimension1, value1);

    EXPECT_EQ(value1, vd1);
    EXPECT_TRUE(vd1.allocated());

    vd1.swap(vd1);

    EXPECT_EQ(value1, vd1);
    EXPECT_TRUE(vd1.allocated());
}

TEST(vd_empty_preallocated_value, stl) {

    vector_dense<double> vd1(dimension1, value1);

    EXPECT_FALSE(vd1.empty());

    vd1.deallocate();

    EXPECT_TRUE(vd1.empty());
}

TEST(vd_empty_preallocated_default_value, stl) {

    vector_dense<double> vd1(dimension1);

    EXPECT_FALSE(vd1.empty());

    vd1.deallocate();

    EXPECT_TRUE(vd1.empty());
}

TEST(vd_empty_not_preallocated, stl) {

    vector_dense<double> vd1;

    EXPECT_TRUE(vd1.empty());

    vd1.allocate(dimension1);

    EXPECT_FALSE(vd1.empty());
}

TEST(vd_at, stl) {

    vector_dense<double> vd1(dimension1, value1);
    vector_dense<double> vd2(dimension2, value2);

    EXPECT_EQ(value1, vd1);
    EXPECT_EQ(value2, vd2);

    for (uint64_t i = 0; i != vd1.size(); i++) {
        EXPECT_EQ(value1, vd1.at(i));
    }

    for (uint64_t i = 0; i != vd2.size(); i++) {
        EXPECT_EQ(value2, vd2.at(i));
    }

    for (auto &el: vd1) {
        el = value2;
    }

    for (auto &el: vd2) {
        el = value1;
    }

    EXPECT_EQ(value2, vd1);
    EXPECT_EQ(value1, vd2);

    for (uint64_t i = 0; i != vd1.size(); i++) {
        EXPECT_EQ(value2, vd1.at(i));
    }

    for (uint64_t i = 0; i != vd2.size(); i++) {
        EXPECT_EQ(value1, vd2.at(i));
    }
}