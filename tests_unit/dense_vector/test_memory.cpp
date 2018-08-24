#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

const uint64_t dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(vd_allocated_deallocated, memory) {

    dense_vector<double> vd;

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());

    vd.allocate(dimension);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());

    vd.deallocate();

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());
    EXPECT_EQ(0UL, vd.size());
}

TEST(vd_allocate_deallocate_constructor_one_argument, memory) {

    dense_vector<double> vd(dimension);

    EXPECT_TRUE(vd.allocated());
    EXPECT_FALSE(vd.deallocated());
    EXPECT_EQ(dimension, vd.size());

    vd.deallocate();

    EXPECT_FALSE(vd.allocated());
    EXPECT_TRUE(vd.deallocated());
    EXPECT_EQ(0UL, vd.size());
}

TEST(vd_allocate_deallocate_constructor_two_arguments, memory) {

    dense_vector<double> vd(dimension);

    vd.set(value);

    EXPECT_TRUE(vd.allocated());
    EXPECT_FALSE(vd.deallocated());
    EXPECT_EQ(vd, value);
    EXPECT_EQ(value, vd);
    EXPECT_EQ(dimension, vd.size());

    for (const auto &el: vd) {

        EXPECT_EQ(value, el);
    }

    vd.deallocate();

    EXPECT_FALSE(vd.allocated());
    EXPECT_TRUE(vd.deallocated());
    EXPECT_EQ(0UL, vd.size());
}
