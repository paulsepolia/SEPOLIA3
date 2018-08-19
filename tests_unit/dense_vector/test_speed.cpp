#include <gtest/gtest.h>
#include <cmath>
#include <chrono>
#include "../../dense_vector/vector_dense.h"

using sepolia::vector_dense;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(vd_test_speed_move_copy_constructor, declare_vectors) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        vector_dense<double> v1(dimension, value);

        EXPECT_TRUE(v1.allocated());

        vector_dense<double> v2(v1);

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        vector_dense<double> v1(dimension, value);

        EXPECT_TRUE(v1.allocated());

        vector_dense<double> v2(std::move(v1));

        EXPECT_TRUE(v1.deallocated());
        EXPECT_TRUE(v2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}

TEST(vd_test_speed_move_copy_assignment_operator, assign_to_vector) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        vector_dense<double> v1(dimension, value);
        vector_dense<double> v2;

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.deallocated());

        v2 = v1;

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        vector_dense<double> v1(dimension, value);
        vector_dense<double> v2;

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.deallocated());

        v2 = std::move(v1);

        EXPECT_TRUE(v1.deallocated());
        EXPECT_TRUE(v2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}
