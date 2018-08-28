#include <gtest/gtest.h>
#include <cmath>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const uint64_t dimension = static_cast<const uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;
const double value1 = 234.567;
const double value2 = 765.432;
const uint64_t value3 = 123456;
const uint64_t value4 = 876543;
const uint64_t index1 = 11;
const uint64_t index2 = 12;


TEST(dcon_test_add_with_number_double, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 + value1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon2(i), dcon1(i) + value1);
        EXPECT_EQ(dcon2[i], dcon1[i] + value1);
        EXPECT_EQ(dcon2[i], value1 + value);
        EXPECT_EQ(dcon1[i], value);
    }

    EXPECT_EQ(dcon2, value1 + value);
    EXPECT_EQ(dcon1, value);
    EXPECT_EQ(value1 + value, dcon2);
    EXPECT_EQ(value, dcon1);
}

TEST(dcon_test_add_with_number_uint64t, algebra) {

    dense_container<uint64_t> dcon1(dimension);
    dense_container<uint64_t> dcon2;

    dcon1.set(value3);

    dcon2 = dcon1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon2(i), dcon1(i) + value4);
        EXPECT_EQ(dcon2[i], dcon1[i] + value4);
        EXPECT_EQ(dcon2[i], value3 + value4);
        EXPECT_EQ(dcon1[i], value3);
    }

    EXPECT_EQ(dcon1, value3);
    EXPECT_EQ(dcon2, dcon1 + value4);
    EXPECT_EQ(value3, dcon1);
    EXPECT_EQ(dcon1 + value4, dcon2);
}

TEST(dcon_test_add_with_vector_double, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 + dcon2;

    EXPECT_TRUE(v3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v3[i], dcon1[i] + dcon2[i]);
        EXPECT_EQ(v3(i), dcon1(i) + dcon2(i));
    }

    EXPECT_EQ(v3, dcon1 + dcon2);
    EXPECT_EQ(dcon1 + dcon2, v3);
}

TEST(dcon_test_add_with_vector_uint64t, algebra) {

    dense_container<uint64_t> dcon1(dimension);
    dense_container<uint64_t> dcon2(dimension);
    dense_container<uint64_t> v3;

    dcon1.set(value3);
    dcon2.set(value4);

    v3 = dcon1 + dcon2;

    EXPECT_TRUE(v3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v3[i], dcon1[i] + dcon2[i]);
        EXPECT_EQ(v3(i), dcon1(i) + dcon2(i));
    }

    EXPECT_EQ(v3, dcon1 + dcon2);
    EXPECT_EQ(dcon1 + dcon2, v3);
}


TEST(dcon_test_add_with_number_return_to_same_double, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 + value1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon1(i), value + value1);
        EXPECT_EQ(dcon1[i], value + value1);
    }

    EXPECT_EQ(dcon1, value + value1);
}

TEST(dcon_test_add_with_number_return_to_same_uint64_t, algebra) {

    dense_container<uint64_t> dcon1(dimension);

    dcon1.set(value3);

    dcon1 = dcon1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon1(i), value3 + value4);
        EXPECT_EQ(dcon1[i], value3 + value4);
    }

    EXPECT_EQ(dcon1, value3 + value4);
    EXPECT_EQ(value3 + value4, dcon1);
}

TEST(dcon_test_add_with_number_return_to_same_in_parallel_double, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 + value1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon1(i), value1 + value);
        EXPECT_EQ(dcon1[i], value1 + value);
    }

    EXPECT_EQ(dcon1, value1 + value);
    EXPECT_EQ(value1 + value, dcon1);
}

// test add a vector with another vector and return to it, double case

TEST(dcon_test_add_with_vector_return_to_same_double, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 + dcon2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon1(i), value1 + value2);
        EXPECT_EQ(dcon2(i), value2);
        EXPECT_EQ(dcon1[i], value1 + value2);
        EXPECT_EQ(dcon2[i], value2);
    }

    EXPECT_EQ(dcon1, value1 + value2);
    EXPECT_EQ(dcon2, value2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;

    dcon2 = dcon1 + dcon2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon2(i), value1 + value2);
        EXPECT_EQ(dcon1(i), value1);
        EXPECT_EQ(dcon2[i], value1 + value2);
        EXPECT_EQ(dcon1[i], value1);
    }

    EXPECT_EQ(dcon2, value1 + value2);
    EXPECT_EQ(dcon1, value1);

    EXPECT_EQ(value1 + value2, dcon2);
    EXPECT_EQ(value1, dcon1);
}

