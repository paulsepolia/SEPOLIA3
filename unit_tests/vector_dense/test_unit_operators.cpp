#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

const uint64_t dimension = static_cast<const uint64_t>(std::pow(10.0, 4.0));
const double value1 = 765.432;
const double value2 = 234.567;
const uint64_t index1 = 11;
const uint64_t index2 = 12;

const double ERROR_M10 = std::pow(10.0, -10.0);
const double ERROR_M11 = std::pow(10.0, -11.0);
const double ERROR_M12 = std::pow(10.0, -12.0);

using sepolia::vector_dense;

TEST(vd_test_operator_curved_brackets, operators)
{
    vector_dense<double> vd(dimension, value2);

    EXPECT_EQ(value2, vd(index1));
    EXPECT_EQ(value2, vd(index2));

    for (const auto & el: vd) {
        EXPECT_EQ(value2, el);
    }
}

TEST(vd_test_set_operator_square_brackets, operators)
{
    vector_dense<double> vd(dimension, value1);

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
    vector_dense<double> vd(dimension, value1);

    for (const auto & el: vd) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        vd(i) = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), vd(i));
    }
}

TEST(vd_test_operator_plus_plus, operators) {

    vector_dense<double> v1(dimension, value1);

    ++v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + 1.0, v1(i));
    }

    v1++;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + 2.0, v1(i));
    }

    v1.deallocate();
    v1.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        v1[i] = std::sin(static_cast<double>(i));
    }

    v1++;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, v1(i), ERROR_M12);
    }

    ++v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, v1(i), ERROR_M12);
    }
}

TEST(vd_test_operator_minus_minus, operators) {

    vector_dense<double> v1(dimension, value1);

    --v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - 1.0, v1(i));
    }

    v1--;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - 2.0, v1(i));
    }

    v1.deallocate();
    v1.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        v1[i] = std::sin(static_cast<double>(i));
    }

    v1--;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, v1(i), ERROR_M12);
    }

    --v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, v1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, v1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, v1(i), ERROR_M12);
    }

}

TEST(vd_test_operator_plus_equal, operators) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v2 += v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + value2, v2(i));
        EXPECT_EQ(value1, v1(i));
    }

    v1.deallocate();
    v1.allocate(dimension);
    v1 = value1;

    v1 += v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + value1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        v1[i] = std::sin(static_cast<double>(i));
        v2[i] = std::cos(static_cast<double>(i));
    }

    v2 += v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) +
                    std::cos(static_cast<double>(i)),
                    v2(i), ERROR_M12);
    }
}

TEST(vd_test_operator_minus_equal, operators) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v2 -= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value2 - value1, v2(i));
        EXPECT_EQ(value1, v1(i));
    }

    v1.deallocate();
    v1.allocate(dimension);
    v1 = value1;

    v1 -= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - value1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        v1[i] = std::sin(static_cast<double>(i));
        v2[i] = std::cos(static_cast<double>(i));
    }

    v2 -= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) -
                    std::sin(static_cast<double>(i)),
                    v2(i), ERROR_M12);
    }

    v2 -= v2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(0, v2(i));
    }
}

TEST(vd_test_operator_times_equal, operators) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v2 *= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 * value2, v2(i));
        EXPECT_EQ(value1, v1(i));
    }

    v1.deallocate();
    v1.allocate(dimension);
    v1 = value1;

    v1 *= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 * value1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        v1[i] = std::sin(static_cast<double>(i));
        v2[i] = std::cos(static_cast<double>(i));
    }

    v2 *= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)),
                    v2(i), ERROR_M12);
    }

    v2 *= v2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)) *
                    std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)), v2(i), ERROR_M12);
    }
}

TEST(vd_test_operator_divide_equal, operators) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v2 /= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value2 / value1, v2(i));
        EXPECT_EQ(value1, v1(i));
    }

    v1.deallocate();
    v1.allocate(dimension);
    v1 = value1;

    v1 /= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 / value1, v1(i));
    }

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        v1[i] = static_cast<double>(i + 1);
        v2[i] = static_cast<double>(i + 2);
    }

    v2 /= v1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(i + 1, v1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR((i + 2.0) / (i + 1.0), v2(i), ERROR_M12);
    }

    v2 /= v2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(1.0, v2(i), ERROR_M12);
    }
}

TEST(vd_test_operator_equal, operators) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value1);

    EXPECT_EQ(v2, v1);
    EXPECT_EQ(v1, v2);
    EXPECT_TRUE(v2 == v1);
    EXPECT_TRUE(v1 == v2);

    v1 = value1;
    v2 = value2;

    EXPECT_FALSE(v2 == v1);
    EXPECT_FALSE(v1 == v2);

    EXPECT_EQ(v1, value1);
    EXPECT_EQ(v2, value2);
}

TEST(vd_test_operator_not_equal, operators) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    EXPECT_NE(v2, v1);
    EXPECT_NE(v1, v2);

    EXPECT_TRUE(v2 != v1);
    EXPECT_TRUE(v1 != v2);

    EXPECT_NE(v2, value1);
    EXPECT_NE(v1, value2);
}
