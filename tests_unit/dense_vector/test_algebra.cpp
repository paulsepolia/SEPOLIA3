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


TEST(vd_test_add_with_number_double, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = value1 + vd1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd2(i), vd1(i) + value1);
        EXPECT_EQ(vd2[i], vd1[i] + value1);
        EXPECT_EQ(vd2[i], value1 + value);
        EXPECT_EQ(vd1[i], value);
    }

    EXPECT_EQ(vd2, value1 + value);
    EXPECT_EQ(vd1, value);
    EXPECT_EQ(value1 + value, vd2);
    EXPECT_EQ(value, vd1);
}

TEST(vd_test_add_with_number_uint64t, algebra) {

    dense_vector<uint64_t> vd1(dimension);
    dense_vector<uint64_t> vd2;

    vd1 = value3;
    vd2 = vd1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd2(i), vd1(i) + value4);
        EXPECT_EQ(vd2[i], vd1[i] + value4);
        EXPECT_EQ(vd2[i], value3 + value4);
        EXPECT_EQ(vd1[i], value3);
    }

    EXPECT_EQ(vd1, value3);
    EXPECT_EQ(vd2, vd1 + value4);
    EXPECT_EQ(value3, vd1);
    EXPECT_EQ(vd1 + value4, vd2);
}

TEST(vd_test_add_with_vector_double, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 + vd2;

    EXPECT_TRUE(v3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v3[i], vd1[i] + vd2[i]);
        EXPECT_EQ(v3(i), vd1(i) + vd2(i));
    }

    EXPECT_EQ(v3, vd1 + vd2);
    EXPECT_EQ(vd1 + vd2, v3);
}

TEST(vd_test_add_with_vector_uint64t, algebra) {

    dense_vector<uint64_t> vd1(dimension);
    dense_vector<uint64_t> vd2(dimension);
    dense_vector<uint64_t> v3;

    vd1 = value3;
    vd2 = value4;
    v3 = vd1 + vd2;

    EXPECT_TRUE(v3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(v3[i], vd1[i] + vd2[i]);
        EXPECT_EQ(v3(i), vd1(i) + vd2(i));
    }

    EXPECT_EQ(v3, vd1 + vd2);
    EXPECT_EQ(vd1 + vd2, v3);
}


TEST(vd_test_add_with_number_return_to_same_double, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 + value1;
    vd1 = value1 + vd1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd1(i), value + 2 * value1);
        EXPECT_EQ(vd1[i], value + 2 * value1);
    }

    EXPECT_EQ(vd1, value + 2 * value1);
    EXPECT_EQ(value + 2 * value1, vd1);
}

TEST(vd_test_add_with_number_return_to_same_uint64_t, algebra) {

    dense_vector<uint64_t> vd1(dimension);

    vd1 = value3;
    vd1 = vd1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd1(i), value3 + value4);
        EXPECT_EQ(vd1[i], value3 + value4);
    }

    EXPECT_EQ(vd1, value3 + value4);
    EXPECT_EQ(value3 + value4, vd1);
}

// test add a vector with another vector and return to it, double case

TEST(vd_test_add_with_vector_return_to_same_double, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 + vd2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd1(i), value1 + value2);
        EXPECT_EQ(vd2(i), value2);
        EXPECT_EQ(vd1[i], value1 + value2);
        EXPECT_EQ(vd2[i], value2);
    }

    EXPECT_EQ(vd1, value1 + value2);
    EXPECT_EQ(vd2, value2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value1;
    vd2 = value2;
    vd2 = vd1 + vd2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd2(i), value1 + value2);
        EXPECT_EQ(vd1(i), value1);
        EXPECT_EQ(vd2[i], value1 + value2);
        EXPECT_EQ(vd1[i], value1);
    }

    EXPECT_EQ(vd2, value1 + value2);
    EXPECT_EQ(vd1, value1);

    EXPECT_EQ(value1 + value2, vd2);
    EXPECT_EQ(value1, vd1);
}

