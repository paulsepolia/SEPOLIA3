#include <gtest/gtest.h>
#include <cmath>
#include <cstdlib>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

const auto rows = static_cast<uint64_t>(std::pow(10.0, 1.0));
const auto columns = static_cast<uint64_t>(std::pow(10.0, 1.0));
const auto dimension = rows * columns;
const double value1 = 123.456;
const uint64_t value2 = 123456;

using sepolia::dense_matrix;

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

TEST(md_for_each, stl_compatibility) {

    dense_matrix<double> md1;
    dense_matrix<double> md2;

    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i < dimension; i++) {
        md1[i] = static_cast<double>(i);
    }

    md2 = md1;
    md2++;

    std::for_each(md1.begin(), md1.end(), [](double &x) { x++; });

    EXPECT_EQ(md1, md2);
}

TEST(md_generate, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);

    double x(0);
    std::generate(md.begin(), md.end(), [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun));

    std::sort(md.begin(), md.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun_reverse));
}

TEST(md_generate_n, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);

    double x(0);
    std::generate_n(md.begin(), dimension, [&x] { return x++; });

    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun));

    std::sort(md.begin(), md.end(), sort_obj_reverse);

    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun_reverse));
}

TEST(md_includes_equal_matrixs, stl_compatibility) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value1);

    EXPECT_TRUE(std::includes(md1.begin(), md1.end(), md2.begin(), md2.end()));
}

TEST(md_includes_same_matrix, stl_compatibility) {

    dense_matrix<double> md1(rows, columns);

    md1.set(value1);

    EXPECT_TRUE(std::includes(md1.begin(), md1.end(), md1.begin(), md1.end()));
}

TEST(md_includes_sorted, stl_compatibility) {

    dense_matrix<double> md1;
    dense_matrix<double> md2;

    md1.allocate(rows, columns);
    md2.allocate(rows, columns - 1);

    double x(0);
    std::generate_n(md1.begin(), md1.size(), [&x] { return x++; });

    x = 0;
    std::generate_n(md2.begin(), md2.size(), [&x] { return x++; });

    EXPECT_TRUE(std::includes(md1.begin(), md1.end(), md2.begin(), md2.end()));
}

TEST(md_includes_sorted_reverse, stl_compatibility) {

    dense_matrix<double> md1;
    dense_matrix<double> md2;

    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    double x(0);
    std::generate_n(md1.begin(), md1.size(), [&x] { return x--; });

    x = 0;
    std::generate_n(md2.begin(), md2.size(), [&x] { return x--; });

    EXPECT_TRUE(std::includes(md1.begin(), md1.end(), md2.begin(), md2.end(), sort_obj_reverse));
}

TEST(md_is_sorted_default, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);
    md = value1;

    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun_reverse));
}

TEST(md_is_sorted_non_default, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);

    std::generate(md.begin(), md.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end(), sort_obj));
    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end(), sort_fun));

    std::sort(md.begin(), md.end());

    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end()));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun));
}

TEST(md_is_sorted_non_default_reverse, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);

    std::generate(md.begin(), md.end(), rand_num);

    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end(), sort_obj_reverse));
    EXPECT_EQ(false, std::is_sorted(md.begin(), md.end(), sort_fun_reverse));

    std::sort(md.begin(), md.end(), sort_obj_reverse);

    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_obj_reverse));
    EXPECT_EQ(true, std::is_sorted(md.begin(), md.end(), sort_fun_reverse));
}

TEST(md_reverse_constructor_default, stl_compatibility) {

    dense_matrix<double> md1;
    dense_matrix<double> md2;

    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i < dimension; i++) {
        md1[i] = static_cast<double>(i);
    }

    md2 = md1;

    std::reverse(md1.begin(), md1.end());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, md1[i]);
    }

    std::reverse(md1.begin(), md1.end());

    EXPECT_EQ(md1, md2);
}

TEST(md_reverse_constructor_one, stl_compatibility) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    for (uint64_t i = 0; i < dimension; i++) {
        md1[i] = static_cast<double>(i);
    }

    md2 = md1;

    std::reverse(md1.begin(), md1.end());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, md1[i]);
    }

    std::reverse(md1.begin(), md1.end());

    EXPECT_EQ(md1, md2);
}

TEST(md_reverse_constructor_one_value, stl_compatibility) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value1);

    EXPECT_EQ(md1, md2);

    std::reverse(md1.begin(), md1.end());

    EXPECT_EQ(md1, md2);

    std::reverse(md1.begin(), md1.end());

    EXPECT_EQ(md1, md2);
}

TEST(md_reverse_copy_constructor_default, stl_compatibility) {

    dense_matrix<double> md1;
    dense_matrix<double> md2;

    md1.allocate(rows, columns);
    md2.allocate(rows, columns);

    for (uint64_t i = 0; i < dimension; i++) {
        md1[i] = static_cast<double>(i);
    }

    std::reverse_copy(md1.begin(), md1.end(), md2.begin());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, md2[i]);
    }

    std::reverse(md2.begin(), md2.end());

    EXPECT_EQ(md1, md2);
}

TEST(md_reverse_copy_constructor_one, stl_compatibility) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    for (uint64_t i = 0; i < dimension; i++) {
        md1[i] = static_cast<double>(i);
    }

    for (uint64_t i = 0; i < dimension; i++) {
        md1[i] = static_cast<double>(i);
    }

    std::reverse_copy(md1.begin(), md1.end(), md2.begin());

    for (uint64_t i = 0; i < dimension; i++) {
        EXPECT_EQ(dimension - 1 - i, md2[i]);
    }

    std::reverse(md2.begin(), md2.end());

    EXPECT_EQ(md1, md2);
}

TEST(md_reverse_copy_constructor_one_value, stl_compatibility) {

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(rows, columns);

    md1.set(value1);
    md2.set(value1);

    EXPECT_EQ(md1, md2);

    md2 = value2;

    EXPECT_EQ(md2, value2);

    std::reverse_copy(md1.begin(), md1.end(), md2.begin());

    EXPECT_EQ(md1, md2);
}

TEST(md_sort_default, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);

    for (uint64_t i = 0; i != md.size(); i++) {
        md[i] = static_cast<double>(i);
    }

    std::reverse(md.begin(), md.end());

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_EQ(dimension - 1 - i, md[i]);
    }

    std::sort(md.begin(), md.end());

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_EQ(i, md[i]);
    }
}

TEST(md_sort_non_default, stl_compatibility) {

    dense_matrix<double> md;

    md.allocate(rows, columns);

    for (uint64_t i = 0; i != md.size(); i++) {
        md[i] = static_cast<double>(i);
    }

    std::reverse(md.begin(), md.end());

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_EQ(dimension - 1 - i, md[i]);
    }

    std::sort(md.begin(), md.end(), sort_fun);

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_EQ(i, md[i]);
    }

    std::reverse(md.begin(), md.end());

    std::sort(md.begin(), md.end(), sort_obj);

    for (uint64_t i = 0; i != md.size(); i++) {
        EXPECT_EQ(i, md[i]);
    }
}
