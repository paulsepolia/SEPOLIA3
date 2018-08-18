#include "/opt/gtest/1.7.0/include/gtest/gtest.h"
#include <cmath>
#include <cstdint>
#include "../../vector_dense/vector_dense.h"

// local parameters

const auto DIM_COMM(static_cast<uint64_t>(std::pow(10.0, 4.0)));
const double VAL_TEST1(123.456);
const uint64_t VAL_TEST2(123456);
const int64_t VAL_TEST3(123456);

TEST(vd_set_element_via_constructor_and_get_it_double, set_get)
{
    sepolia::vector_dense<double> vd(DIM_COMM, VAL_TEST1);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(VAL_TEST1, vd(i));
    }
}

TEST(vd_set_element_via_constructor_and_get_it_uint64_t, set_get)
{
    sepolia::vector_dense<uint64_t> vd(DIM_COMM, VAL_TEST2);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(VAL_TEST2, vd(i));
    }
}

TEST(vd_set_element_via_constructor_and_get_it_int64_t, set_get)
{
    sepolia::vector_dense<int64_t> vd(DIM_COMM, VAL_TEST3);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(VAL_TEST3, vd(i));
    }
}

TEST(vd_set_dimension_via_constructor_and_get_it_double, set_get)
{
    sepolia::vector_dense<double> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

TEST(vd_set_dimension_via_constructor_and_get_it_uint64_t, set_get)
{

    sepolia::vector_dense<uint64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

TEST(vd_set_dimension_via_constructor_and_get_it_int64_t, set_get)
{

    sepolia::vector_dense<int64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

TEST(vd_set_dimension_via_allocate_and_get_it_double, set_get)
{

    sepolia::vector_dense<double> vd;
    vd.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

TEST(vd_set_dimension_via_allocate_and_get_it_uint64_t, set_get)
{

    sepolia::vector_dense<uint64_t> vd;
    vd.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

TEST(vd_set_dimension_via_allocate_and_get_it_int64_t, set_get)
{

    sepolia::vector_dense<int64_t> vd;
    vd.allocate(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());
}

TEST(vd_set_element_and_get_it_double, set_get)
{

    sepolia::vector_dense<double> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd(i), static_cast<double>(i));
    }
}

TEST(vd_set_element_and_get_it_uint64_t, set_get)
{

    sepolia::vector_dense<uint64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd(i) = i;
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd(i), i);
    }
}

TEST(vd_set_element_and_get_it_int64_t, set_get)
{

    sepolia::vector_dense<int64_t> vd(DIM_COMM);

    EXPECT_EQ(DIM_COMM, vd.size());

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        vd(i) = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd(i), static_cast<int64_t>(i));
    }
}

TEST(vd_set_vector_to_another_using_assignment_operator_double, set_get)
{

    sepolia::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);
    sepolia::vector_dense<double> vd2;

    EXPECT_EQ(DIM_COMM, vd1.size());

    vd2 = vd1;

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
    }

    EXPECT_EQ(vd1.size(), DIM_COMM);
}

TEST(vd_set_vector_via_copy_constructor_double, set_get)
{

    sepolia::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<double> vd2(vd1);

    EXPECT_EQ(vd1.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1(i), VAL_TEST1);
        EXPECT_EQ(vd2(i), VAL_TEST1);
    }
}

TEST(vd_set_vector_via_copy_constructor_uint64_t, set_get)
{

    sepolia::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<uint64_t> vd2(vd1);

    EXPECT_EQ(vd1.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1(i), VAL_TEST2);
        EXPECT_EQ(vd2(i), VAL_TEST2);
    }
}

TEST(vd_set_vector_via_copy_constructor_int64_t, set_get)
{

    sepolia::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<int64_t> vd2(vd1);

    EXPECT_EQ(vd1.size(), DIM_COMM);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd1(i), VAL_TEST3);
        EXPECT_EQ(vd2(i), VAL_TEST3);
    }
}

TEST(vd_set_vector_via_move_constructor_double, set_get)
{

    sepolia::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<double> vd2(std::move(vd1));

    EXPECT_EQ(vd1.allocated(), false);
    EXPECT_EQ(vd1.deallocated(), true);
    EXPECT_EQ(vd1.size(), 0UL);
    EXPECT_EQ(vd2.allocated(), true);
    EXPECT_EQ(vd2.deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2(i), VAL_TEST1);
    }
}

TEST(vd_set_vector_via_move_constructor_uint64_t, set_get)
{

    sepolia::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<uint64_t> vd2(std::move(vd1));

    EXPECT_EQ(vd1.allocated(), false);
    EXPECT_EQ(vd1.deallocated(), true);
    EXPECT_EQ(vd1.size(), 0UL);
    EXPECT_EQ(vd2.allocated(), true);
    EXPECT_EQ(vd2.deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2(i), VAL_TEST2);
    }
}

TEST(vd_set_vector_via_move_constructor_int64_t, set_get)
{

    sepolia::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<int64_t> vd2(std::move(vd1));

    EXPECT_EQ(vd1.allocated(), false);
    EXPECT_EQ(vd1.deallocated(), true);
    EXPECT_EQ(vd1.size(), 0UL);
    EXPECT_EQ(vd2.allocated(), true);
    EXPECT_EQ(vd2.deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2(i), VAL_TEST3);
    }
}

TEST(vd_set_vector_via_move_assignment_operator_double, set_get)
{

    sepolia::vector_dense<double> vd1(DIM_COMM, VAL_TEST1);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<double> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(vd1.allocated(), false);
    EXPECT_EQ(vd1.deallocated(), true);
    EXPECT_EQ(vd1.size(), 0UL);
    EXPECT_EQ(vd2.allocated(), true);
    EXPECT_EQ(vd2.deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2(i), VAL_TEST1);
    }
}

TEST(vd_set_vector_via_move_assignment_operator_uint64_t, set_get)
{

    sepolia::vector_dense<uint64_t> vd1(DIM_COMM, VAL_TEST2);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<uint64_t> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(vd1.allocated(), false);
    EXPECT_EQ(vd1.deallocated(), true);
    EXPECT_EQ(vd1.size(), 0UL);
    EXPECT_EQ(vd2.allocated(), true);
    EXPECT_EQ(vd2.deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2(i), VAL_TEST2);
    }
}

TEST(vd_set_vector_via_move_assignment_operator_int64_t, set_get)
{

    sepolia::vector_dense<int64_t> vd1(DIM_COMM, VAL_TEST3);

    EXPECT_EQ(DIM_COMM, vd1.size());

    sepolia::vector_dense<int64_t> vd2;
    vd2 = std::move(vd1);

    EXPECT_EQ(vd1.allocated(), false);
    EXPECT_EQ(vd1.deallocated(), true);
    EXPECT_EQ(vd1.size(), 0UL);
    EXPECT_EQ(vd2.allocated(), true);
    EXPECT_EQ(vd2.deallocated(), false);

    for (uint64_t i = 0; i < DIM_COMM; i++) {

        EXPECT_EQ(vd2(i), VAL_TEST3);
    }
}
