#include <cmath>
#include <cstdint>
#include </opt/gtest/1.7.0/include/gtest/gtest.h>
#include "../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL(123.456);

TEST(vd_is_allocated_deallocated_allocate_deallocate, memory)
{

    sepolia::vector_dense<double> vd;

    EXPECT_EQ(vd.allocated(), false);
    EXPECT_EQ(vd.deallocated(), true);

    vd.allocate(DIM);

    EXPECT_EQ(vd.allocated(), true);
    EXPECT_EQ(vd.deallocated(), false);

    vd.deallocate();

    EXPECT_EQ(vd.allocated(), false);
    EXPECT_EQ(vd.deallocated(), true);
}

TEST(vd_allocate_deallocate_constructor_one_argument, memory)
{

    sepolia::vector_dense<double> vd(DIM);

    EXPECT_TRUE(vd.allocated());
    EXPECT_FALSE(vd.deallocated());

    vd.deallocate();

    EXPECT_FALSE(vd.allocated());
    EXPECT_TRUE(vd.deallocated());
}

TEST(vd_allocate_deallocate_constructor_two_arguments, memory)
{

    sepolia::vector_dense<double> vd(DIM, VAL);

    EXPECT_TRUE(vd.allocated());
    EXPECT_FALSE(vd.deallocated());

    vd.deallocate();

    EXPECT_FALSE(vd.allocated());
    EXPECT_TRUE(vd.deallocated());

}
