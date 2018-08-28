#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const auto rows1 = static_cast<uint64_t>(std::pow(10.0, 2.0));
const auto columns1 = static_cast<uint64_t>(std::pow(10.0, 1.0));

const auto rows2 = static_cast<uint64_t>(std::pow(10.0, 2.0));
const auto columns2 = static_cast<uint64_t>(std::pow(10.0, 2.0));

const double value1 = 123.456;
const double value2 = 345.678;

TEST(md_swap_preallocated, stl) {

    dense_matrix<double> md1(rows1, columns1);
    dense_matrix<double> md2(rows2, columns2);

    md1 = value1;
    md2 = value2;

    EXPECT_EQ(value1, md1);
    EXPECT_EQ(value2, md2);

    md1.swap(md2);

    EXPECT_EQ(value1, md2);
    EXPECT_EQ(value2, md1);
}

TEST(md_swap_one_preallocated, stl) {

    dense_matrix<double> md1(rows1, columns1);
    dense_matrix<double> md2;

    md1 = value1;

    EXPECT_EQ(value1, md1);
    EXPECT_TRUE(md2.deallocated());

    md1.swap(md2);

    EXPECT_EQ(value1, md2);
    EXPECT_TRUE(md1.deallocated());
}

TEST(md_swap_same_matrix, stl) {

    dense_matrix<double> md1(rows1, columns1);

    md1 = value1;

    EXPECT_EQ(value1, md1);
    EXPECT_TRUE(md1.allocated());

    md1.swap(md1);

    EXPECT_EQ(value1, md1);
    EXPECT_TRUE(md1.allocated());
}

TEST(md_empty_preallocated_value, stl) {

    dense_matrix<double> md1(rows1, columns1);

    md1 = value1;

    EXPECT_FALSE(md1.empty());

    md1.deallocate();

    EXPECT_TRUE(md1.empty());
}

TEST(md_empty_preallocated_default_value, stl) {

    dense_matrix<double> md1(rows1, columns1);

    EXPECT_FALSE(md1.empty());

    md1.deallocate();

    EXPECT_TRUE(md1.empty());
}

TEST(md_empty_not_preallocated, stl) {

    dense_matrix<double> md1;

    EXPECT_TRUE(md1.empty());

    md1.allocate(rows1, columns1);

    EXPECT_FALSE(md1.empty());
}

TEST(md_at, stl) {

    dense_matrix<double> md1(rows1, columns1);
    dense_matrix<double> md2(rows2, columns2);

    md1 = value1;
    md2 = value2;

    EXPECT_EQ(value1, md1);
    EXPECT_EQ(value2, md2);

    for (uint64_t i = 0; i != md1.size(); i++) {
        EXPECT_EQ(value1, md1.at(i));
    }

    for (uint64_t i = 0; i != md2.size(); i++) {
        EXPECT_EQ(value2, md2.at(i));
    }

    for (auto &el: md1) {
        el = value2;
    }

    for (auto &el: md2) {
        el = value1;
    }

    EXPECT_EQ(value2, md1);
    EXPECT_EQ(value1, md2);

    for (uint64_t i = 0; i != md1.size(); i++) {
        EXPECT_EQ(value2, md1.at(i));
    }

    for (uint64_t i = 0; i != md2.size(); i++) {
        EXPECT_EQ(value1, md2.at(i));
    }
}

TEST(md_at_dual, stl) {

    dense_matrix<double> md1(rows1, columns1);
    dense_matrix<double> md2(rows2, columns2);

    md1 = value1;
    md2 = value2;

    EXPECT_EQ(value1, md1);
    EXPECT_EQ(value2, md2);

    for (uint64_t i = 0; i < md1.rows(); i++) {
        for (uint64_t j = 0; j < md1.columns(); j++) {
            EXPECT_EQ(value1, md1.at(i, j));
        }
    }

    for (uint64_t i = 0; i < md2.rows(); i++) {
        for (uint64_t j = 0; j < md2.columns(); j++) {
            EXPECT_EQ(value2, md2.at(i, j));
        }
    }

    for (auto &el: md1) {
        el = value2;
    }

    for (auto &el: md2) {
        el = value1;
    }

    EXPECT_EQ(value2, md1);
    EXPECT_EQ(value1, md2);

    for (uint64_t i = 0; i < md1.rows(); i++) {
        for (uint64_t j = 0; j < md1.columns(); j++) {
            EXPECT_EQ(value2, md1.at(i, j));
        }
    }

    for (uint64_t i = 0; i < md2.rows(); i++) {
        for (uint64_t j = 0; j < md2.columns(); j++) {
            EXPECT_EQ(value1, md2.at(i, j));
        }
    }
}