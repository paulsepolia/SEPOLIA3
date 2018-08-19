#include <gtest/gtest.h>
#include <cmath>
#include "../../dense_vector/vector_dense.h"

using sepolia::vector_dense;

const uint64_t dimension = static_cast<const uint64_t>(std::pow(10.0, 4.0));
const double value = 123.456;
const double value1 = 234.567;
const double value2 = 765.432;
const uint64_t value3 = 123456;
const uint64_t value4 = 876543;
const uint64_t index1 = 11;
const uint64_t index2 = 12;


TEST(vd_test_add_with_number_double, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 + value1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v2(i), v1(i) + value1);
        EXPECT_EQ(v2[i], v1[i] + value1);
        EXPECT_EQ(v2[i], value1 + value);
        EXPECT_EQ(v1[i], value);
    }

    EXPECT_EQ(v2, value1 + value);
    EXPECT_EQ(v1, value);
    EXPECT_EQ(value1 + value, v2);
    EXPECT_EQ(value, v1);
}

TEST(vd_test_add_with_number_uint64t, algebra) {

    vector_dense<uint64_t> v1(dimension, value3);
    vector_dense<uint64_t> v2;

    v2 = v1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v2(i), v1(i) + value4);
        EXPECT_EQ(v2[i], v1[i] + value4);
        EXPECT_EQ(v2[i], value3 + value4);
        EXPECT_EQ(v1[i], value3);
    }

    EXPECT_EQ(v1, value3);
    EXPECT_EQ(v2, v1 + value4);
    EXPECT_EQ(value3, v1);
    EXPECT_EQ(v1 + value4, v2);
}

TEST(vd_test_add_with_vector_double, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 + v2;

    EXPECT_TRUE(v3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v3[i], v1[i] + v2[i]);
        EXPECT_EQ(v3(i), v1(i) + v2(i));
    }

    EXPECT_EQ(v3, v1 + v2);
    EXPECT_EQ(v1 + v2, v3);
}

TEST(vd_test_add_with_vector_uint64t, algebra) {

    vector_dense<uint64_t> v1(dimension, value3);
    vector_dense<uint64_t> v2(dimension, value4);
    vector_dense<uint64_t> v3;

    v3 = v1 + v2;

    EXPECT_TRUE(v3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v3[i], v1[i] + v2[i]);
        EXPECT_EQ(v3(i), v1(i) + v2(i));
    }

    EXPECT_EQ(v3, v1 + v2);
    EXPECT_EQ(v1 + v2, v3);
}


TEST(vd_test_add_with_number_return_to_same_double, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 + value1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v1(i), value + value1);
        EXPECT_EQ(v1[i], value + value1);
    }

    EXPECT_EQ(v1, value + value1);
}

TEST(vd_test_add_with_number_return_to_same_uint64_t, algebra) {

    vector_dense<uint64_t> v1(dimension, value3);

    v1 = v1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v1(i), value3 + value4);
        EXPECT_EQ(v1[i], value3 + value4);
    }

    EXPECT_EQ(v1, value3 + value4);
    EXPECT_EQ(value3 + value4, v1);
}

TEST(vd_test_add_with_number_return_to_same_in_parallel_double, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 + value1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v1(i), value1 + value);
        EXPECT_EQ(v1[i], value1 + value);
    }

    EXPECT_EQ(v1, value1 + value);
    EXPECT_EQ(value1 + value, v1);
}

// test add a vector with another vector and return to it, double case

TEST(vd_test_add_with_vector_return_to_same_double, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 + v2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v1(i), value1 + value2);
        EXPECT_EQ(v2(i), value2);
        EXPECT_EQ(v1[i], value1 + value2);
        EXPECT_EQ(v2[i], value2);
    }

    EXPECT_EQ(v1, value1 + value2);
    EXPECT_EQ(v2, value2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;

    v2 = v1 + v2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v2(i), value1 + value2);
        EXPECT_EQ(v1(i), value1);
        EXPECT_EQ(v2[i], value1 + value2);
        EXPECT_EQ(v1[i], value1);
    }

    EXPECT_EQ(v2, value1 + value2);
    EXPECT_EQ(v1, value1);

    EXPECT_EQ(value1 + value2, v2);
    EXPECT_EQ(value1, v1);
}