TEST(dcon_test_add_with_vector_return_to_same_uint64_t, algebra) {

    dense_container<uint64_t> dcon1(dimension);
    dense_container<uint64_t> dcon2(dimension);

    dcon1.set(value3);
    dcon2.set(value4);

    dcon1 = dcon1 + dcon2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon1(i), value3 + value4);
        EXPECT_EQ(dcon2(i), value4);
        EXPECT_EQ(dcon1[i], value3 + value4);
        EXPECT_EQ(dcon2[i], value4);
    }

    EXPECT_EQ(dcon1, value3 + value4);
    EXPECT_EQ(dcon2, value4);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value3;
    dcon2 = value4;

    dcon2 = dcon1 + dcon2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon2(i), value3 + value4);
        EXPECT_EQ(dcon1(i), value3);
        EXPECT_EQ(dcon2[i], value3 + value4);
        EXPECT_EQ(dcon1[i], value3);
    }

    EXPECT_EQ(dcon2, value3 + value4);
    EXPECT_EQ(dcon1, value3);

    EXPECT_EQ(value3 + value4, dcon2);
    EXPECT_EQ(value3, dcon1);
}

TEST(dcon_test_add_with_vector_return_to_same_parallel_double, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 + dcon2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon1(i), value1 + value2);
        EXPECT_EQ(dcon2(i), value2);
        EXPECT_EQ(dcon1[i], value1 + value2);
        EXPECT_EQ(dcon2[i], value2);
    }

    EXPECT_EQ(dcon1, value1 + value2);
    EXPECT_EQ(dcon2, value2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;

    dcon2 = dcon1 + dcon2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon2(i), value1 + value2);
        EXPECT_EQ(dcon1(i), value1);
        EXPECT_EQ(dcon2[i], value1 + value2);
        EXPECT_EQ(dcon1[i], value1);
    }

    EXPECT_EQ(dcon2, value1 + value2);
    EXPECT_EQ(dcon1, value1);

    EXPECT_EQ(value1 + value2, dcon2);
    EXPECT_EQ(value1, dcon1);
}

// test subtract from a vector a number

TEST(dcon_test_subtract_a_number, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 - value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] - value1);
    EXPECT_EQ(dcon2, dcon1 - value1);
    EXPECT_EQ(dcon1 - value1, dcon2);

}

// test subtract a vector from another vector

TEST(dcon_test_subtract_with_vector, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 - dcon2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], dcon1[index1] - dcon2[index1]);
    EXPECT_EQ(v3, dcon1 - dcon2);
    EXPECT_EQ(dcon1 - dcon2, v3);
}

TEST(dcon_test_subtract_a_number_to_same, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 - value1;

    EXPECT_EQ(dcon1[index1], value - value1);
    EXPECT_EQ(dcon1[index2], value - value1);
    EXPECT_EQ(dcon1, value - value1);

}

// test subtract a vector from another vector and return to it

TEST(dcon_test_subtract_with_vector_return_to_same, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 - dcon2;

    EXPECT_EQ(dcon1[index1], value1 - value2);
    EXPECT_EQ(dcon1[index2], value1 - value2);

    EXPECT_EQ(dcon1, value1 - value2);
    EXPECT_EQ(value1 - value2, dcon1);

    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    EXPECT_EQ(dcon2, value2);
    EXPECT_EQ(value2, dcon2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;
    dcon2 = dcon1 - dcon2;

    EXPECT_EQ(dcon2[index1], value1 - value2);
    EXPECT_EQ(dcon2[index2], value1 - value2);

    EXPECT_EQ(dcon2, value1 - value2);
    EXPECT_EQ(value1 - value2, dcon2);

    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(value1, dcon1);
}

TEST(dcon_test_times_a_number, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 * value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] * value1);
    EXPECT_EQ(dcon2, dcon1 * value1);
    EXPECT_EQ(dcon1 * value1, dcon2);
}

TEST(dcon_test_times_with_vector, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 * dcon2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], dcon1[index1] * dcon2[index1]);
    EXPECT_EQ(v3, dcon1 * dcon2);
    EXPECT_EQ(dcon1 * dcon2, v3);
}

TEST(dcon_test_times_a_number_to_same, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 * value1;

    EXPECT_EQ(dcon1[index1], value * value1);
    EXPECT_EQ(dcon1[index2], value * value1);
    EXPECT_EQ(dcon1, value * value1);
    EXPECT_EQ(value * value1, dcon1);
}

