#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

TEST(in_place_transpose_double, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = rows;

    dense_matrix<double> md(rows, columns);

    // build local test matrix

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md(i, j) = static_cast<double>(i);
        }
    }

    sepolia::Transpose(md);

    // build the matrix to compare

    dense_matrix<double> md_res(rows, columns);

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md_res(j, i) = static_cast<double>(i);
        }
    }

    // compare

    EXPECT_EQ(md, md_res);
}

TEST(in_place_transpose_float, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = rows;

    dense_matrix<float> md(rows, columns);

    // build local test matrix

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md(i, j) = static_cast<float>(i);
        }
    }

    sepolia::Transpose(md);

    // build the matrix to compare

    dense_matrix<float> md_res(rows, columns);

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md_res(j, i) = static_cast<float>(i);
        }
    }

    // compare

    EXPECT_EQ(md, md_res);
}

TEST(in_place_transpose_mkl_complex8, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = rows;

    dense_matrix<MKL_Complex8> md(rows, columns);

    // build local test matrix

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md(i, j) = {static_cast<float>(i), 0};
        }
    }

    sepolia::Transpose(md);

    // build the matrix to compare

    dense_matrix<MKL_Complex8> md_res(rows, columns);

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md_res(j, i) = {static_cast<float>(i), 0};
        }
    }

    // compare

    EXPECT_EQ(md, md_res);
}

TEST(in_place_transpose_mkl_complex16, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = rows;

    dense_matrix<MKL_Complex16> md(rows, columns);

    // build local test matrix

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md(i, j) = {static_cast<double>(i), 0};
        }
    }

    sepolia::Transpose(md);

    // build the matrix to compare

    dense_matrix<MKL_Complex16> md_res(rows, columns);

    for (uint64_t i = 0; i < md.rows(); i++) {
        for (uint64_t j = 0; j < md.columns(); j++) {
            md_res(j, i) = {static_cast<double>(i), 0};
        }
    }

    // compare

    EXPECT_EQ(md, md_res);
}

TEST(out_place_transpose_double, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 3.0));

    dense_matrix<double> md1(rows, columns);
    dense_matrix<double> md2(columns, rows);

    // build local test matrix

    for (uint64_t i = 0; i < md1.rows(); i++) {
        for (uint64_t j = 0; j < md1.columns(); j++) {
            md1(i, j) = static_cast<double>(i);
        }
    }

    const auto md3 = md1;
    md1.deallocate();

    md2 = sepolia::Transpose(md3);

    // build the matrix to compare

    dense_matrix<double> md_res(columns, rows);

    for (uint64_t i = 0; i < md_res.rows(); i++) {
        for (uint64_t j = 0; j < md_res.columns(); j++) {
            md_res(i, j) = static_cast<double>(j);
        }
    }

    // compare

    EXPECT_EQ(md2, md_res);
}

TEST(out_place_transpose_float, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 3.0));

    dense_matrix<float> md1(rows, columns);
    dense_matrix<float> md2(columns, rows);

    // build local test matrix

    for (uint64_t i = 0; i < md1.rows(); i++) {
        for (uint64_t j = 0; j < md1.columns(); j++) {
            md1(i, j) = static_cast<float>(i);
        }
    }

    const auto md3 = md1;
    md1.deallocate();

    md2 = sepolia::Transpose(md3);

    // build the matrix to compare

    dense_matrix<float> md_res(columns, rows);

    for (uint64_t i = 0; i < md_res.rows(); i++) {
        for (uint64_t j = 0; j < md_res.columns(); j++) {
            md_res(i, j) = static_cast<float>(j);
        }
    }

    // compare

    EXPECT_EQ(md2, md_res);
}

TEST(out_place_transpose_mkl_complex8, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 3.0));

    dense_matrix<MKL_Complex8> md1(rows, columns);
    dense_matrix<MKL_Complex8> md2(columns, rows);

    // build local test matrix

    for (uint64_t i = 0; i < md1.rows(); i++) {
        for (uint64_t j = 0; j < md1.columns(); j++) {
            md1(i, j) = {static_cast<float>(i), 0};
        }
    }

    const auto md3 = md1;
    md1.deallocate();

    md2 = sepolia::Transpose(md3);

    // build the matrix to compare

    dense_matrix<MKL_Complex8> md_res(columns, rows);

    for (uint64_t i = 0; i < md_res.rows(); i++) {
        for (uint64_t j = 0; j < md_res.columns(); j++) {
            md_res(i, j) = {static_cast<float>(j), 0};
        }
    }

    // compare

    EXPECT_EQ(md2, md_res);
}

TEST(out_place_transpose_mkl_complex16, transpose) {

    const auto rows = static_cast<uint64_t>(std::pow(10.0, 2.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 3.0));

    dense_matrix<MKL_Complex16> md1(rows, columns);
    dense_matrix<MKL_Complex16> md2(columns, rows);

    // build local test matrix

    for (uint64_t i = 0; i < md1.rows(); i++) {
        for (uint64_t j = 0; j < md1.columns(); j++) {
            md1(i, j) = {static_cast<double>(i), 0};
        }
    }

    const auto md3 = md1;
    md1.deallocate();

    md2 = sepolia::Transpose(md3);

    // build the matrix to compare

    dense_matrix<MKL_Complex16> md_res(columns, rows);

    for (uint64_t i = 0; i < md_res.rows(); i++) {
        for (uint64_t j = 0; j < md_res.columns(); j++) {
            md_res(i, j) = {static_cast<double>(j), 0};
        }
    }

    // compare

    EXPECT_EQ(md2, md_res);
}