#include <gtest/gtest.h>
#include <cmath>
#include <cstdlib>
#include "../../dense_vector/dense_vector.h"

const uint64_t dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
const uint64_t dim2 = static_cast<uint64_t>(std::pow(10.0, 3.0));
const double value1 = 123.456;
const uint64_t value2 = 123456;

using sepolia::dense_vector;

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

TEST(vd_for_each, stl_compatibility) {

    dense_vector<double> vd1;
    dense_vector<double> vd2;

    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        vd1[i] = static_cast<double>(i);
    }

    vd2 = vd1;
    vd2++;

    std::for_each(vd1.begin(), vd1.end(), [](double &x) { x++; });

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_generate, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);

    double x(0);
    std::generate(vd.begin(), vd.end(), [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    std::sort(vd.begin(), vd.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

TEST(vd_generate_n, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);

    double x(0);
    std::generate_n(vd.begin(), dimension, [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    std::sort(vd.begin(), vd.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

TEST(vd_includes_equal_vectors, stl_compatibility) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1.set(value1);
    vd2.set(value1);

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd2.begin(), vd2.end()));
}

TEST(vd_includes_same_vector, stl_compatibility) {

    dense_vector<double> vd1(dimension);

    vd1.set(value1);

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd1.begin(), vd1.end()));
}

TEST(vd_includes_sorted, stl_compatibility) {

    dense_vector<double> vd1;
    dense_vector<double> vd2;

    vd1.allocate(dim2);
    vd2.allocate(dim2 - 1);

    double x(0);
    std::generate_n(vd1.begin(), vd1.size(), [&x] { return x++; });

    x = 0;
    std::generate_n(vd2.begin(), vd2.size(), [&x] { return x++; });

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd2.begin(), vd2.end()));
}

TEST(vd_includes_sorted_reverse, stl_compatibility) {

    dense_vector<double> vd1;
    dense_vector<double> vd2;

    vd1.allocate(dim2);
    vd2.allocate(dim2);

    double x(0);
    std::generate_n(vd1.begin(), vd1.size(), [&x] { return x--; });

    x = 0;
    std::generate_n(vd2.begin(), vd2.size(), [&x] { return x--; });

    EXPECT_TRUE(std::includes(vd1.begin(), vd1.end(), vd2.begin(), vd2.end(), sort_obj_reverse));
}

TEST(vd_is_sorted_default, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);
    vd = value1;

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

TEST(vd_is_sorted_non_default, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);

    std::generate(vd.begin(), vd.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_fun));

    std::sort(vd.begin(), vd.end());

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end()));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun));
}

TEST(vd_is_sorted_non_default_reverse, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);

    std::generate(vd.begin(), vd.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(false, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));

    std::sort(vd.begin(), vd.end(), sort_obj_reverse);

    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(vd.begin(), vd.end(), sort_fun_reverse));
}

TEST(vd_reverse_constructor_default, stl_compatibility) {

    dense_vector<double> vd1;
    dense_vector<double> vd2;

    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        vd1[i] = static_cast<double>(i);
    }

    vd2 = vd1;

    std::reverse(vd1.begin(), vd1.end());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, vd1[i]);
    }

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_reverse_constructor_one, stl_compatibility) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        vd1[i] = static_cast<double>(i);
    }

    vd2 = vd1;

    std::reverse(vd1.begin(), vd1.end());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, vd1[i]);
    }

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_reverse_constructor_two, stl_compatibility) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1.set(value1);
    vd2.set(value1);

    EXPECT_EQ(vd1, vd2);

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);

    std::reverse(vd1.begin(), vd1.end());

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_reverse_copy_constructor_default, stl_compatibility) {

    dense_vector<double> vd1;
    dense_vector<double> vd2;

    vd1.allocate(dimension);
    vd2.allocate(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        vd1[i] = static_cast<double>(i);
    }

    std::reverse_copy(vd1.begin(), vd1.end(), vd2.begin());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, vd2[i]);
    }

    std::reverse(vd2.begin(), vd2.end());

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_reverse_copy_constructor_one, stl_compatibility) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    for (uint64_t i = 0; i < dimension; i++) {
        vd1[i] = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {
        vd1[i] = static_cast<double>(i);
    }

    std::reverse_copy(vd1.begin(), vd1.end(), vd2.begin());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, vd2[i]);
    }

    std::reverse(vd2.begin(), vd2.end());

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_reverse_copy_constructor_two, stl_compatibility) {

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1.set(value1);
    vd2.set(value1);

    EXPECT_EQ(vd1, vd2);

    vd2 = value2;

    EXPECT_EQ(vd2, value2);

    std::reverse_copy(vd1.begin(), vd1.end(), vd2.begin());

    EXPECT_EQ(vd1, vd2);
}

TEST(vd_sort_default, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);

    for (uint64_t i = 0; i != vd.size(); i++) {
        vd[i] = static_cast<double>(i);
    }

    std::reverse(vd.begin(), vd.end());

    std::sort(vd.begin(), vd.end());

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(i, vd[i]);
    }
}

TEST(vd_sort_non_default, stl_compatibility) {

    dense_vector<double> vd;

    vd.allocate(dimension);

    for (uint64_t i = 0; i != vd.size(); i++) {
        vd[i] = static_cast<double>(i);
    }

    std::reverse(vd.begin(), vd.end());

    std::sort(vd.begin(), vd.end(), sort_fun);

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(i, vd[i]);
    }

    std::reverse(vd.begin(), vd.end());

    std::sort(vd.begin(), vd.end(), sort_obj);

    for (uint64_t i = 0; i != vd.size(); i++) {
        EXPECT_EQ(i, vd[i]);
    }
}