TEST(vd_test_add_with_vector_return_to_same_uint64_t, algebra) {

    vector_dense<uint64_t> v1(dimension, value3);
    vector_dense<uint64_t> v2(dimension, value4);

    v1 = v1 + v2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v1(i), value3 + value4);
        EXPECT_EQ(v2(i), value4);
        EXPECT_EQ(v1[i], value3 + value4);
        EXPECT_EQ(v2[i], value4);
    }

    EXPECT_EQ(v1, value3 + value4);
    EXPECT_EQ(v2, value4);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value3;
    v2 = value4;

    v2 = v1 + v2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v2(i), value3 + value4);
        EXPECT_EQ(v1(i), value3);
        EXPECT_EQ(v2[i], value3 + value4);
        EXPECT_EQ(v1[i], value3);
    }

    EXPECT_EQ(v2, value3 + value4);
    EXPECT_EQ(v1, value3);

    EXPECT_EQ(value3 + value4, v2);
    EXPECT_EQ(value3, v1);
}

TEST(vd_test_add_with_vector_return_to_same_parallel_double, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 + v2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v1(i), value1 + value2);
        EXPECT_EQ(v2(i), value2);
        EXPECT_EQ(v1[i], value1 + value2);
        EXPECT_EQ(v2[i], value2);
    }

    EXPECT_EQ(v1, value1 + value2);
    EXPECT_EQ(v2, value2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;

    v2 = v1 + v2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v2(i), value1 + value2);
        EXPECT_EQ(v1(i), value1);
        EXPECT_EQ(v2[i], value1 + value2);
        EXPECT_EQ(v1[i], value1);
    }

    EXPECT_EQ(v2, value1 + value2);
    EXPECT_EQ(v1, value1);

    EXPECT_EQ(value1 + value2, v2);
    EXPECT_EQ(value1, v1);
}

// test subtract from a vector a number

TEST(vd_test_subtract_a_number, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 - value1;

    EXPECT_EQ(v2[index1], v1[index1] - value1);
    EXPECT_EQ(v2, v1 - value1);
    EXPECT_EQ(v1 - value1, v2);

}

// test subtract a vector from another vector

TEST(vd_test_subtract_with_vector, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 - v2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], v1[index1] - v2[index1]);
    EXPECT_EQ(v3, v1 - v2);
    EXPECT_EQ(v1 - v2, v3);
}

TEST(vd_test_subtract_a_number_to_same, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 - value1;

    EXPECT_EQ(v1[index1], value - value1);
    EXPECT_EQ(v1[index2], value - value1);
    EXPECT_EQ(v1, value - value1);

}

// test subtract a vector from another vector and return to it

TEST(vd_test_subtract_with_vector_return_to_same, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 - v2;

    EXPECT_EQ(v1[index1], value1 - value2);
    EXPECT_EQ(v1[index2], value1 - value2);

    EXPECT_EQ(v1, value1 - value2);
    EXPECT_EQ(value1 - value2, v1);

    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    EXPECT_EQ(v2, value2);
    EXPECT_EQ(value2, v2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;
    v2 = v1 - v2;

    EXPECT_EQ(v2[index1], value1 - value2);
    EXPECT_EQ(v2[index2], value1 - value2);

    EXPECT_EQ(v2, value1 - value2);
    EXPECT_EQ(value1 - value2, v2);

    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v1, value1);
    EXPECT_EQ(value1, v1);
}

TEST(vd_test_times_a_number, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 * value1;

    EXPECT_EQ(v2[index1], v1[index1] * value1);
    EXPECT_EQ(v2, v1 * value1);
    EXPECT_EQ(v1 * value1, v2);
}

TEST(vd_test_times_with_vector, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 * v2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], v1[index1] * v2[index1]);
    EXPECT_EQ(v3, v1 * v2);
    EXPECT_EQ(v1 * v2, v3);
}

TEST(vd_test_times_a_number_to_same, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 * value1;

    EXPECT_EQ(v1[index1], value * value1);
    EXPECT_EQ(v1[index2], value * value1);
    EXPECT_EQ(v1, value * value1);
    EXPECT_EQ(value * value1, v1);
}

TEST(vd_test_times_a_number_to_same_in_parallel, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 * value1;

    EXPECT_EQ(v1[index1], value * value1);
    EXPECT_EQ(v1[index2], value * value1);
}

