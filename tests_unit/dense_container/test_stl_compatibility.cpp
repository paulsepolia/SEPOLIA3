#include <gtest/gtest.h>
#include <cmath>
#include <cstdlib>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const uint64_t dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
const uint64_t dim2 = static_cast<uint64_t>(std::pow(10.0, 3.0));
const double value1 = 123.456;
const uint64_t value2 = 123456;

// help functions and classes

bool sort_fun(double i, double j) {

    return (i < j);
}

bool sort_fun_reverse(double i, double j) {

    return (i > j);
}

struct sort_class {

    bool operator()(double i, double j) {

        return (i < j);
    }
};

struct sort_class_reverse {
    bool operator()(double i, double j) {

        return (i > j);
    }
};

double rand_num() {

    return static_cast<double>(std::rand() % 100);
}

// help functors

sort_class sort_obj;
sort_class_reverse sort_obj_reverse;

TEST(dcon_for_each, stl_compatibility) {

    dense_container<double> dcon1;
    dense_container<double> dcon2;

    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        dcon1[i] = static_cast<double>(i);
    }

    dcon2 = dcon1;
    dcon2++;

    std::for_each(dcon1.begin(), dcon1.end(), [](double &x) { x++; });

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_generate, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);

    double x(0);
    std::generate(dcon.begin(), dcon.end(), [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun));

    std::sort(dcon.begin(), dcon.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun_reverse));
}

TEST(dcon_generate_n, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);

    double x(0);
    std::generate_n(dcon.begin(), dimension, [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun));

    std::sort(dcon.begin(), dcon.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun_reverse));
}

TEST(dcon_includes_equal_vectors, stl_compatibility) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value1);

    EXPECT_TRUE(std::includes(dcon1.begin(), dcon1.end(), dcon2.begin(), dcon2.end()));
}

TEST(dcon_includes_same_vector, stl_compatibility) {

    dense_container<double> dcon1(dimension);

    dcon1.set(value1);

    EXPECT_TRUE(std::includes(dcon1.begin(), dcon1.end(), dcon1.begin(), dcon1.end()));
}

TEST(dcon_includes_sorted, stl_compatibility) {

    dense_container<double> dcon1;
    dense_container<double> dcon2;

    dcon1.allocate(dim2);
    dcon2.allocate(dim2 - 1);

    double x(0);
    std::generate_n(dcon1.begin(), dcon1.size(), [&x] { return x++; });

    x = 0;
    std::generate_n(dcon2.begin(), dcon2.size(), [&x] { return x++; });

    EXPECT_TRUE(std::includes(dcon1.begin(), dcon1.end(), dcon2.begin(), dcon2.end()));
}

TEST(dcon_includes_sorted_reverse, stl_compatibility) {

    dense_container<double> dcon1;
    dense_container<double> dcon2;

    dcon1.allocate(dim2);
    dcon2.allocate(dim2);

    double x(0);
    std::generate_n(dcon1.begin(), dcon1.size(), [&x] { return x--; });

    x = 0;
    std::generate_n(dcon2.begin(), dcon2.size(), [&x] { return x--; });

    EXPECT_TRUE(std::includes(dcon1.begin(), dcon1.end(), dcon2.begin(), dcon2.end(), sort_obj_reverse));
}

TEST(dcon_is_sorted_default, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);
    dcon = value1;

    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun));

    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun_reverse));
}

TEST(dcon_is_sorted_non_default, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);

    std::generate(dcon.begin(), dcon.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end(), sort_obj));
    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end(), sort_fun));

    std::sort(dcon.begin(), dcon.end());

    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end()));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun));
}

TEST(dcon_is_sorted_non_default_reverse, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);

    std::generate(dcon.begin(), dcon.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end(), sort_obj_reverse));
    EXPECT_EQ(false, std::is_sorted(dcon.begin(), dcon.end(), sort_fun_reverse));

    std::sort(dcon.begin(), dcon.end(), sort_obj_reverse);

    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(dcon.begin(), dcon.end(), sort_fun_reverse));
}

TEST(dcon_reverse_constructor_default, stl_compatibility) {

    dense_container<double> dcon1;
    dense_container<double> dcon2;

    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        dcon1[i] = static_cast<double>(i);
    }

    dcon2 = dcon1;

    std::reverse(dcon1.begin(), dcon1.end());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, dcon1[i]);
    }

    std::reverse(dcon1.begin(), dcon1.end());

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_reverse_constructor_one, stl_compatibility) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        dcon1[i] = static_cast<double>(i);
    }

    dcon2 = dcon1;

    std::reverse(dcon1.begin(), dcon1.end());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, dcon1[i]);
    }

    std::reverse(dcon1.begin(), dcon1.end());

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_reverse_constructor_value, stl_compatibility) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value1);

    EXPECT_EQ(dcon1, dcon2);

    std::reverse(dcon1.begin(), dcon1.end());

    EXPECT_EQ(dcon1, dcon2);

    std::reverse(dcon1.begin(), dcon1.end());

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_reverse_copy_constructor_default, stl_compatibility) {

    dense_container<double> dcon1;
    dense_container<double> dcon2;

    dcon1.allocate(dimension);
    dcon2.allocate(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        dcon1[i] = static_cast<double>(i);
    }

    std::reverse_copy(dcon1.begin(), dcon1.end(), dcon2.begin());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, dcon2[i]);
    }

    std::reverse(dcon2.begin(), dcon2.end());

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_reverse_copy_constructor_one, stl_compatibility) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        dcon1[i] = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {
        dcon1[i] = static_cast<double>(i);
    }

    std::reverse_copy(dcon1.begin(), dcon1.end(), dcon2.begin());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, dcon2[i]);
    }

    std::reverse(dcon2.begin(), dcon2.end());

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_reverse_copy_constructor_one_value, stl_compatibility) {

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value1);

    EXPECT_EQ(dcon1, dcon2);

    dcon2 = value2;

    EXPECT_EQ(dcon2, value2);

    std::reverse_copy(dcon1.begin(), dcon1.end(), dcon2.begin());

    EXPECT_EQ(dcon1, dcon2);
}

TEST(dcon_sort_default, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);

    for (uint64_t i = 0; i != dcon.size(); i++) {
        dcon[i] = static_cast<double>(i);
    }

    std::reverse(dcon.begin(), dcon.end());

    std::sort(dcon.begin(), dcon.end());

    for (uint64_t i = 0; i != dcon.size(); i++) {
        EXPECT_EQ(i, dcon[i]);
    }
}

TEST(dcon_sort_non_default, stl_compatibility) {

    dense_container<double> dcon;

    dcon.allocate(dimension);

    for (uint64_t i = 0; i != dcon.size(); i++) {
        dcon[i] = static_cast<double>(i);
    }

    std::reverse(dcon.begin(), dcon.end());

    std::sort(dcon.begin(), dcon.end(), sort_fun);

    for (uint64_t i = 0; i != dcon.size(); i++) {
        EXPECT_EQ(i, dcon[i]);
    }

    std::reverse(dcon.begin(), dcon.end());

    std::sort(dcon.begin(), dcon.end(), sort_obj);

    for (uint64_t i = 0; i != dcon.size(); i++) {
        EXPECT_EQ(i, dcon[i]);
    }
}
