#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
const auto columns = static_cast<uint64_t>(std::pow(10.0, 2.0));
const double value1 = 123.456;
const uint64_t value2 = 123456;
const int64_t value3 = 456789;

TEST(md_set_element_via_constructor_and_get_it_double, set_get) {

    dense_matrix<double> md(rows, columns);

    md.set(value1);

    for (const auto &el: md) {

        EXPECT_EQ(value1, el);
    }
}

TEST(md_set_element_via_constructor_and_get_it_uint64_t, set_get) {

    dense_matrix<uint64_t> md(rows, columns);

    md.set(value2);

    for (const auto &el: md) {

        EXPECT_EQ(value2, el);
    }
}

TEST(md_set_element_via_constructor_and_get_it_int64_t, set_get) {

    dense_matrix<int64_t> md(rows, columns);

    md.set(value3);

    for (const auto &el: md) {

        EXPECT_EQ(value3, el);
    }
}

TEST(md_set_dimension_via_constructor_and_get_it_double, set_get) {

    dense_matrix<double> md(rows, columns);

    EXPECT_EQ(rows * columns, md.size());
}

TEST(md_set_dimension_via_constructor_and_get_it_uint64_t, set_get) {

    dense_matrix<uint64_t> md(rows, columns);

    EXPECT_EQ(rows * columns, md.size());
}

TEST(md_set_dimension_via_constructor_and_get_it_int64_t, set_get) {

    dense_matrix<int64_t> md(rows, columns);

    EXPECT_EQ(rows * columns, md.size());
}

TEST(md_set_dimension_via_allocate_and_get_it_double, set_get) {

    dense_matrix<double> md;
    md.allocate(rows, columns);

    EXPECT_EQ(rows * columns, md.size());
}

TEST(md_set_dimension_via_allocate_and_get_it_uint64_t, set_get) {

    dense_matrix<uint64_t> md;
    md.allocate(rows, columns);

    EXPECT_EQ(rows * columns, md.size());
}

TEST(md_set_dimension_via_allocate_and_get_it_int64_t, set_get) {

    dense_matrix<int64_t> md;
    md.allocate(rows, columns);

    EXPECT_EQ(rows * columns, md.size());
}

TEST(md_set_element_and_get_it_double, set_get) {

    dense_matrix<double> md(rows, columns);

    EXPECT_EQ(rows * columns, md.size());

    for (uint64_t i = 0; i < rows * columns; i++) {

        md(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < rows * columns; i++) {

        EXPECT_EQ(md(i), static_cast<double>(i));
    }
}

TEST(md_set_element_and_get_it_uint64_t, set_get) {

    dense_matrix<uint64_t> md(rows, columns);

    EXPECT_EQ(rows * columns, md.size());

    // curved brackets

    for (uint64_t i = 0; i < rows * columns; i++) {

        md(i) = i;
    }

    for (uint64_t i = 0; i < rows * columns; i++) {

        EXPECT_EQ(i, md(i));
    }

    // square brackets

    for (uint64_t i = 0; i < rows * columns; i++) {

        md[i] = i;
    }

    for (uint64_t i = 0; i < rows * columns; i++) {

        EXPECT_EQ(i, md[i]);
    }
}

TEST(md_set_element_and_get_it_int64_t, set_get) {

    dense_matrix<int64_t> md(rows, columns);

    EXPECT_EQ(rows * columns, md.size());

    // curved brackets

    for (uint64_t i = 0; i < rows * columns; i++) {

        md(i) = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < rows * columns; i++) {

        EXPECT_EQ(static_cast<int64_t>(i), md(i));
    }

    // square brackets

    for (uint64_t i = 0; i < rows * columns; i++) {

        md[i] = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < rows * columns; i++) {

        EXPECT_EQ(static_cast<int64_t>(i), md[i]);
    }
}

TEST(md_set_matrix_to_another_using_assignment_operator_double, set_get) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2;

    md1.set(value1);

    EXPECT_EQ(rows * columns, md1.size());

    for (const auto &el: md1) {

        EXPECT_EQ(value1, el);
    }

    md2 = md1;

    EXPECT_EQ(rows * columns, md2.size());

    for (const auto &el: md2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_EQ(md1, md2);

}

TEST(md_set_matrix_via_copy_constructor_double, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value1);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2(md1);

    EXPECT_EQ(rows * columns, md1.size());

    for (const auto &el: md1) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_EQ(rows * columns, md2.size());

    for (const auto &el: md2) {

        EXPECT_EQ(value1, el);
    }
}

