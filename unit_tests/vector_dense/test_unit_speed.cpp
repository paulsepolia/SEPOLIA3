#include "/opt/gtest/1.7.0/include/gtest/gtest.h"
#include <cmath>
#include <chrono>
#include "../../vector_dense/vector_dense.h"

using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::duration_cast;

// local parameters

const uint64_t DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL_COMM(123.456);

// test speed of move vs copy constructor

TEST(vd_test_speed_move_copy_constructor, declare_vectors)
{
    auto t1 = system_clock::now();

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sepolia::vector_dense<double> v1(DIM_COMM, VAL_COMM);

        EXPECT_TRUE(v1.allocated());

        sepolia::vector_dense<double> v2(v1);

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.allocated());
    }

    auto t2 = system_clock::now();
    auto time_span_copy = duration_cast<duration<double, std::milli>>(t2 - t1);

    t1 = system_clock::now();

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sepolia::vector_dense<double> v1(DIM_COMM, VAL_COMM);

        EXPECT_TRUE(v1.allocated());

        sepolia::vector_dense<double> v2(std::move(v1));

        EXPECT_TRUE(v1.deallocated());
        EXPECT_TRUE(v2.allocated());
    }

    t2 = system_clock::now();
    auto time_span_move = duration_cast<duration<double, std::milli>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}

// test speed of move vs copy assignment constructor

TEST(vd_test_speed_move_copy_assignment_operator, assign_to_vector)
{
    auto t1 = system_clock::now();

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sepolia::vector_dense<double> v1(DIM_COMM, VAL_COMM);
        sepolia::vector_dense<double> v2;

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.deallocated());

        v2 = v1;

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.allocated());
    }

    auto t2 = system_clock::now();
    auto time_span_copy = duration_cast<duration<double, std::milli>>(t2 - t1);

    t1 = system_clock::now();

    for (uint64_t i = 0; i != DIM_COMM; i++) {

        sepolia::vector_dense<double> v1(DIM_COMM, VAL_COMM);
        sepolia::vector_dense<double> v2;

        EXPECT_TRUE(v1.allocated());
        EXPECT_TRUE(v2.deallocated());

        v2 = std::move(v1);

        EXPECT_TRUE(v1.deallocated());
        EXPECT_TRUE(v2.allocated());
    }

    t2 = system_clock::now();
    auto time_span_move = duration_cast<duration<double, std::milli>>(t2 - t1);

    EXPECT_GE(time_span_copy.count(), time_span_move.count());
}
