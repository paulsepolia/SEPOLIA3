#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

const uint64_t dimension = static_cast<const uint64_t>(std::pow(10.0, 4.0));
const double value1 = 765.432;
const double value2 = 234.567;
const uint64_t index1 = 11;
const uint64_t index2 = 12;

TEST(vd_test_operator_curved_brackets, operators)
{
    sepolia::vector_dense<double> vd(dimension, value2);

    EXPECT_EQ(value2, vd(index1));
    EXPECT_EQ(value2, vd(index2));

    for (const auto & el: vd) {
        EXPECT_EQ(value2, el);
    }
}

TEST(vd_test_set_operator_square_brackets, operators)
{
    sepolia::vector_dense<double> vd(dimension, value1);

    for (const auto & el: vd) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        vd[i] = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), vd[i]);
    }
}

TEST(vd_test_set_operator_curved_brackets, operators)
{
    sepolia::vector_dense<double> vd(dimension, value1);

    for (const auto & el: vd) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        vd(i) = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), vd(i));
    }
}