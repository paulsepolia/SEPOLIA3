#include <gtest/gtest.h>
#include <cmath>
#include "../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

const uint64_t rows = static_cast<const uint64_t>(std::pow(10.0, 1.0));
const uint64_t columns = static_cast<const uint64_t>(std::pow(10.0, 3.0));
const uint64_t dimension = rows * columns;

const double value = 123.456;
const double value1 = 234.567;
const double value2 = 765.432;
const uint64_t value3 = 123456;
const uint64_t value4 = 876543;
const uint64_t index1 = 11;
const uint64_t index2 = 12;


TEST(md_test_add_with_number_double, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1 = value;
    md2 = value1 + md1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md2(i), md1(i) + value1);
        EXPECT_EQ(md2[i], md1[i] + value1);
        EXPECT_EQ(md2[i], value1 + value);
        EXPECT_EQ(md1[i], value);
    }

    EXPECT_EQ(md2, value1 + value);
    EXPECT_EQ(md1, value);
    EXPECT_EQ(value1 + value, md2);
    EXPECT_EQ(value, md1);
}

TEST(md_test_add_with_number_uint64t, algebra) {

    dense_matrix<uint64_t> md1(rows, columns);
    dense_matrix<uint64_t> md2;

    md1 = value3;

    md2 = md1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md2(i), md1(i) + value4);
        EXPECT_EQ(md2[i], md1[i] + value4);
        EXPECT_EQ(md2[i], value3 + value4);
        EXPECT_EQ(md1[i], value3);
    }

    EXPECT_EQ(md1, value3);
    EXPECT_EQ(md2, md1 + value4);
    EXPECT_EQ(value3, md1);
    EXPECT_EQ(md1 + value4, md2);
}

TEST(md_test_add_with_matrix_double, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1 = value1;
    md2 = value2;

    md3 = md1 + md2;

    EXPECT_TRUE(md3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md3[i], md1[i] + md2[i]);
        EXPECT_EQ(md3(i), md1(i) + md2(i));
    }

    EXPECT_EQ(md3, md1 + md2);
    EXPECT_EQ(md1 + md2, md3);
}

TEST(md_test_add_with_matrix_uint64t, algebra) {

    dense_matrix<uint64_t> md1(rows, columns);
    dense_matrix<uint64_t> md2(rows, columns);
    dense_matrix<uint64_t> md3;

    md1 = value3;
    md2 = value4;

    md3 = md1 + md2;

    EXPECT_TRUE(md3.allocated());

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md3[i], md1[i] + md2[i]);
        EXPECT_EQ(md3(i), md1(i) + md2(i));
    }

    EXPECT_EQ(md3, md1 + md2);
    EXPECT_EQ(md1 + md2, md3);
}


TEST(md_test_add_with_number_return_to_same_double, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1 = value;

    md1 = md1 + value1;
    md1 = value1 + md1;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md1(i), value + 2 * value1);
        EXPECT_EQ(md1[i], value + 2 * value1);
    }

    EXPECT_EQ(md1, value + 2 * value1);
    EXPECT_EQ(value + 2 * value1, md1);
}

TEST(md_test_add_with_number_return_to_same_uint64_t, algebra) {

    dense_matrix<uint64_t> md1(rows, columns);

    md1 = value3;

    md1 = md1 + value4;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md1(i), value3 + value4);
        EXPECT_EQ(md1[i], value3 + value4);
    }

    EXPECT_EQ(md1, value3 + value4);
    EXPECT_EQ(value3 + value4, md1);
}

// test add a matrix with another matrix and return to it, double case

TEST(md_test_add_with_matrix_return_to_same_double, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md1 = md1 + md2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md1(i), value1 + value2);
        EXPECT_EQ(md2(i), value2);
        EXPECT_EQ(md1[i], value1 + value2);
        EXPECT_EQ(md2[i], value2);
    }

    EXPECT_EQ(md1, value1 + value2);
    EXPECT_EQ(md2, value2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value1;
    md2 = value2;

    md2 = md1 + md2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md2(i), value1 + value2);
        EXPECT_EQ(md1(i), value1);
        EXPECT_EQ(md2[i], value1 + value2);
        EXPECT_EQ(md1[i], value1);
    }

    EXPECT_EQ(md2, value1 + value2);
    EXPECT_EQ(md1, value1);

    EXPECT_EQ(value1 + value2, md2);
    EXPECT_EQ(value1, md1);
}

