#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

using sepolia::vector_dense;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value1 = 123.456;
const uint64_t value2 = 123456;
const int64_t value3 = 456789;

TEST(vd_set_element_via_constructor_and_get_it_double, set_get)
{
    vector_dense<double> vd(dimension, value1);

    for (const auto & el: vd) {

        EXPECT_EQ(value1, el);
    }
}

TEST(vd_set_element_via_constructor_and_get_it_uint64_t, set_get)
{
    vector_dense<uint64_t> vd(dimension, value2);

    for (const auto & el: vd) {

        EXPECT_EQ(value2, el);
    }
}

TEST(vd_set_element_via_constructor_and_get_it_int64_t, set_get)
{
    vector_dense<int64_t> vd(dimension, value3);

    for (const auto & el: vd) {

        EXPECT_EQ(value3, el);
    }
}

TEST(vd_set_dimension_via_constructor_and_get_it_double, set_get)
{
    vector_dense<double> vd(dimension);

    EXPECT_EQ(dimension, vd.size());
}

TEST(vd_set_dimension_via_constructor_and_get_it_uint64_t, set_get)
{
    vector_dense<uint64_t> vd(dimension);

    EXPECT_EQ(dimension, vd.size());
}

TEST(vd_set_dimension_via_constructor_and_get_it_int64_t, set_get)
{
    vector_dense<int64_t> vd(dimension);

    EXPECT_EQ(dimension, vd.size());
}

TEST(vd_set_dimension_via_allocate_and_get_it_double, set_get)
{
    vector_dense<double> vd;
    vd.allocate(dimension);

    EXPECT_EQ(dimension, vd.size());
}

TEST(vd_set_dimension_via_allocate_and_get_it_uint64_t, set_get)
{
    vector_dense<uint64_t> vd;
    vd.allocate(dimension);

    EXPECT_EQ(dimension, vd.size());
}

TEST(vd_set_dimension_via_allocate_and_get_it_int64_t, set_get)
{
    vector_dense<int64_t> vd;
    vd.allocate(dimension);

    EXPECT_EQ(dimension, vd.size());
}

TEST(vd_set_element_and_get_it_double, set_get)
{
    vector_dense<double> vd(dimension);

    EXPECT_EQ(dimension, vd.size());

    for (uint64_t i = 0; i < dimension; i++) {

        vd(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd(i), static_cast<double>(i));
    }
}

TEST(vd_set_element_and_get_it_uint64_t, set_get)
{
    vector_dense<uint64_t> vd(dimension);

    EXPECT_EQ(dimension, vd.size());

    // curved brackets

    for (uint64_t i = 0; i < dimension; i++) {

        vd(i) = i;
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(i, vd(i));
    }

    // square brackets

    for (uint64_t i = 0; i < dimension; i++) {

        vd[i] = i;
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(i, vd[i]);
    }
}

TEST(vd_set_element_and_get_it_int64_t, set_get)
{
    vector_dense<int64_t> vd(dimension);

    EXPECT_EQ(dimension, vd.size());

    // curved brackets

    for (uint64_t i = 0; i < dimension; i++) {

        vd(i) = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(static_cast<int64_t>(i), vd(i));
    }

    // square brackets

    for (uint64_t i = 0; i < dimension; i++) {

        vd[i] = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(static_cast<int64_t>(i), vd[i]);
    }
}

TEST(vd_set_vector_to_another_using_assignment_operator_double, set_get)
{
    vector_dense<double> vd1(dimension, value1);
    vector_dense<double> vd2;

    EXPECT_EQ(dimension, vd1.size());

    for (const auto & el: vd1) {

        EXPECT_EQ(value1, el);
    }

    vd2 = vd1;

    EXPECT_EQ(dimension, vd2.size());

    for (const auto & el: vd2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_EQ(vd1, vd2);

}

TEST(vd_set_vector_via_copy_constructor_double, set_get)
{
    vector_dense<double> vd1(dimension, value1);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2(vd1);

    EXPECT_EQ(dimension, vd1.size());

    for (const auto & el: vd1) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_EQ(dimension, vd2.size());

    for (const auto & el: vd2) {

        EXPECT_EQ(value1, el);
    }
}

TEST(vd_set_vector_via_copy_constructor_uint64_t, set_get)
{
    vector_dense<uint64_t> vd1(dimension, value2);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<uint64_t> vd2(vd1);

    EXPECT_EQ(dimension, vd1.size());

    for (const auto & el: vd1) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_EQ(dimension, vd2.size());

    for (const auto & el: vd2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_set_vector_via_copy_constructor_int64_t, set_get)
{
    vector_dense<int64_t> vd1(dimension, value3);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<int64_t> vd2(vd1);

    EXPECT_EQ(dimension, vd1.size());

    for (const auto & el: vd1) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_EQ(dimension, vd2.size());

    for (const auto & el: vd2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_set_vector_via_move_constructor_double, set_get)
{
    vector_dense<double> vd1(dimension, value1);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2(std::move(vd1));

    EXPECT_EQ(false, vd1.allocated());
    EXPECT_EQ(true, vd1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), vd1.size());
    EXPECT_EQ(true, vd2.allocated());
    EXPECT_EQ(false, vd2.deallocated());

    for(const auto & el: vd2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_NE(vd1, vd2);
}

TEST(vd_set_vector_via_move_constructor_uint64_t, set_get)
{
    vector_dense<double> vd1(dimension, value2);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2(std::move(vd1));

    EXPECT_EQ(false, vd1.allocated());
    EXPECT_EQ(true, vd1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), vd1.size());
    EXPECT_EQ(true, vd2.allocated());
    EXPECT_EQ(false, vd2.deallocated());

    for(const auto & el: vd2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_NE(vd1, vd2);
}

TEST(vd_set_vector_via_move_constructor_int64_t, set_get)
{
    vector_dense<double> vd1(dimension, value3);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2(std::move(vd1));

    EXPECT_EQ(false, vd1.allocated());
    EXPECT_EQ(true, vd1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), vd1.size());
    EXPECT_EQ(true, vd2.allocated());
    EXPECT_EQ(false, vd2.deallocated());

    for(const auto & el: vd2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_NE(vd1, vd2);
}

TEST(vd_set_vector_via_move_assignment_operator_double, set_get)
{
    vector_dense<double> vd1(dimension, value1);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(false, vd1.allocated());
    EXPECT_EQ(true, vd1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), vd1.size());
    EXPECT_EQ(true, vd2.allocated());
    EXPECT_EQ(false, vd2.deallocated());

    for (const auto & el: vd2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_NE(vd1, vd2);
}

TEST(vd_set_vector_via_move_assignment_operator_uint64_t, set_get)
{
    vector_dense<double> vd1(dimension, value2);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(false, vd1.allocated());
    EXPECT_EQ(true, vd1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), vd1.size());
    EXPECT_EQ(true, vd2.allocated());
    EXPECT_EQ(false, vd2.deallocated());

    for (const auto & el: vd2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_NE(vd1, vd2);
}

TEST(vd_set_vector_via_move_assignment_operator_int64_t, set_get)
{
    vector_dense<double> vd1(dimension, value3);

    EXPECT_EQ(dimension, vd1.size());

    vector_dense<double> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(false, vd1.allocated());
    EXPECT_EQ(true, vd1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), vd1.size());
    EXPECT_EQ(true, vd2.allocated());
    EXPECT_EQ(false, vd2.deallocated());

    for (const auto & el: vd2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_NE(vd1, vd2);
}