TEST(vd_test_add_with_vector_return_to_same_uint64_t, algebra) {

    dense_vector<uint64_t> vd1(dimension);
    dense_vector<uint64_t> vd2(dimension);

    vd1 = value3;
    vd2 = value4;
    vd1 = vd1 + vd2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd1(i), value3 + value4);
        EXPECT_EQ(vd2(i), value4);
        EXPECT_EQ(vd1[i], value3 + value4);
        EXPECT_EQ(vd2[i], value4);
    }

    EXPECT_EQ(vd1, value3 + value4);
    EXPECT_EQ(vd2, value4);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value3;
    vd2 = value4;
    vd2 = vd1 + vd2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(vd2(i), value3 + value4);
        EXPECT_EQ(vd1(i), value3);
        EXPECT_EQ(vd2[i], value3 + value4);
        EXPECT_EQ(vd1[i], value3);
    }

    EXPECT_EQ(vd2, value3 + value4);
    EXPECT_EQ(vd1, value3);

    EXPECT_EQ(value3 + value4, vd2);
    EXPECT_EQ(value3, vd1);
}

// test subtract from a vector a number

TEST(vd_test_subtract_a_number, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 - value1;

    EXPECT_EQ(vd2[index1], vd1[index1] - value1);
    EXPECT_EQ(vd2, vd1 - value1);
    EXPECT_EQ(vd1 - value1, vd2);

}

// test subtract a vector from another vector

TEST(vd_test_subtract_with_vector, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 - vd2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], vd1[index1] - vd2[index1]);
    EXPECT_EQ(v3, vd1 - vd2);
    EXPECT_EQ(vd1 - vd2, v3);
}

TEST(vd_test_subtract_a_number_to_same, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 - value1;

    EXPECT_EQ(vd1[index1], value - value1);
    EXPECT_EQ(vd1[index2], value - value1);
    EXPECT_EQ(vd1, value - value1);

}

// test subtract a vector from another vector and return to it

TEST(vd_test_subtract_with_vector_return_to_same, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 - vd2;

    EXPECT_EQ(vd1[index1], value1 - value2);
    EXPECT_EQ(vd1[index2], value1 - value2);

    EXPECT_EQ(vd1, value1 - value2);
    EXPECT_EQ(value1 - value2, vd1);

    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    EXPECT_EQ(vd2, value2);
    EXPECT_EQ(value2, vd2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value1;
    vd2 = value2;
    vd2 = vd1 - vd2;

    EXPECT_EQ(vd2[index1], value1 - value2);
    EXPECT_EQ(vd2[index2], value1 - value2);

    EXPECT_EQ(vd2, value1 - value2);
    EXPECT_EQ(value1 - value2, vd2);

    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(value1, vd1);
}

TEST(vd_test_times_a_number, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 * value1;

    EXPECT_EQ(vd2[index1], vd1[index1] * value1);
    EXPECT_EQ(vd2, vd1 * value1);
    EXPECT_EQ(vd1 * value1, vd2);
}

TEST(vd_test_times_with_vector, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 * vd2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], vd1[index1] * vd2[index1]);
    EXPECT_EQ(v3, vd1 * vd2);
    EXPECT_EQ(vd1 * vd2, v3);
}

TEST(vd_test_times_a_number_to_same, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 * value1;

    EXPECT_EQ(vd1[index1], value * value1);
    EXPECT_EQ(vd1[index2], value * value1);
    EXPECT_EQ(vd1, value * value1);
    EXPECT_EQ(value * value1, vd1);
}

// test times a vector with another vector and return to it

TEST(vd_test_times_a_vector_return_to_same, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;

    vd1 = vd1 * vd2;

    EXPECT_EQ(vd1[index1], value1 * value2);
    EXPECT_EQ(vd1[index2], value1 * value2);
    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value1;
    vd2 = value2;
    vd2 = vd1 * vd2;

    EXPECT_EQ(vd2[index1], value1 * value2);
    EXPECT_EQ(vd2[index2], value1 * value2);
    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd2, value1 * value2);
    EXPECT_EQ(value1 * value2, vd2);
    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(value1, vd1);
}


TEST(vd_test_divide_a_number, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 / value1;

    EXPECT_EQ(vd2[index1], vd1[index1] / value1);
    EXPECT_EQ(vd2, vd1 / value1);
    EXPECT_EQ(vd1 / value1, vd2);
}