TEST(md_test_add_with_matrix_return_to_same_uint64_t, algebra) {

    dense_matrix<uint64_t> md1(rows, columns);
    dense_matrix<uint64_t> md2(rows, columns);

    md1 = value3;
    md2 = value4;

    md1 = md1 + md2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md1(i), value3 + value4);
        EXPECT_EQ(md2(i), value4);
        EXPECT_EQ(md1[i], value3 + value4);
        EXPECT_EQ(md2[i], value4);
    }

    EXPECT_EQ(md1, value3 + value4);
    EXPECT_EQ(md2, value4);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value3;
    md2 = value4;

    md2 = md1 + md2;

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(md2(i), value3 + value4);
        EXPECT_EQ(md1(i), value3);
        EXPECT_EQ(md2[i], value3 + value4);
        EXPECT_EQ(md1[i], value3);
    }

    EXPECT_EQ(md2, value3 + value4);
    EXPECT_EQ(md1, value3);

    EXPECT_EQ(value3 + value4, md2);
    EXPECT_EQ(value3, md1);
}

// test subtract from a matrix a number

TEST(md_test_subtract_a_number, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1 = value;

    md2 = md1 - value1;

    EXPECT_EQ(md2[index1], md1[index1] - value1);
    EXPECT_EQ(md2, md1 - value1);
    EXPECT_EQ(md1 - value1, md2);

}

// test subtract a matrix from another matrix

TEST(md_test_subtract_with_matrix, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1 = value1;
    md2 = value2;

    md3 = md1 - md2;

    EXPECT_TRUE(md3.allocated());
    EXPECT_EQ(md3[index1], md1[index1] - md2[index1]);
    EXPECT_EQ(md3, md1 - md2);
    EXPECT_EQ(md1 - md2, md3);
}

TEST(md_test_subtract_a_number_to_same, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1 = value;

    md1 = md1 - value1;

    EXPECT_EQ(md1[index1], value - value1);
    EXPECT_EQ(md1[index2], value - value1);
    EXPECT_EQ(md1, value - value1);

}

// test subtract a matrix from another matrix and return to it

TEST(md_test_subtract_with_matrix_return_to_same, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md1 = md1 - md2;

    EXPECT_EQ(md1[index1], value1 - value2);
    EXPECT_EQ(md1[index2], value1 - value2);

    EXPECT_EQ(md1, value1 - value2);
    EXPECT_EQ(value1 - value2, md1);

    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    EXPECT_EQ(md2, value2);
    EXPECT_EQ(value2, md2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value1;
    md2 = value2;
    md2 = md1 - md2;

    EXPECT_EQ(md2[index1], value1 - value2);
    EXPECT_EQ(md2[index2], value1 - value2);

    EXPECT_EQ(md2, value1 - value2);
    EXPECT_EQ(value1 - value2, md2);

    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md1, value1);
    EXPECT_EQ(value1, md1);
}

TEST(md_test_times_a_number, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1 = value;

    md2 = md1 * value1;

    EXPECT_EQ(md2[index1], md1[index1] * value1);
    EXPECT_EQ(md2, md1 * value1);
    EXPECT_EQ(md1 * value1, md2);
}

TEST(md_test_times_with_matrix, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1 = value1;
    md2 = value2;

    md3 = md1 * md2;

    EXPECT_TRUE(md3.allocated());
    EXPECT_EQ(md3[index1], md1[index1] * md2[index1]);
    EXPECT_EQ(md3, md1 * md2);
    EXPECT_EQ(md1 * md2, md3);
}

TEST(md_test_times_a_number_to_same, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1 = value;

    md1 = md1 * value1;

    EXPECT_EQ(md1[index1], value * value1);
    EXPECT_EQ(md1[index2], value * value1);
    EXPECT_EQ(md1, value * value1);
    EXPECT_EQ(value * value1, md1);
}

// test times a matrix with another matrix and return to it

TEST(md_test_times_a_matrix_return_to_same, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1 = value1;
    md2 = value2;

    md1 = md1 * md2;

    EXPECT_EQ(md1[index1], value1 * value2);
    EXPECT_EQ(md1[index2], value1 * value2);
    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value1;
    md2 = value2;
    md2 = md1 * md2;

    EXPECT_EQ(md2[index1], value1 * value2);
    EXPECT_EQ(md2[index2], value1 * value2);
    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md2, value1 * value2);
    EXPECT_EQ(value1 * value2, md2);
    EXPECT_EQ(md1, value1);
    EXPECT_EQ(value1, md1);
}