TEST(dcon_test_times_a_number_to_same_in_parallel, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 * value1;

    EXPECT_EQ(dcon1[index1], value * value1);
    EXPECT_EQ(dcon1[index2], value * value1);
}

// test times a vector with another vector and return to it

TEST(dcon_test_times_a_vector_return_to_same, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 * dcon2;

    EXPECT_EQ(dcon1[index1], value1 * value2);
    EXPECT_EQ(dcon1[index2], value1 * value2);
    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;
    dcon2 = dcon1 * dcon2;

    EXPECT_EQ(dcon2[index1], value1 * value2);
    EXPECT_EQ(dcon2[index2], value1 * value2);
    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon2, value1 * value2);
    EXPECT_EQ(value1 * value2, dcon2);
    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(value1, dcon1);
}


TEST(dcon_test_divide_a_number, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 / value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] / value1);
    EXPECT_EQ(dcon2, dcon1 / value1);
    EXPECT_EQ(dcon1 / value1, dcon2);

}

TEST(dcon_test_divide_with_vector, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 / dcon2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], dcon1[index1] / dcon2[index1]);
    EXPECT_EQ(v3, dcon1 / dcon2);
    EXPECT_EQ(dcon1 / dcon2, v3);
}

TEST(dcon_test_divide_a_number_to_same, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 / value1;

    EXPECT_EQ(dcon1[index1], value / value1);
    EXPECT_EQ(dcon1[index2], value / value1);
    EXPECT_EQ(dcon1, value / value1);
    EXPECT_EQ(value / value1, dcon1);
}

TEST(dcon_test_divide_a_vector_return_to_same, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 / dcon2;

    EXPECT_EQ(dcon1[index1], value1 / value2);
    EXPECT_EQ(dcon1[index2], value1 / value2);
    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    EXPECT_EQ(dcon2, value2);
    EXPECT_EQ(dcon1, value1 / value2);

    EXPECT_EQ(value2, dcon2);
    EXPECT_EQ(value1 / value2, dcon1);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;
    dcon2 = dcon1 / dcon2;

    EXPECT_EQ(dcon2[index1], value1 / value2);
    EXPECT_EQ(dcon2[index2], value1 / value2);
    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(value1, dcon1);
    EXPECT_EQ(dcon2, value1 / value2);
    EXPECT_EQ(value1 / value2, dcon2);
}

TEST(dcon_test_add_with_number_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 + value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] + value1);
    EXPECT_EQ(dcon2(index1), dcon1(index1) + value1);
    EXPECT_EQ(dcon2, dcon1 + value1);
    EXPECT_EQ(dcon1 + value1, dcon2);
}

TEST(dcon_test_add_with_vector_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 + dcon2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], dcon1[index1] + dcon2[index1]);
    EXPECT_EQ(v3, dcon1 + dcon2);
    EXPECT_EQ(dcon1 + dcon2, v3);
}

TEST(dcon_test_add_with_number_return_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 + value1;

    EXPECT_EQ(dcon1[index1], value + value1);
    EXPECT_EQ(dcon1[index2], value + value1);

    EXPECT_EQ(dcon1, value + value1);
    EXPECT_EQ(value + value1, dcon1);
}

TEST(dcon_test_add_with_vector_return_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 + dcon2;

    EXPECT_EQ(dcon1[index1], value1 + value2);
    EXPECT_EQ(dcon1[index2], value1 + value2);
    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    EXPECT_EQ(dcon1, value1 + value2);
    EXPECT_EQ(value1 + value2, dcon1);
    EXPECT_EQ(dcon2, value2);
    EXPECT_EQ(value2, dcon2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;
    dcon2 = dcon1 + dcon2;

    EXPECT_EQ(dcon2[index1], value1 + value2);
    EXPECT_EQ(dcon2[index2], value1 + value2);
    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(value1, dcon1);

    EXPECT_EQ(dcon2, value1 + value2);
    EXPECT_EQ(value1 + value2, dcon2);
}

TEST(dcon_test_subtract_a_number_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 - value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] - value1);
    EXPECT_EQ(dcon2, dcon1 - value1);
}


TEST(dcon_test_subtract_with_vector_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 - dcon2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], dcon1[index1] - dcon2[index1]);
    EXPECT_EQ(v3, dcon1 - dcon2);
    EXPECT_EQ(dcon1 - dcon2, v3);
}

TEST(dcon_test_subtract_a_number_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 - value1;

    EXPECT_EQ(dcon1[index1], value - value1);
    EXPECT_EQ(dcon1[index2], value - value1);

    EXPECT_EQ(dcon1, value - value1);
    EXPECT_EQ(value - value1, dcon1);
}


