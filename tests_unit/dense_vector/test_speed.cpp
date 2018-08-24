#include <gtest/gtest.h>
#include <cmath>
#include <chrono>
#include "../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(vd_test_speed_move_copy_constructor, declare_vectors) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_vector<double> vd1(dimension);

        vd1.set(value);

        EXPECT_TRUE(vd1.allocated());

        dense_vector<double> vd2(vd1);

        EXPECT_TRUE(vd1.allocated());
        EXPECT_TRUE(vd2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_vector<double> vd1(dimension);

        vd1.set(value);

        EXPECT_TRUE(vd1.allocated());

        dense_vector<double> vd2(std::move(vd1));

        EXPECT_TRUE(vd1.deallocated());
        EXPECT_TRUE(vd2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}

TEST(vd_test_speed_move_copy_assignment_operator, assign_to_vector) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2;

        vd1.set(value);

        EXPECT_TRUE(vd1.allocated());
        EXPECT_TRUE(vd2.deallocated());

        vd2 = vd1;

        EXPECT_TRUE(vd1.allocated());
        EXPECT_TRUE(vd2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2;

        vd1.set(value);

        EXPECT_TRUE(vd1.allocated());
        EXPECT_TRUE(vd2.deallocated());

        vd2 = std::move(vd1);

        EXPECT_TRUE(vd1.deallocated());
        EXPECT_TRUE(vd2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}
