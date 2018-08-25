#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_container/dense_container.h"

using sepolia::dense_container;

const uint64_t dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(dcon_allocated_deallocated, memory) {

    dense_container<double> dcon;

    EXPECT_EQ(false, dcon.allocated());
    EXPECT_EQ(true, dcon.deallocated());

    dcon.allocate(dimension);

    EXPECT_EQ(true, dcon.allocated());
    EXPECT_EQ(false, dcon.deallocated());
    EXPECT_EQ(dimension, dcon.size());

    dcon.deallocate();

    EXPECT_EQ(false, dcon.allocated());
    EXPECT_EQ(true, dcon.deallocated());
    EXPECT_EQ(0UL, dcon.size());
}

TEST(dcon_allocate_deallocate_constructor_one_argument, memory) {

    dense_container<double> dcon(dimension);

    EXPECT_TRUE(dcon.allocated());
    EXPECT_FALSE(dcon.deallocated());
    EXPECT_EQ(dimension, dcon.size());

    dcon.deallocate();

    EXPECT_FALSE(dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());
    EXPECT_EQ(0UL, dcon.size());
}

TEST(dcon_allocate_deallocate_constructor_one_argument_value, memory) {

    dense_container<double> dcon(dimension);

    dcon.set(value);

    EXPECT_TRUE(dcon.allocated());
    EXPECT_FALSE(dcon.deallocated());
    EXPECT_EQ(dcon, value);
    EXPECT_EQ(value, dcon);
    EXPECT_EQ(dimension, dcon.size());

    for (const auto &el: dcon) {

        EXPECT_EQ(value, el);
    }

    dcon.deallocate();

    EXPECT_FALSE(dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());
    EXPECT_EQ(0UL, dcon.size());
}