TEST(dcon_test_subtract_with_vector_return_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 - dcon2;

    EXPECT_EQ(dcon1[index1], value1 - value2);
    EXPECT_EQ(dcon1[index2], value1 - value2);
    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);
    dcon1 = value1;
    dcon2 = value2;

    dcon2 = dcon1 - dcon2;

    EXPECT_EQ(dcon2[index1], value1 - value2);
    EXPECT_EQ(dcon2[index2], value1 - value2);
    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(dcon2, value1 - value2);
}

TEST(dcon_test_times_a_number_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 * value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] * value1);
    EXPECT_EQ(dcon2, dcon1[index1] * value1);
    EXPECT_EQ(dcon2[index1], dcon1 * value1);
    EXPECT_EQ(dcon2, dcon1 * value1);
}

TEST(dcon_test_times_with_vector_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 * dcon2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], dcon1[index1] * dcon2[index1]);
    EXPECT_EQ(v3, dcon1[index1] * dcon2[index1]);
    EXPECT_EQ(v3[index1], dcon1[index1] * dcon2);
    EXPECT_EQ(v3, dcon1 * dcon2[index1]);
    EXPECT_EQ(v3, dcon1 * dcon2);
}


TEST(dcon_test_times_a_number_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 * value1;

    EXPECT_EQ(dcon1[index1], value * value1);
    EXPECT_EQ(dcon1[index2], value * value1);
    EXPECT_EQ(dcon1, value * value1);
}

TEST(dcon_test_times_a_vector_return_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 * dcon2;

    EXPECT_EQ(dcon1[index1], value1 * value2);
    EXPECT_EQ(dcon1[index2], value1 * value2);
    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);
    dcon1 = value1;
    dcon2 = value2;

    dcon2 = dcon1 * dcon2;

    EXPECT_EQ(dcon2[index1], value1 * value2);
    EXPECT_EQ(dcon2[index2], value1 * value2);
    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon1, value1);
    EXPECT_EQ(dcon2, value1 * value2);
}

TEST(dcon_test_divide_a_number_operator, algebra) {

    dense_container<double> dcon1(dimension, value);
    dense_container<double> dcon2;

    dcon1.set(value);

    dcon2 = dcon1 / value1;

    EXPECT_EQ(dcon2[index1], dcon1[index1] / value1);
}

// test divide a vector with another vector using operator

TEST(dcon_test_divide_with_vector_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);
    dense_container<double> v3;

    dcon1.set(value1);
    dcon2.set(value2);

    v3 = dcon1 / dcon2;

    EXPECT_TRUE(v3.allocated());

    EXPECT_EQ(v3[index1], dcon1[index1] / dcon2[index1]);
    EXPECT_EQ(v3[index1], dcon1[index1] / dcon2);
    EXPECT_EQ(v3[index1], dcon1 / dcon2[index1]);
    EXPECT_EQ(v3[index1], dcon1 / dcon2);

    EXPECT_EQ(v3, dcon1[index1] / dcon2[index1]);
    EXPECT_EQ(v3, dcon1[index1] / dcon2);
    EXPECT_EQ(v3, dcon1 / dcon2[index1]);
    EXPECT_EQ(v3, dcon1 / dcon2);

}

TEST(dcon_test_divide_with_number_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dcon1 = dcon1 / value1;

    EXPECT_EQ(dcon1[index1], value / value1);
    EXPECT_EQ(dcon1[index2], value / value1);
    EXPECT_EQ(dcon1, value / value1);
}

TEST(dcon_test_divide_a_vector_return_to_same_operator, algebra) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    dcon1 = dcon1 / dcon2;

    EXPECT_EQ(dcon1[index1], value1 / value2);
    EXPECT_EQ(dcon1[index2], value1 / value2);
    EXPECT_EQ(dcon2[index1], value2);
    EXPECT_EQ(dcon2[index2], value2);

    EXPECT_EQ(dcon1, value1 / value2);
    EXPECT_EQ(dcon2, value2);

    dcon1.deallocate();
    dcon2.deallocate();
    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    dcon1 = value1;
    dcon2 = value2;
    dcon2 = dcon1 / dcon2;

    EXPECT_EQ(dcon2[index1], value1 / value2);
    EXPECT_EQ(dcon2[index2], value1 / value2);
    EXPECT_EQ(dcon1[index1], value1);
    EXPECT_EQ(dcon1[index2], value1);

    EXPECT_EQ(dcon2, value1 / value2);
    EXPECT_EQ(dcon1, value1);
}