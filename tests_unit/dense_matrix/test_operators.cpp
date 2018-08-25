#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

const auto rows = static_cast<const uint64_t>(std::pow(10.0, 2.0));
const auto columns = static_cast<const uint64_t>(std::pow(10.0, 2.0));
const double value1 = 765.432;
const double value2 = 234.567;
const double ERROR_M10 = std::pow(10.0, -10.0);
const double ERROR_M11 = std::pow(10.0, -11.0);
const double ERROR_M12 = std::pow(10.0, -12.0);

TEST(md_test_operator_curved_brackets, operators) {

    dense_matrix<double> md(rows, columns);

    md = value1;

    for (const auto &el: md) {
        EXPECT_EQ(value1, el);
    }
}

TEST(md_test_operator_curved_brackets_dual, operators) {

    dense_matrix<double> md(rows, columns);

    md = value1;

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            EXPECT_EQ(value1, md(i, j));
        }
    }

    EXPECT_EQ(md, md(1, 1));
    EXPECT_EQ(md(2, 1), md);
}

TEST(md_test_operator_curved_brackets_dual_at, operators) {

    dense_matrix<double> md(rows, columns);

    md = value1;

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            EXPECT_EQ(value1, md.at(i, j));
        }
    }

    EXPECT_EQ(md, md.at(1, 1));
    EXPECT_EQ(md.at(2, 1), md);
}

TEST(md_test_set_operator_square_brackets, operators) {

    dense_matrix<double> md(rows, columns);

    md = value1;

    EXPECT_EQ(rows * columns, md.size());

    for (const auto &el: md) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != rows * columns; i++) {

        md[i] = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), md[i]);
    }
}

TEST(md_test_set_operator_curved_brackets, operators) {

    dense_matrix<double> md(rows, columns);

    md = value1;

    for (const auto &el: md) {
        EXPECT_EQ(value1, el);
    }

    for (uint64_t i = 0; i != rows * columns; i++) {

        md(i) = static_cast<double>(i);
        EXPECT_EQ(static_cast<double>(i), md(i));
    }
}

TEST(md_test_operator_plus_plus, operators) {

    dense_matrix<double> md1(rows, columns);

    md1 = value1;

    ++md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 + 1.0, md1(i));
    }

    md1++;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 + 2.0, md1(i));
    }

    md1.deallocate();
    md1.allocate(rows, columns);

    for (uint64_t i = 0; i != rows * columns; i++) {
        md1[i] = std::sin(static_cast<double>(i));
    }

    md1++;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, md1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, md1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 1.0, md1(i), ERROR_M12);
    }

    ++md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, md1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, md1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) + 2.0, md1(i), ERROR_M12);
    }
}

TEST(md_test_operator_minus_minus, operators) {

    dense_matrix<double> md1(rows, columns);

    md1 = value1;

    --md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 - 1.0, md1(i));
    }

    md1--;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 - 2.0, md1(i));
    }

    md1.deallocate();
    md1.allocate(rows, columns);

    for (uint64_t i = 0; i != rows * columns; i++) {
        md1[i] = std::sin(static_cast<double>(i));
    }

    md1--;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, md1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, md1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 1.0, md1(i), ERROR_M12);
    }

    --md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, md1(i), ERROR_M10);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, md1(i), ERROR_M11);
        EXPECT_NEAR(std::sin(static_cast<double>(i)) - 2.0, md1(i), ERROR_M12);
    }

}

TEST(md_test_operator_plus_equal, operators) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md2 += md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 + value2, md2(i));
        EXPECT_EQ(value1, md1(i));
    }

    EXPECT_EQ(value1 + value2, md2);
    EXPECT_EQ(value1, md1);

    md1.deallocate();
    md1.allocate(rows, columns);
    md1 = value1;

    md1 += md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 + value1, md1(i));
    }

    EXPECT_EQ(value1 + value1, md1);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i != rows * columns; i++) {
        md1[i] = std::sin(static_cast<double>(i));
        md2[i] = std::cos(static_cast<double>(i));
    }

    md2 += md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), md1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)) +
                    std::cos(static_cast<double>(i)),
                    md2(i), ERROR_M12);
    }
}

