#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

const uint64_t rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
const uint64_t columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
const double value = 123.456;

TEST(md_allocated_deallocated, memory) {

    dense_matrix<double> md;

    EXPECT_EQ(false, md.allocated());
    EXPECT_EQ(true, md.deallocated());

    md.allocate(rows, columns);

    EXPECT_EQ(true, md.allocated());
    EXPECT_EQ(false, md.deallocated());
    EXPECT_EQ(rows * columns, md.size());

    md.deallocate();

    EXPECT_EQ(false, md.allocated());
    EXPECT_EQ(true, md.deallocated());
    EXPECT_EQ(0UL, md.size());
}

TEST(md_allocate_deallocate_constructor_one_argument, memory) {

    dense_matrix<double> md(rows, columns);

    EXPECT_TRUE(md.allocated());
    EXPECT_FALSE(md.deallocated());
    EXPECT_EQ(rows * columns, md.size());

    md.deallocate();

    EXPECT_FALSE(md.allocated());
    EXPECT_TRUE(md.deallocated());
    EXPECT_EQ(0UL, md.size());
}

TEST(md_allocate_deallocate_constructor_one_argument_value, memory) {

    dense_matrix<double> md(rows, columns);

    md = value;

    EXPECT_TRUE(md.allocated());
    EXPECT_FALSE(md.deallocated());
    EXPECT_EQ(md, value);
    EXPECT_EQ(value, md);
    EXPECT_EQ(rows * columns, md.size());

    for (const auto &el: md) {

        EXPECT_EQ(value, el);
    }

    md.deallocate();

    EXPECT_FALSE(md.allocated());
    EXPECT_TRUE(md.deallocated());
    EXPECT_EQ(0UL, md.size());
}
