#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_container/dense_container.h"

using sepolia::dense_container;

const auto dimension = static_cast<const uint64_t>(std::pow(10.0, 4.0));
const double value1 = 765.432;
const double value2 = 234.567;
const double ERROR_M10 = std::pow(10.0, -10.0);
const double ERROR_M11 = std::pow(10.0, -11.0);
const double ERROR_M12 = std::pow(10.0, -12.0);

TEST(dcon_test_operator_curved_brackets, operators) {

    dense_container<double> dcon(dimension, value1);

    for (const auto &el: dcon) {
        EXPECT_EQ(value1, el);
    }
}

TEST(dcon_test_set_operator_square_brackets, operators) {

    dense_container<double> dcon(dimension, value1);

    EXPECT_EQ(dimension, dcon.size());

    for (const auto &el: dcon) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {

        dcon[i] = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), dcon[i]);
    }
}

TEST(dcon_test_set_operator_curved_brackets, operators) {

    dense_container<double> dcon(dimension, value1);

    for (const auto &el: dcon) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {

        dcon(i) = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), dcon(i));
    }
}

TEST(dcon_test_operator_plus_plus, operators) {

    dense_container<double> dcon1(dimension, value1);

    ++dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + 1.0, dcon1(i));
    }

    dcon1++;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + 2.0, dcon1(i));
    }

    dcon1.deallocate();
    dcon1.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        dcon1[i] = std::sin(static_cast<double>(i));
    }

    dcon1++;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, dcon1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, dcon1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, dcon1(i), ERROR_M12);
    }

    ++dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, dcon1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, dcon1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, dcon1(i), ERROR_M12);
    }
}

TEST(dcon_test_operator_minus_minus, operators) {

    dense_container<double> dcon1(dimension, value1);

    --dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - 1.0, dcon1(i));
    }

    dcon1--;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - 2.0, dcon1(i));
    }

    dcon1.deallocate();
    dcon1.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        dcon1[i] = std::sin(static_cast<double>(i));
    }

    dcon1--;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, dcon1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, dcon1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, dcon1(i), ERROR_M12);
    }

    --dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, dcon1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, dcon1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, dcon1(i), ERROR_M12);
    }

}

TEST(dcon_test_operator_plus_equal, operators) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2(dimension, value2);

    dcon2 += dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + value2, dcon2(i));
        EXPECT_EQ(value1, dcon1(i));
    }

    EXPECT_EQ(value1 + value2, dcon2);
    EXPECT_EQ(value1, dcon1);

    dcon1.deallocate();
    dcon1.allocate(dimension);
    dcon1 = value1;

    dcon1 += dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + value1, dcon1(i));
    }

    EXPECT_EQ(value1 + value1, dcon1);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        dcon1[i] = std::sin(static_cast<double>(i));
        dcon2[i] = std::cos(static_cast<double>(i));
    }

    dcon2 += dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), dcon1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) +
                    std::cos(static_cast<double>(i)),
                    dcon2(i), ERROR_M12);
    }
}

TEST(dcon_test_operator_minus_equal, operators) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2(dimension, value2);

    dcon2 -= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value2 - value1, dcon2(i));
        EXPECT_EQ(value1, dcon1(i));
    }

    EXPECT_EQ(value2 - value1, dcon2);
    EXPECT_EQ(value1, dcon1);

    dcon1.deallocate();
    dcon1.allocate(dimension);
    dcon1 = value1;

    dcon1 -= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - value1, dcon1(i));
    }

    EXPECT_EQ(value1 - value1, dcon1);
    EXPECT_EQ(0.0, dcon1);

    EXPECT_EQ(dcon1, value1 - value1);
    EXPECT_EQ(dcon1, 0);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        dcon1[i] = std::sin(static_cast<double>(i));
        dcon2[i] = std::cos(static_cast<double>(i));
    }

    dcon2 -= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), dcon1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) -
                    std::sin(static_cast<double>(i)),
                    dcon2(i), ERROR_M12);
    }

    dcon2 -= dcon2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(0, dcon2(i));
    }

    EXPECT_EQ(0.0, dcon2);
    EXPECT_EQ(dcon2, 0.0);
}

TEST(dcon_test_operator_times_equal, operators) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2(dimension, value2);

    dcon2 *= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 * value2, dcon2(i));
        EXPECT_EQ(value1, dcon1(i));
    }

    EXPECT_EQ(value1 * value2, dcon2);
    EXPECT_EQ(value1, dcon1);

    EXPECT_EQ(dcon2, value1 * value2);
    EXPECT_EQ(dcon1, value1);

    dcon1.deallocate();
    dcon1.allocate(dimension);
    dcon1 = value1;

    dcon1 *= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 * value1, dcon1(i));
    }

    EXPECT_EQ(value1 * value1, dcon1);
    EXPECT_EQ(dcon1, value1 * value1);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        dcon1[i] = std::sin(static_cast<double>(i));
        dcon2[i] = std::cos(static_cast<double>(i));
    }

    dcon2 *= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), dcon1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)),
                    dcon2(i), ERROR_M12);
    }

    dcon2 *= dcon2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)) *
                    std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)), dcon2(i), ERROR_M12);
    }
}

TEST(dcon_test_operator_divide_equal, operators) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2(dimension, value2);

    dcon2 /= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value2 / value1, dcon2(i));
        EXPECT_EQ(value1, dcon1(i));
    }

    EXPECT_EQ(value2 / value1, dcon2);
    EXPECT_EQ(value1, dcon1);

    EXPECT_EQ(dcon2, value2 / value1);
    EXPECT_EQ(dcon1, value1);

    dcon1.deallocate();
    dcon1.allocate(dimension);
    dcon1 = value1;

    dcon1 /= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 / value1, dcon1(i));
    }

    EXPECT_EQ(dcon1, value1 / value1);
    EXPECT_EQ(value1 / value1, dcon1);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        dcon1[i] = static_cast<double>(i + 1);
        dcon2[i] = static_cast<double>(i + 2);
    }

    dcon2 /= dcon1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(i + 1, dcon1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR((i + 2.0) / (i + 1.0), dcon2(i), ERROR_M12);
    }

    dcon2 /= dcon2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(1.0, dcon2(i), ERROR_M12);
    }
}

TEST(dcon_test_operator_equal, operators) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2(dimension, value1);

    EXPECT_EQ(dcon2, dcon1);
    EXPECT_EQ(dcon1, dcon2);
    EXPECT_TRUE(dcon2 == dcon1);
    EXPECT_TRUE(dcon1 == dcon2);

    dcon1 = value1;
    dcon2 = value2;

    EXPECT_FALSE(dcon2 == dcon1);
    EXPECT_FALSE(dcon1 == dcon2);

    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(dcon2, value2);

    EXPECT_EQ(value1, dcon1);
    EXPECT_EQ(value2, dcon2);

}

TEST(dcon_test_operator_not_equal, operators) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2(dimension, value2);

    EXPECT_NE(dcon2, dcon1);
    EXPECT_NE(dcon1, dcon2);

    EXPECT_TRUE(dcon2 != dcon1);
    EXPECT_TRUE(dcon1 != dcon2);

    EXPECT_NE(dcon2, value1);
    EXPECT_NE(dcon1, value2);

    EXPECT_NE(value1, dcon2);
    EXPECT_NE(value2, dcon1);
}
