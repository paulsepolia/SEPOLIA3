#include <gtest/gtest.h>
#include <cmath>
#include <chrono>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;

TEST(dcon_test_speed_move_copy_constructor, declare_vectors) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_container<double> dcon1(dimension);

        dcon1.set(value);

        EXPECT_TRUE(dcon1.allocated());

        dense_container<double> dcon2(dcon1);

        EXPECT_TRUE(dcon1.allocated());
        EXPECT_TRUE(dcon2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_container<double> dcon1(dimension);

        dcon1.set(value);

        EXPECT_TRUE(dcon1.allocated());

        dense_container<double> dcon2(std::move(dcon1));

        EXPECT_TRUE(dcon1.deallocated());
        EXPECT_TRUE(dcon2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}

TEST(dcon_test_speed_move_copy_assignment_operator, assign_to_vector) {

    auto t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2;

        dcon1.set(value);

        EXPECT_TRUE(dcon1.allocated());
        EXPECT_TRUE(dcon2.deallocated());

        dcon2 = dcon1;

        EXPECT_TRUE(dcon1.allocated());
        EXPECT_TRUE(dcon2.allocated());
    }

    auto t2 = std::chrono::system_clock::now();
    auto time_span_copy = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    t1 = std::chrono::system_clock::now();

    for (uint64_t i = 0; i != dimension; i++) {

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2;

        dcon1.set(value);

        EXPECT_TRUE(dcon1.allocated());
        EXPECT_TRUE(dcon2.deallocated());

        dcon2 = std::move(dcon1);

        EXPECT_TRUE(dcon1.deallocated());
        EXPECT_TRUE(dcon2.allocated());
    }

    t2 = std::chrono::system_clock::now();
    auto time_span_move = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}