// test times a vector with another vector and return to it

TEST(vd_test_times_a_vector_return_to_same, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 * v2;

    EXPECT_EQ(v1[index1], value1 * value2);
    EXPECT_EQ(v1[index2], value1 * value2);
    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;
    v2 = v1 * v2;

    EXPECT_EQ(v2[index1], value1 * value2);
    EXPECT_EQ(v2[index2], value1 * value2);
    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v2, value1 * value2);
    EXPECT_EQ(value1 * value2, v2);
    EXPECT_EQ(v1, value1);
    EXPECT_EQ(value1, v1);
}


TEST(vd_test_divide_a_number, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 / value1;

    EXPECT_EQ(v2[index1], v1[index1] / value1);
    EXPECT_EQ(v2, v1 / value1);
    EXPECT_EQ(v1 / value1, v2);

}

TEST(vd_test_divide_with_vector, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 / v2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], v1[index1] / v2[index1]);
    EXPECT_EQ(v3, v1 / v2);
    EXPECT_EQ(v1 / v2, v3);
}

TEST(vd_test_divide_a_number_to_same, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 / value1;

    EXPECT_EQ(v1[index1], value / value1);
    EXPECT_EQ(v1[index2], value / value1);
    EXPECT_EQ(v1, value / value1);
    EXPECT_EQ(value / value1, v1);
}

TEST(vd_test_divide_a_vector_return_to_same, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 / v2;

    EXPECT_EQ(v1[index1], value1 / value2);
    EXPECT_EQ(v1[index2], value1 / value2);
    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    EXPECT_EQ(v2, value2);
    EXPECT_EQ(v1, value1 / value2);

    EXPECT_EQ(value2, v2);
    EXPECT_EQ(value1 / value2, v1);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;
    v2 = v1 / v2;

    EXPECT_EQ(v2[index1], value1 / value2);
    EXPECT_EQ(v2[index2], value1 / value2);
    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v1, value1);
    EXPECT_EQ(value1, v1);
    EXPECT_EQ(v2, value1 / value2);
    EXPECT_EQ(value1 / value2, v2);
}

TEST(vd_test_add_with_number_operator, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 + value1;

    EXPECT_EQ(v2[index1], v1[index1] + value1);
    EXPECT_EQ(v2(index1), v1(index1) + value1);
    EXPECT_EQ(v2, v1 + value1);
    EXPECT_EQ(v1 + value1, v2);
}

TEST(vd_test_add_with_vector_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 + v2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], v1[index1] + v2[index1]);
    EXPECT_EQ(v3, v1 + v2);
    EXPECT_EQ(v1 + v2, v3);
}

TEST(vd_test_add_with_number_return_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 + value1;

    EXPECT_EQ(v1[index1], value + value1);
    EXPECT_EQ(v1[index2], value + value1);

    EXPECT_EQ(v1, value + value1);
    EXPECT_EQ(value + value1, v1);
}

TEST(vd_test_add_with_vector_return_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 + v2;

    EXPECT_EQ(v1[index1], value1 + value2);
    EXPECT_EQ(v1[index2], value1 + value2);
    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    EXPECT_EQ(v1, value1 + value2);
    EXPECT_EQ(value1 + value2, v1);
    EXPECT_EQ(v2, value2);
    EXPECT_EQ(value2, v2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;
    v2 = v1 + v2;

    EXPECT_EQ(v2[index1], value1 + value2);
    EXPECT_EQ(v2[index2], value1 + value2);
    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v1, value1);
    EXPECT_EQ(value1, v1);

    EXPECT_EQ(v2, value1 + value2);
    EXPECT_EQ(value1 + value2, v2);
}

TEST(vd_test_subtract_a_number_operator, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 - value1;

    EXPECT_EQ(v2[index1], v1[index1] - value1);
    EXPECT_EQ(v2, v1 - value1);
}


TEST(vd_test_subtract_with_vector_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 - v2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], v1[index1] - v2[index1]);
    EXPECT_EQ(v3, v1 - v2);
    EXPECT_EQ(v1 - v2, v3);
}

TEST(vd_test_subtract_a_number_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 - value1;

    EXPECT_EQ(v1[index1], value - value1);
    EXPECT_EQ(v1[index2], value - value1);

    EXPECT_EQ(v1, value - value1);
    EXPECT_EQ(value - value1, v1);
}