TEST(md_test_divide_a_number, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1 = value;

    md2 = md1 / value1;

    EXPECT_EQ(md2[index1], md1[index1] / value1);
    EXPECT_EQ(md2, md1 / value1);
    EXPECT_EQ(md1 / value1, md2);

}

TEST(md_test_divide_with_matrix, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1= value1;
    md2= value2;

    md3 = md1 / md2;

    EXPECT_TRUE(md3.allocated());
    EXPECT_EQ(md3[index1], md1[index1] / md2[index1]);
    EXPECT_EQ(md3, md1 / md2);
    EXPECT_EQ(md1 / md2, md3);
}

TEST(md_test_divide_a_number_to_same, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1= value;

    md1 = md1 / value1;

    EXPECT_EQ(md1[index1], value / value1);
    EXPECT_EQ(md1[index2], value / value1);
    EXPECT_EQ(md1, value / value1);
    EXPECT_EQ(value / value1, md1);
}

TEST(md_test_divide_a_matrix_return_to_same, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1= value1;
    md2= value2;

    md1 = md1 / md2;

    EXPECT_EQ(md1[index1], value1 / value2);
    EXPECT_EQ(md1[index2], value1 / value2);
    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    EXPECT_EQ(md2, value2);
    EXPECT_EQ(md1, value1 / value2);

    EXPECT_EQ(value2, md2);
    EXPECT_EQ(value1 / value2, md1);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value1;
    md2 = value2;
    md2 = md1 / md2;

    EXPECT_EQ(md2[index1], value1 / value2);
    EXPECT_EQ(md2[index2], value1 / value2);
    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md1, value1);
    EXPECT_EQ(value1, md1);
    EXPECT_EQ(md2, value1 / value2);
    EXPECT_EQ(value1 / value2, md2);
}

TEST(md_test_add_with_number_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1= value;

    md2 = md1 + value1;

    EXPECT_EQ(md2[index1], md1[index1] + value1);
    EXPECT_EQ(md2(index1), md1(index1) + value1);
    EXPECT_EQ(md2, md1 + value1);
    EXPECT_EQ(md1 + value1, md2);
}

TEST(md_test_add_with_matrix_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1= value1;
    md1= value2;

    md3 = md1 + md2;

    EXPECT_TRUE(md3.allocated());
    EXPECT_EQ(md3[index1], md1[index1] + md2[index1]);
    EXPECT_EQ(md3, md1 + md2);
    EXPECT_EQ(md1 + md2, md3);
}

TEST(md_test_add_with_number_return_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1= value;

    md1 = md1 + value1;

    EXPECT_EQ(md1[index1], value + value1);
    EXPECT_EQ(md1[index2], value + value1);

    EXPECT_EQ(md1, value + value1);
    EXPECT_EQ(value + value1, md1);
}

TEST(md_test_add_with_matrix_return_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1= value1;
    md2= value2;

    md1 = md1 + md2;

    EXPECT_EQ(md1[index1], value1 + value2);
    EXPECT_EQ(md1[index2], value1 + value2);
    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    EXPECT_EQ(md1, value1 + value2);
    EXPECT_EQ(value1 + value2, md1);
    EXPECT_EQ(md2, value2);
    EXPECT_EQ(value2, md2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value1;
    md2 = value2;
    md2 = md1 + md2;

    EXPECT_EQ(md2[index1], value1 + value2);
    EXPECT_EQ(md2[index2], value1 + value2);
    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md1, value1);
    EXPECT_EQ(value1, md1);

    EXPECT_EQ(md2, value1 + value2);
    EXPECT_EQ(value1 + value2, md2);
}

TEST(md_test_subtract_a_number_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1= value;

    md2 = md1 - value1;

    EXPECT_EQ(md2[index1], md1[index1] - value1);
    EXPECT_EQ(md2, md1 - value1);
}


TEST(md_test_subtract_with_matrix_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1= value1;
    md1= value2;

    md3 = md1 - md2;

    EXPECT_TRUE(md3.allocated());
    EXPECT_EQ(md3[index1], md1[index1] - md2[index1]);
    EXPECT_EQ(md3, md1 - md2);
    EXPECT_EQ(md1 - md2, md3);
}

TEST(md_test_subtract_a_number_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1= value;
    md1 = md1 - value1;

    EXPECT_EQ(md1[index1], value - value1);
    EXPECT_EQ(md1[index2], value - value1);

    EXPECT_EQ(md1, value - value1);
    EXPECT_EQ(value - value1, md1);
}


