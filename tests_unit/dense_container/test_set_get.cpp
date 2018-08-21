#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../dense_container/dense_container.h"

using sepolia::dense_container;

const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
const double value1 = 123.456;
const uint64_t value2 = 123456;
const int64_t value3 = 456789;

TEST(dcon_set_element_via_constructor_and_get_it_double, set_get) {

    dense_container<double> dcon(dimension, value1);

    for (const auto &el: dcon) {

        EXPECT_EQ(value1, el);
    }
}

TEST(dcon_set_element_via_constructor_and_get_it_uint64_t, set_get) {

    dense_container<uint64_t> dcon(dimension, value2);

    for (const auto &el: dcon) {

        EXPECT_EQ(value2, el);
    }
}

TEST(dcon_set_element_via_constructor_and_get_it_int64_t, set_get) {

    dense_container<int64_t> dcon(dimension, value3);

    for (const auto &el: dcon) {

        EXPECT_EQ(value3, el);
    }
}

TEST(dcon_set_dimension_via_constructor_and_get_it_double, set_get) {

    dense_container<double> dcon(dimension);

    EXPECT_EQ(dimension, dcon.size());
}

TEST(dcon_set_dimension_via_constructor_and_get_it_uint64_t, set_get) {

    dense_container<uint64_t> dcon(dimension);

    EXPECT_EQ(dimension, dcon.size());
}

TEST(dcon_set_dimension_via_constructor_and_get_it_int64_t, set_get) {

    dense_container<int64_t> dcon(dimension);

    EXPECT_EQ(dimension, dcon.size());
}

TEST(dcon_set_dimension_via_allocate_and_get_it_double, set_get) {

    dense_container<double> dcon;
    dcon.allocate(dimension);

    EXPECT_EQ(dimension, dcon.size());
}

TEST(dcon_set_dimension_via_allocate_and_get_it_uint64_t, set_get) {

    dense_container<uint64_t> dcon;
    dcon.allocate(dimension);

    EXPECT_EQ(dimension, dcon.size());
}

TEST(dcon_set_dimension_via_allocate_and_get_it_int64_t, set_get) {

    dense_container<int64_t> dcon;
    dcon.allocate(dimension);

    EXPECT_EQ(dimension, dcon.size());
}

TEST(dcon_set_element_and_get_it_double, set_get) {

    dense_container<double> dcon(dimension);

    EXPECT_EQ(dimension, dcon.size());

    for (uint64_t i = 0; i < dimension; i++) {

        dcon(i) = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(dcon(i), static_cast<double>(i));
    }
}

TEST(dcon_set_element_and_get_it_uint64_t, set_get) {

    dense_container<uint64_t> dcon(dimension);

    EXPECT_EQ(dimension, dcon.size());

    // curved brackets

    for (uint64_t i = 0; i < dimension; i++) {

        dcon(i) = i;
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(i, dcon(i));
    }

    // square brackets

    for (uint64_t i = 0; i < dimension; i++) {

        dcon[i] = i;
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(i, dcon[i]);
    }
}

TEST(dcon_set_element_and_get_it_int64_t, set_get) {

    dense_container<int64_t> dcon(dimension);

    EXPECT_EQ(dimension, dcon.size());

    // curved brackets

    for (uint64_t i = 0; i < dimension; i++) {

        dcon(i) = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(static_cast<int64_t>(i), dcon(i));
    }

    // square brackets

    for (uint64_t i = 0; i < dimension; i++) {

        dcon[i] = static_cast<int64_t>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {

        EXPECT_EQ(static_cast<int64_t>(i), dcon[i]);
    }
}

TEST(dcon_set_vector_to_another_using_assignment_operator_double, set_get) {

    dense_container<double> dcon1(dimension, value1);
    dense_container<double> dcon2;

    EXPECT_EQ(dimension, dcon1.size());

    for (const auto &el: dcon1) {

        EXPECT_EQ(value1, el);
    }

    dcon2 = dcon1;

    EXPECT_EQ(dimension, dcon2.size());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_EQ(dcon1, dcon2);

}

TEST(dcon_set_vector_via_copy_constructor_double, set_get) {

    dense_container<double> dcon1(dimension, value1);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2(dcon1);

    EXPECT_EQ(dimension, dcon1.size());

    for (const auto &el: dcon1) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_EQ(dimension, dcon2.size());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value1, el);
    }
}

