#include "/opt/gtest/1.7.0/include/gtest/gtest.h"
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

// local parameters

const uint64_t DIM_COMM(static_cast<const uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);
const double VAL_TEST1(234.567);
const double VAL_TEST2(765.432);
const uint64_t INDEX1(11);
const uint64_t INDEX2(12);

TEST(vd_test_operator_curved_brackets, operators)
{

    sepolia::vector_dense<double> v1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(VAL_TEST1, v1(INDEX1));
    EXPECT_EQ(VAL_TEST1, v1(INDEX2));

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST1, v1(i));
    }
}

// test set via operator []

TEST(vd_test_set_operator_square_brackets, operators_set)
{

    sepolia::vector_dense<double> v1(DIM_COMM, VAL_TEST2);

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        EXPECT_EQ(VAL_TEST2, v1(i));
    }

    for (uint64_t i = 0; i != DIM_COMM; i++) {
        v1(i) = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), v1(i));
    }
}