TEST(md_set_matrix_via_copy_constructor_uint64_t, set_get) {

    dense_matrix<uint64_t> md1(rows, columns);

    md1.set(value2);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<uint64_t> md2(md1);

    EXPECT_EQ(rows * columns, md1.size());

    for (const auto &el: md1) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_EQ(rows * columns, md2.size());

    for (const auto &el: md2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_EQ(md1, md2);
}

TEST(md_set_matrix_via_copy_constructor_int64_t, set_get) {

    dense_matrix<int64_t> md1(rows, columns);

    md1.set(value3);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<int64_t> md2(md1);

    EXPECT_EQ(rows * columns, md1.size());

    for (const auto &el: md1) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_EQ(rows * columns, md2.size());

    for (const auto &el: md2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_EQ(md1, md2);
}

TEST(md_set_matrix_via_move_constructor_double, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value1);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2(std::move(md1));

    EXPECT_EQ(false, md1.allocated());
    EXPECT_EQ(true, md1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), md1.size());
    EXPECT_EQ(true, md2.allocated());
    EXPECT_EQ(false, md2.deallocated());

    for (const auto &el: md2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_NE(md1, md2);
}

TEST(md_set_matrix_via_move_constructor_uint64_t, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value2);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2(std::move(md1));

    EXPECT_EQ(false, md1.allocated());
    EXPECT_EQ(true, md1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), md1.size());
    EXPECT_EQ(true, md2.allocated());
    EXPECT_EQ(false, md2.deallocated());

    for (const auto &el: md2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_NE(md1, md2);
}

TEST(md_set_matrix_via_move_constructor_int64_t, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value3);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2(std::move(md1));

    EXPECT_EQ(false, md1.allocated());
    EXPECT_EQ(true, md1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), md1.size());
    EXPECT_EQ(true, md2.allocated());
    EXPECT_EQ(false, md2.deallocated());

    for (const auto &el: md2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_NE(md1, md2);
}

TEST(md_set_matrix_via_move_assignment_operator_double, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value1);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2;
    md2 = std::move(md1);

    EXPECT_EQ(false, md1.allocated());
    EXPECT_EQ(true, md1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), md1.size());
    EXPECT_EQ(true, md2.allocated());
    EXPECT_EQ(false, md2.deallocated());

    for (const auto &el: md2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_NE(md1, md2);
}

TEST(md_set_matrix_via_move_assignment_operator_uint64_t, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value2);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2;
    md2 = std::move(md1);

    EXPECT_EQ(false, md1.allocated());
    EXPECT_EQ(true, md1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), md1.size());
    EXPECT_EQ(true, md2.allocated());
    EXPECT_EQ(false, md2.deallocated());

    for (const auto &el: md2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_NE(md1, md2);
}

TEST(md_set_matrix_via_move_assignment_operator_int64_t, set_get) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value3);

    EXPECT_EQ(rows * columns, md1.size());

    dense_matrix<double> md2;
    md2 = std::move(md1);

    EXPECT_EQ(false, md1.allocated());
    EXPECT_EQ(true, md1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), md1.size());
    EXPECT_EQ(true, md2.allocated());
    EXPECT_EQ(false, md2.deallocated());

    for (const auto &el: md2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_NE(md1, md2);
}