TEST(vd_test_divide_with_vector, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;

    v3 = vd1 / vd2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], vd1[index1] / vd2[index1]);
    EXPECT_EQ(v3, vd1 / vd2);
    EXPECT_EQ(vd1 / vd2, v3);
}

TEST(vd_test_divide_a_number_to_same, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 / value1;

    EXPECT_EQ(vd1[index1], value / value1);
    EXPECT_EQ(vd1[index2], value / value1);
    EXPECT_EQ(vd1, value / value1);
    EXPECT_EQ(value / value1, vd1);
}

TEST(vd_test_divide_a_vector_return_to_same, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 / vd2;

    EXPECT_EQ(vd1[index1], value1 / value2);
    EXPECT_EQ(vd1[index2], value1 / value2);
    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    EXPECT_EQ(vd2, value2);
    EXPECT_EQ(vd1, value1 / value2);

    EXPECT_EQ(value2, vd2);
    EXPECT_EQ(value1 / value2, vd1);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value1;
    vd2 = value2;
    vd2 = vd1 / vd2;

    EXPECT_EQ(vd2[index1], value1 / value2);
    EXPECT_EQ(vd2[index2], value1 / value2);
    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(value1, vd1);
    EXPECT_EQ(vd2, value1 / value2);
    EXPECT_EQ(value1 / value2, vd2);
}

TEST(vd_test_add_with_number_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 + value1;

    EXPECT_EQ(vd2[index1], vd1[index1] + value1);
    EXPECT_EQ(vd2(index1), vd1(index1) + value1);
    EXPECT_EQ(vd2, vd1 + value1);
    EXPECT_EQ(vd1 + value1, vd2);
}

TEST(vd_test_add_with_vector_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 + vd2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], vd1[index1] + vd2[index1]);
    EXPECT_EQ(v3, vd1 + vd2);
    EXPECT_EQ(vd1 + vd2, v3);
}

TEST(vd_test_add_with_number_return_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 + value1;

    EXPECT_EQ(vd1[index1], value + value1);
    EXPECT_EQ(vd1[index2], value + value1);

    EXPECT_EQ(vd1, value + value1);
    EXPECT_EQ(value + value1, vd1);
}

TEST(vd_test_add_with_vector_return_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 + vd2;

    EXPECT_EQ(vd1[index1], value1 + value2);
    EXPECT_EQ(vd1[index2], value1 + value2);
    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    EXPECT_EQ(vd1, value1 + value2);
    EXPECT_EQ(value1 + value2, vd1);
    EXPECT_EQ(vd2, value2);
    EXPECT_EQ(value2, vd2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value1;
    vd2 = value2;
    vd2 = vd1 + vd2;

    EXPECT_EQ(vd2[index1], value1 + value2);
    EXPECT_EQ(vd2[index2], value1 + value2);
    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(value1, vd1);

    EXPECT_EQ(vd2, value1 + value2);
    EXPECT_EQ(value1 + value2, vd2);
}

TEST(vd_test_subtract_a_number_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 - value1;

    EXPECT_EQ(vd2[index1], vd1[index1] - value1);
    EXPECT_EQ(vd2, vd1 - value1);
}

TEST(vd_test_subtract_with_vector_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 - vd2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], vd1[index1] - vd2[index1]);
    EXPECT_EQ(v3, vd1 - vd2);
    EXPECT_EQ(vd1 - vd2, v3);
}

TEST(vd_test_subtract_a_number_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 - value1;

    EXPECT_EQ(vd1[index1], value - value1);
    EXPECT_EQ(vd1[index2], value - value1);

    EXPECT_EQ(vd1, value - value1);
    EXPECT_EQ(value - value1, vd1);
}


TEST(vd_test_subtract_with_vector_return_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 - vd2;

    EXPECT_EQ(vd1[index1], value1 - value2);
    EXPECT_EQ(vd1[index2], value1 - value2);
    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);
    vd1 = value1;
    vd2 = value2;

    vd2 = vd1 - vd2;

    EXPECT_EQ(vd2[index1], value1 - value2);
    EXPECT_EQ(vd2[index2], value1 - value2);
    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(vd2, value1 - value2);
}