TEST(dcon_set_vector_via_copy_constructor_uint64_t, set_get) {

    dense_container<uint64_t> dcon1(dimension, value2);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<uint64_t> dcon2(dcon1);

    EXPECT_EQ(dimension, dcon1.size());

    for (const auto &el: dcon1) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_EQ(dimension, dcon2.size());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_set_vector_via_copy_constructor_int64_t, set_get) {

    dense_container<int64_t> dcon1(dimension, value3);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<int64_t> dcon2(dcon1);

    EXPECT_EQ(dimension, dcon1.size());

    for (const auto &el: dcon1) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_EQ(dimension, dcon2.size());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_set_vector_via_move_constructor_double, set_get) {

    dense_container<double> dcon1(dimension, value1);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2(std::move(dcon1));

    EXPECT_EQ(false, dcon1.allocated());
    EXPECT_EQ(true, dcon1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), dcon1.size());
    EXPECT_EQ(true, dcon2.allocated());
    EXPECT_EQ(false, dcon2.deallocated());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_NE(dcon1, dcon2);
}

TEST(dcon_set_vector_via_move_constructor_uint64_t, set_get) {

    dense_container<double> dcon1(dimension, value2);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2(std::move(dcon1));

    EXPECT_EQ(false, dcon1.allocated());
    EXPECT_EQ(true, dcon1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), dcon1.size());
    EXPECT_EQ(true, dcon2.allocated());
    EXPECT_EQ(false, dcon2.deallocated());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_NE(dcon1, dcon2);
}

TEST(dcon_set_vector_via_move_constructor_int64_t, set_get) {

    dense_container<double> dcon1(dimension, value3);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2(std::move(dcon1));

    EXPECT_EQ(false, dcon1.allocated());
    EXPECT_EQ(true, dcon1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), dcon1.size());
    EXPECT_EQ(true, dcon2.allocated());
    EXPECT_EQ(false, dcon2.deallocated());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_NE(dcon1, dcon2);
}

TEST(dcon_set_vector_via_move_assignment_operator_double, set_get) {

    dense_container<double> dcon1(dimension, value1);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2;
    dcon2 = std::move(dcon1);

    EXPECT_EQ(false, dcon1.allocated());
    EXPECT_EQ(true, dcon1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), dcon1.size());
    EXPECT_EQ(true, dcon2.allocated());
    EXPECT_EQ(false, dcon2.deallocated());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value1, el);
    }

    EXPECT_NE(dcon1, dcon2);
}

TEST(dcon_set_vector_via_move_assignment_operator_uint64_t, set_get) {

    dense_container<double> dcon1(dimension, value2);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2;
    dcon2 = std::move(dcon1);

    EXPECT_EQ(false, dcon1.allocated());
    EXPECT_EQ(true, dcon1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), dcon1.size());
    EXPECT_EQ(true, dcon2.allocated());
    EXPECT_EQ(false, dcon2.deallocated());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value2, el);
    }

    EXPECT_NE(dcon1, dcon2);
}

TEST(dcon_set_vector_via_move_assignment_operator_int64_t, set_get) {

    dense_container<double> dcon1(dimension, value3);

    EXPECT_EQ(dimension, dcon1.size());

    dense_container<double> dcon2;
    dcon2 = std::move(dcon1);

    EXPECT_EQ(false, dcon1.allocated());
    EXPECT_EQ(true, dcon1.deallocated());
    EXPECT_EQ(static_cast<uint64_t>(0), dcon1.size());
    EXPECT_EQ(true, dcon2.allocated());
    EXPECT_EQ(false, dcon2.deallocated());

    for (const auto &el: dcon2) {

        EXPECT_EQ(value3, el);
    }

    EXPECT_NE(dcon1, dcon2);
}
