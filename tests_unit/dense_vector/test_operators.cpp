#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const auto dimension = static_cast<const uint64_t>(std::pow(10.0, 4.0));
const double value1 = 765.432;
const double value2 = 234.567;
const double ERROR_M10 = std::pow(10.0, -10.0);
const double ERROR_M11 = std::pow(10.0, -11.0);
const double ERROR_M12 = std::pow(10.0, -12.0);

TEST(vd_test_operator_curved_brackets, operators) {

    dense_vector<double> vd(dimension);

    vd = value1;

    for (const auto &el: vd) {
        EXPECT_EQ(value1, el);
    }
}

TEST(vd_test_set_operator_square_brackets, operators) {

    dense_vector<double> vd(dimension);

    vd = value1;

    EXPECT_EQ(dimension, vd.size());

    for (const auto &el: vd) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {

        vd[i] = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), vd[i]);
    }
}

TEST(vd_test_set_operator_curved_brackets, operators) {

    dense_vector<double> vd(dimension);

    vd = value1;

    for (const auto &el: vd) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != dimension; i++) {

        vd(i) = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), vd(i));
    }
}

TEST(vd_test_operator_plus_plus, operators) {

    dense_vector<double> vd1(dimension);

    vd1 = value1;

    ++vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + 1.0, vd1(i));
    }

    vd1++;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + 2.0, vd1(i));
    }

    vd1.deallocate();
    vd1.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        vd1[i] = std::sin(static_cast<double>(i));
    }

    vd1++;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, vd1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, vd1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, vd1(i), ERROR_M12);
    }

    ++vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, vd1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, vd1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, vd1(i), ERROR_M12);
    }
}

TEST(vd_test_operator_minus_minus, operators) {

    dense_vector<double> vd1(dimension);

    vd1 = value1;

    --vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - 1.0, vd1(i));
    }

    vd1--;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - 2.0, vd1(i));
    }

    vd1.deallocate();
    vd1.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        vd1[i] = std::sin(static_cast<double>(i));
    }

    vd1--;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, vd1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, vd1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, vd1(i), ERROR_M12);
    }

    --vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, vd1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, vd1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, vd1(i), ERROR_M12);
    }

}

TEST(vd_test_operator_plus_equal, operators) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;

    vd2 += vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + value2, vd2(i));
        EXPECT_EQ(value1, vd1(i));
    }

    EXPECT_EQ(value1 + value2, vd2);
    EXPECT_EQ(value1, vd1);

    vd1.deallocate();
    vd1.allocate(dimension);
    vd1 = value1;

    vd1 += vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 + value1, vd1(i));
    }

    EXPECT_EQ(value1 + value1, vd1);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        vd1[i] = std::sin(static_cast<double>(i));
        vd2[i] = std::cos(static_cast<double>(i));
    }

    vd2 += vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), vd1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) +
                    std::cos(static_cast<double>(i)),
                    vd2(i), ERROR_M12);
    }
}

TEST(vd_test_operator_minus_equal, operators) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;

    vd2 -= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value2 - value1, vd2(i));
        EXPECT_EQ(value1, vd1(i));
    }

    EXPECT_EQ(value2 - value1, vd2);
    EXPECT_EQ(value1, vd1);

    vd1.deallocate();
    vd1.allocate(dimension);
    vd1 = value1;

    vd1 -= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 - value1, vd1(i));
    }

    EXPECT_EQ(value1 - value1, vd1);
    EXPECT_EQ(0.0, vd1);

    EXPECT_EQ(vd1, value1 - value1);
    EXPECT_EQ(vd1, 0);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        vd1[i] = std::sin(static_cast<double>(i));
        vd2[i] = std::cos(static_cast<double>(i));
    }

    vd2 -= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), vd1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) -
                    std::sin(static_cast<double>(i)),
                    vd2(i), ERROR_M12);
    }

    vd2 -= vd2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(0, vd2(i));
    }

    EXPECT_EQ(0.0, vd2);
    EXPECT_EQ(vd2, 0.0);
}

TEST(vd_test_operator_times_equal, operators) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;

    vd2 *= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 * value2, vd2(i));
        EXPECT_EQ(value1, vd1(i));
    }

    EXPECT_EQ(value1 * value2, vd2);
    EXPECT_EQ(value1, vd1);

    EXPECT_EQ(vd2, value1 * value2);
    EXPECT_EQ(vd1, value1);

    vd1.deallocate();
    vd1.allocate(dimension);
    vd1 = value1;

    vd1 *= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 * value1, vd1(i));
    }

    EXPECT_EQ(value1 * value1, vd1);
    EXPECT_EQ(vd1, value1 * value1);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        vd1[i] = std::sin(static_cast<double>(i));
        vd2[i] = std::cos(static_cast<double>(i));
    }

    vd2 *= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), vd1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)),
                    vd2(i), ERROR_M12);
    }

    vd2 *= vd2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)) *
                    std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)), vd2(i), ERROR_M12);
    }
}

TEST(vd_test_operator_divide_equal, operators) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;

    vd2 /= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value2 / value1, vd2(i));
        EXPECT_EQ(value1, vd1(i));
    }

    EXPECT_EQ(value2 / value1, vd2);
    EXPECT_EQ(value1, vd1);

    EXPECT_EQ(vd2, value2 / value1);
    EXPECT_EQ(vd1, value1);

    vd1.deallocate();
    vd1.allocate(dimension);
    vd1 = value1;

    vd1 /= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_EQ(value1 / value1, vd1(i));
    }

    EXPECT_EQ(vd1, value1 / value1);
    EXPECT_EQ(value1 / value1, vd1);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i != dimension; i++) {
        vd1[i] = static_cast<double>(i + 1);
        vd2[i] = static_cast<double>(i + 2);
    }

    vd2 /= vd1;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(i + 1, vd1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR((i + 2.0) / (i + 1.0), vd2(i), ERROR_M12);
    }

    vd2 /= vd2;

    for (uint64_t i = 0; i != dimension; i++) {
        EXPECT_NEAR(1.0, vd2(i), ERROR_M12);
    }
}

TEST(vd_test_operator_equal, operators) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value1;

    EXPECT_EQ(vd2, vd1);
    EXPECT_EQ(vd1, vd2);
    EXPECT_TRUE(vd2 == vd1);
    EXPECT_TRUE(vd1 == vd2);

    vd1 = value1;
    vd2 = value2;

    EXPECT_FALSE(vd2 == vd1);
    EXPECT_FALSE(vd1 == vd2);

    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(vd2, value2);

    EXPECT_EQ(value1, vd1);
    EXPECT_EQ(value2, vd2);

}

TEST(vd_test_operator_not_equal, operators) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;

    EXPECT_NE(vd2, vd1);
    EXPECT_NE(vd1, vd2);

    EXPECT_TRUE(vd2 != vd1);
    EXPECT_TRUE(vd1 != vd2);

    EXPECT_NE(vd2, value1);
    EXPECT_NE(vd1, value2);

    EXPECT_NE(value1, vd2);
    EXPECT_NE(value2, vd1);
}