TEST(md_test_operator_minus_equal, operators) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md2 -= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value2 - value1, md2(i));
        EXPECT_EQ(value1, md1(i));
    }

    EXPECT_EQ(value2 - value1, md2);
    EXPECT_EQ(value1, md1);

    md1.deallocate();
    md1.allocate(rows, columns);
    md1 = value1;

    md1 -= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 - value1, md1(i));
    }

    EXPECT_EQ(value1 - value1, md1);
    EXPECT_EQ(0.0, md1);

    EXPECT_EQ(md1, value1 - value1);
    EXPECT_EQ(md1, 0);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i != rows * columns; i++) {
        md1[i] = std::sin(static_cast<double>(i));
        md2[i] = std::cos(static_cast<double>(i));
    }

    md2 -= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), md1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) -
                    std::sin(static_cast<double>(i)),
                    md2(i), ERROR_M12);
    }

    md2 -= md2;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(0, md2(i));
    }

    EXPECT_EQ(0.0, md2);
    EXPECT_EQ(md2, 0.0);
}

TEST(md_test_operator_times_equal, operators) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md2 *= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 * value2, md2(i));
        EXPECT_EQ(value1, md1(i));
    }

    EXPECT_EQ(value1 * value2, md2);
    EXPECT_EQ(value1, md1);

    EXPECT_EQ(md2, value1 * value2);
    EXPECT_EQ(md1, value1);

    md1.deallocate();
    md1.allocate(rows, columns);
    md1 = value1;

    md1 *= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 * value1, md1(i));
    }

    EXPECT_EQ(value1 * value1, md1);
    EXPECT_EQ(md1, value1 * value1);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i != rows * columns; i++) {
        md1[i] = std::sin(static_cast<double>(i));
        md2[i] = std::cos(static_cast<double>(i));
    }

    md2 *= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::sin(static_cast<double>(i)), md1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)),
                    md2(i), ERROR_M12);
    }

    md2 *= md2;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)) *
                    std::cos(static_cast<double>(i)) *
                    std::sin(static_cast<double>(i)), md2(i), ERROR_M12);
    }
}

TEST(md_test_operator_divide_equal, operators) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md2 /= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value2 / value1, md2(i));
        EXPECT_EQ(value1, md1(i));
    }

    EXPECT_EQ(value2 / value1, md2);
    EXPECT_EQ(value1, md1);

    EXPECT_EQ(md2, value2 / value1);
    EXPECT_EQ(md1, value1);

    md1.deallocate();
    md1.allocate(rows, columns);
    md1 = value1;

    md1 /= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_EQ(value1 / value1, md1(i));
    }

    EXPECT_EQ(md1, value1 / value1);
    EXPECT_EQ(value1 / value1, md1);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i != rows * columns; i++) {
        md1[i] = static_cast<double>(i + 1);
        md2[i] = static_cast<double>(i + 2);
    }

    md2 /= md1;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(i + 1, md1(i), ERROR_M12);
    }

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR((i + 2.0) / (i + 1.0), md2(i), ERROR_M12);
    }

    md2 /= md2;

    for (uint64_t i = 0; i != rows * columns; i++) {
        EXPECT_NEAR(1.0, md2(i), ERROR_M12);
    }
}

TEST(md_test_operator_equal, operators) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value1;

    EXPECT_EQ(md2, md1);
    EXPECT_EQ(md1, md2);
    EXPECT_TRUE(md2 == md1);
    EXPECT_TRUE(md1 == md2);

    md1 = value1;
    md2 = value2;

    EXPECT_FALSE(md2 == md1);
    EXPECT_FALSE(md1 == md2);

    EXPECT_EQ(md1, value1);
    EXPECT_EQ(md2, value2);

    EXPECT_EQ(value1, md1);
    EXPECT_EQ(value2, md2);

}

TEST(md_test_operator_not_equal, operators) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    EXPECT_NE(md2, md1);
    EXPECT_NE(md1, md2);

    EXPECT_TRUE(md2 != md1);
    EXPECT_TRUE(md1 != md2);

    EXPECT_NE(md2, value1);
    EXPECT_NE(md1, value2);

    EXPECT_NE(value1, md2);
    EXPECT_NE(value2, md1);
}
