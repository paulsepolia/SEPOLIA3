#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

const uint64_t dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(constructor_with_no_arguments, constructors)
{
    sepolia::vector_dense<double> vd;

    EXPECT_EQ(false, vd.allocated());
    EXPECT_EQ(true, vd.deallocated());
}

TEST(constructor_with_one_argument, constructors)
{
    sepolia::vector_dense<double> vd(dimension);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());
}

TEST(constructor_with_two_arguments, constructors)
{
    sepolia::vector_dense<double> vd(dimension, value);

    EXPECT_EQ(true, vd.allocated());
    EXPECT_EQ(false, vd.deallocated());
    EXPECT_EQ(dimension, vd.size());

    for(const auto & el: vd) {
        EXPECT_EQ(value, el);
    }
}