TEST(vd_test_subtract_with_vector_return_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 - v2;

    EXPECT_EQ(v1[index1], value1 - value2);
    EXPECT_EQ(v1[index2], value1 - value2);
    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);
    v1 = value1;
    v2 = value2;

    v2 = v1 - v2;

    EXPECT_EQ(v2[index1], value1 - value2);
    EXPECT_EQ(v2[index2], value1 - value2);
    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v1, value1);
    EXPECT_EQ(v2, value1 - value2);
}

TEST(vd_test_times_a_number_operator, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 * value1;

    EXPECT_EQ(v2[index1], v1[index1] * value1);
    EXPECT_EQ(v2, v1[index1] * value1);
    EXPECT_EQ(v2[index1], v1 * value1);
    EXPECT_EQ(v2, v1 * value1);
}

TEST(vd_test_times_with_vector_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 * v2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], v1[index1] * v2[index1]);
    EXPECT_EQ(v3, v1[index1] * v2[index1]);
    EXPECT_EQ(v3[index1], v1[index1] * v2);
    EXPECT_EQ(v3, v1 * v2[index1]);
    EXPECT_EQ(v3, v1 * v2);
}


TEST(vd_test_times_a_number_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 * value1;

    EXPECT_EQ(v1[index1], value * value1);
    EXPECT_EQ(v1[index2], value * value1);
    EXPECT_EQ(v1, value * value1);
}

TEST(vd_test_times_a_vector_return_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 * v2;

    EXPECT_EQ(v1[index1], value1 * value2);
    EXPECT_EQ(v1[index2], value1 * value2);
    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);
    v1 = value1;
    v2 = value2;

    v2 = v1 * v2;

    EXPECT_EQ(v2[index1], value1 * value2);
    EXPECT_EQ(v2[index2], value1 * value2);
    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v1, value1);
    EXPECT_EQ(v2, value1 * value2);
}

TEST(vd_test_divide_a_number_operator, algebra) {

    vector_dense<double> v1(dimension, value);
    vector_dense<double> v2;

    v2 = v1 / value1;

    EXPECT_EQ(v2[index1], v1[index1] / value1);
}

// test divide a vector with another vector using operator

TEST(vd_test_divide_with_vector_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);
    vector_dense<double> v3;

    v3 = v1 / v2;

    EXPECT_TRUE(v3.allocated());

    EXPECT_EQ(v3[index1], v1[index1] / v2[index1]);
    EXPECT_EQ(v3[index1], v1[index1] / v2);
    EXPECT_EQ(v3[index1], v1 / v2[index1]);
    EXPECT_EQ(v3[index1], v1 / v2);

    EXPECT_EQ(v3, v1[index1] / v2[index1]);
    EXPECT_EQ(v3, v1[index1] / v2);
    EXPECT_EQ(v3, v1 / v2[index1]);
    EXPECT_EQ(v3, v1 / v2);

}

TEST(vd_test_divide_with_number_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value);

    v1 = v1 / value1;

    EXPECT_EQ(v1[index1], value / value1);
    EXPECT_EQ(v1[index2], value / value1);
    EXPECT_EQ(v1, value / value1);
}

TEST(vd_test_divide_a_vector_return_to_same_operator, algebra) {

    vector_dense<double> v1(dimension, value1);
    vector_dense<double> v2(dimension, value2);

    v1 = v1 / v2;

    EXPECT_EQ(v1[index1], value1 / value2);
    EXPECT_EQ(v1[index2], value1 / value2);
    EXPECT_EQ(v2[index1], value2);
    EXPECT_EQ(v2[index2], value2);

    EXPECT_EQ(v1, value1 / value2);
    EXPECT_EQ(v2, value2);

    v1.deallocate();
    v2.deallocate();
    v1.allocate(dimension);
    v2.allocate(dimension);

    v1 = value1;
    v2 = value2;
    v2 = v1 / v2;

    EXPECT_EQ(v2[index1], value1 / value2);
    EXPECT_EQ(v2[index2], value1 / value2);
    EXPECT_EQ(v1[index1], value1);
    EXPECT_EQ(v1[index2], value1);

    EXPECT_EQ(v2, value1 / value2);
    EXPECT_EQ(v1, value1);
}