TEST(vd_test_times_a_number_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 * value1;

    EXPECT_EQ(vd2[index1], vd1[index1] * value1);
    EXPECT_EQ(vd2, vd1[index1] * value1);
    EXPECT_EQ(vd2[index1], vd1 * value1);
    EXPECT_EQ(vd2, vd1 * value1);
}

TEST(vd_test_times_with_vector_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 * vd2;

    EXPECT_TRUE(v3.allocated());
    EXPECT_EQ(v3[index1], vd1[index1] * vd2[index1]);
    EXPECT_EQ(v3, vd1[index1] * vd2[index1]);
    EXPECT_EQ(v3[index1], vd1[index1] * vd2);
    EXPECT_EQ(v3, vd1 * vd2[index1]);
    EXPECT_EQ(v3, vd1 * vd2);
}

TEST(vd_test_times_a_number_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 * value1;

    EXPECT_EQ(vd1[index1], value * value1);
    EXPECT_EQ(vd1[index2], value * value1);
    EXPECT_EQ(vd1, value * value1);
}

TEST(vd_test_times_a_vector_return_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 * vd2;

    EXPECT_EQ(vd1[index1], value1 * value2);
    EXPECT_EQ(vd1[index2], value1 * value2);
    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);
    vd1 = value1;
    vd2 = value2;

    vd2 = vd1 * vd2;

    EXPECT_EQ(vd2[index1], value1 * value2);
    EXPECT_EQ(vd2[index2], value1 * value2);
    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd1, value1);
    EXPECT_EQ(vd2, value1 * value2);
}

TEST(vd_test_divide_a_number_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2;

    vd1 = value;
    vd2 = vd1 / value1;

    EXPECT_EQ(vd2[index1], vd1[index1] / value1);
}

// test divide a vector with another vector using operator

TEST(vd_test_divide_with_vector_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);
    dense_vector<double> v3;

    vd1 = value1;
    vd2 = value2;
    v3 = vd1 / vd2;

    EXPECT_TRUE(v3.allocated());

    EXPECT_EQ(v3[index1], vd1[index1] / vd2[index1]);
    EXPECT_EQ(v3[index1], vd1[index1] / vd2);
    EXPECT_EQ(v3[index1], vd1 / vd2[index1]);
    EXPECT_EQ(v3[index1], vd1 / vd2);

    EXPECT_EQ(v3, vd1[index1] / vd2[index1]);
    EXPECT_EQ(v3, vd1[index1] / vd2);
    EXPECT_EQ(v3, vd1 / vd2[index1]);
    EXPECT_EQ(v3, vd1 / vd2);

}

TEST(vd_test_divide_with_number_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);

    vd1 = value;
    vd1 = vd1 / value1;

    EXPECT_EQ(vd1[index1], value / value1);
    EXPECT_EQ(vd1[index2], value / value1);
    EXPECT_EQ(vd1, value / value1);
}

TEST(vd_test_divide_a_vector_return_to_same_operator, algebra) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1 = value1;
    vd2 = value2;
    vd1 = vd1 / vd2;

    EXPECT_EQ(vd1[index1], value1 / value2);
    EXPECT_EQ(vd1[index2], value1 / value2);
    EXPECT_EQ(vd2[index1], value2);
    EXPECT_EQ(vd2[index2], value2);

    EXPECT_EQ(vd1, value1 / value2);
    EXPECT_EQ(vd2, value2);

    vd1.deallocate();
    vd2.deallocate();
    vd1.allocate(dimension);
    vd2.allocate(dimension);

    vd1 = value1;
    vd2 = value2;
    vd2 = vd1 / vd2;

    EXPECT_EQ(vd2[index1], value1 / value2);
    EXPECT_EQ(vd2[index2], value1 / value2);
    EXPECT_EQ(vd1[index1], value1);
    EXPECT_EQ(vd1[index2], value1);

    EXPECT_EQ(vd2, value1 / value2);
    EXPECT_EQ(vd1, value1);
}