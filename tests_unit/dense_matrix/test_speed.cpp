#include <gtest/gtest.h>
#include <cmath>
#include <chrono>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
const auto dimension = rows * columns;
const double value = 123.456;

TEST(md_test_speed_move_copy_constructor, declare_matrices) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_matrix<double> md1(rows, columns);

        md1.set(value);

        EXPECT_TRUE(md1.allocated());

        dense_matrix<double> md2(md1);

        EXPECT_TRUE(md1.allocated());
        EXPECT_TRUE(md2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_matrix<double> md1(rows, columns);

        md1.set(value);

        EXPECT_TRUE(md1.allocated());

        dense_matrix<double> md2(std::move(md1));

        EXPECT_TRUE(md1.deallocated());
        EXPECT_TRUE(md2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}

TEST(md_test_speed_move_copy_assignment_operator, assign_to_matrix) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2;

        md1.set(value);

        EXPECT_TRUE(md1.allocated());
        EXPECT_TRUE(md2.deallocated());

        md2 = md1;

        EXPECT_TRUE(md1.allocated());
        EXPECT_TRUE(md2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_matrix<double> md1(rows, columns);
        dense_matrix<double> md2;

        md1.set(value);

        EXPECT_TRUE(md1.allocated());
        EXPECT_TRUE(md2.deallocated());

        md2 = std::move(md1);

        EXPECT_TRUE(md1.deallocated());
        EXPECT_TRUE(md2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}
