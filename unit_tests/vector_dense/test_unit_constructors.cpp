#include <cmath>
#include <cstdint>
#include "/opt/gtest/1.7.0/include/gtest/gtest.h"
#include "../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL(123.456);

TEST(constructor_with_no_arguments, constructors)
{

    sepolia::vector_dense<double> vd;

    EXPECT_EQ(vd.allocated(), false);
    EXPECT_EQ(vd.deallocated(), true);
}

TEST(constructor_with_one_argument, constructors)
{

    sepolia::vector_dense<double> vd(DIM);

    EXPECT_EQ(vd.allocated(), true);
    EXPECT_EQ(vd.deallocated(), false);
}

TEST(constructor_with_two_arguments, constructors)
{

    sepolia::vector_dense<double> vd(DIM, VAL);

    EXPECT_EQ(vd.allocated(), true);
    EXPECT_EQ(vd.deallocated(), false);
}
