#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

const uint64_t dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(vd_allocated_deallocated, memory)
{
    vector_dense<double> vd;

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());

    vd.allocate(dimension);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());

    vd.deallocate();

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());
}

TEST(vd_allocate_deallocate_constructor_one_argument, memory)
{
    vector_dense<double> vd(dimension);

    EXPECT_TRUE(vd.allocated());
    EXPECT_FALSE(vd.deallocated());

    vd.deallocate();

    EXPECT_FALSE(vd.allocated());
    EXPECT_TRUE(vd.deallocated());
}

TEST(vd_allocate_deallocate_constructor_two_arguments, memory)
{
    vector_dense<double> vd(dimension, value);

    EXPECT_TRUE(vd.allocated());
    EXPECT_FALSE(vd.deallocated());

    for(const auto & el: vd) {

        EXPECT_EQ(value, el);
    }

    vd.deallocate();

    EXPECT_FALSE(vd.allocated());
    EXPECT_TRUE(vd.deallocated());
}