TEST(md_test_subtract_with_matrix_return_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1= value1;
    md2= value2;

    md1 = md1 - md2;

    EXPECT_EQ(md1[index1], value1 - value2);
    EXPECT_EQ(md1[index2], value1 - value2);
    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);
    md1 = value1;
    md2 = value2;

    md2 = md1 - md2;

    EXPECT_EQ(md2[index1], value1 - value2);
    EXPECT_EQ(md2[index2], value1 - value2);
    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md1, value1);
    EXPECT_EQ(md2, value1 - value2);
}

TEST(md_test_times_a_number_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1= value;

    md2 = md1 * value1;

    EXPECT_EQ(md2[index1], md1[index1] * value1);
    EXPECT_EQ(md2, md1[index1] * value1);
    EXPECT_EQ(md2[index1], md1 * value1);
    EXPECT_EQ(md2, md1 * value1);
}

TEST(md_test_times_with_matrix_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1= value1;
    md2= value2;

    md3 = md1 * md2;

    EXPECT_TRUE(md3.allocated());
    EXPECT_EQ(md3[index1], md1[index1] * md2[index1]);
    EXPECT_EQ(md3, md1[index1] * md2[index1]);
    EXPECT_EQ(md3[index1], md1[index1] * md2);
    EXPECT_EQ(md3, md1 * md2[index1]);
    EXPECT_EQ(md3, md1 * md2);
}

TEST(md_test_times_a_number_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1= value;

    md1 = md1 * value1;

    EXPECT_EQ(md1[index1], value * value1);
    EXPECT_EQ(md1[index2], value * value1);
    EXPECT_EQ(md1, value * value1);
}

TEST(md_test_times_a_matrix_return_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1= value1;
    md2= value2;

    md1 = md1 * md2;

    EXPECT_EQ(md1[index1], value1 * value2);
    EXPECT_EQ(md1[index2], value1 * value2);
    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);
    md1 = value1;
    md2 = value2;

    md2 = md1 * md2;

    EXPECT_EQ(md2[index1], value1 * value2);
    EXPECT_EQ(md2[index2], value1 * value2);
    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md1, value1);
    EXPECT_EQ(md2, value1 * value2);
}

TEST(md_test_divide_a_number_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1= value;

    md2 = md1 / value1;

    EXPECT_EQ(md2[index1], md1[index1] / value1);
}

// test divide a matrix with another matrix using operator

TEST(md_test_divide_with_matrix_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);
    dense_matrix<double> md3;

    md1= value1;
    md2= value2;

    md3 = md1 / md2;

    EXPECT_TRUE(md3.allocated());

    EXPECT_EQ(md3[index1], md1[index1] / md2[index1]);
    EXPECT_EQ(md3[index1], md1[index1] / md2);
    EXPECT_EQ(md3[index1], md1 / md2[index1]);
    EXPECT_EQ(md3[index1], md1 / md2);

    EXPECT_EQ(md3, md1[index1] / md2[index1]);
    EXPECT_EQ(md3, md1[index1] / md2);
    EXPECT_EQ(md3, md1 / md2[index1]);
    EXPECT_EQ(md3, md1 / md2);

}

TEST(md_test_divide_with_number_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);

    md1= value;

    md1 = md1 / value1;

    EXPECT_EQ(md1[index1], value / value1);
    EXPECT_EQ(md1[index2], value / value1);
    EXPECT_EQ(md1, value / value1);
}

TEST(md_test_divide_a_matrix_return_to_same_operator, algebra) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1= value1;
    md2= value2;

    md1 = md1 / md2;

    EXPECT_EQ(md1[index1], value1 / value2);
    EXPECT_EQ(md1[index2], value1 / value2);
    EXPECT_EQ(md2[index1], value2);
    EXPECT_EQ(md2[index2], value2);

    EXPECT_EQ(md1, value1 / value2);
    EXPECT_EQ(md2, value2);

    md1.deallocate();
    md2.deallocate();
    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    md1 = value1;
    md2 = value2;
    md2 = md1 / md2;

    EXPECT_EQ(md2[index1], value1 / value2);
    EXPECT_EQ(md2[index2], value1 / value2);
    EXPECT_EQ(md1[index1], value1);
    EXPECT_EQ(md1[index2], value1);

    EXPECT_EQ(md2, value1 / value2);
    EXPECT_EQ(md1, value1);
}