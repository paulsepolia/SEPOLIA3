#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    const uint32_t SPACE2 = 50;
    const uint32_t TRY = 1;
    std::cout << std::boolalpha;
    const auto rows = 1 * static_cast<uint64_t>(std::pow(10.0, 4.0));
    const auto columns = 1 * static_cast<uint64_t>(std::pow(10.0, 4.0));

    // transpose double matrix inplace same value

    {
        dense_matrix<double> md;
        const double value = 123.456;

        md.allocate(rows, columns);
        md = value;

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            Transpose(md);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md == value) << std::endl;
    }

    // transpose float matrix inplace same value

    {
        dense_matrix<float> md;
        const float value = 123.456;

        md.allocate(rows, columns);
        md = value;

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            Transpose(md);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md == value) << std::endl;
    }

    // transpose double matrix outplace same value

    {
        dense_matrix<double> md1;
        dense_matrix<double> md2;

        const double value = 123.456;

        md1.allocate(rows, columns);
        md1 = value;
        const auto md_tmp = md1;

        md1.deallocate();

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md2 = Transpose(md_tmp);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md2 == value) << std::endl;
        std::cout << " --> " << (md_tmp == value) << std::endl;
        std::cout << " --> " << (md_tmp == md2) << std::endl;
    }

    // transpose float matrix outplace same value

    {
        dense_matrix<float> md1;
        dense_matrix<float> md2;

        const float value = 123.456;

        md1.allocate(rows, columns);
        md1 = value;
        const auto md_tmp = md1;

        md1.deallocate();

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md2 = Transpose(md_tmp);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md2 == value) << std::endl;
        std::cout << " --> " << (md_tmp == value) << std::endl;
        std::cout << " --> " << (md_tmp == md2) << std::endl;
    }

    // transpose MKL_Complex8 matrix inplace same value

    {
        dense_matrix<MKL_Complex8> md;
        const MKL_Complex8 value = {123.456, 345.678};

        md.allocate(rows, columns);
        md = value;

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            Transpose(md);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md == value) << std::endl;
    }

    // transpose MKL_Complex16 matrix inplace same value

    {
        dense_matrix<MKL_Complex16> md;
        const MKL_Complex16 value = {123.456, 345.678};

        md.allocate(rows, columns);
        md = value;

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            Transpose(md);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md == value) << std::endl;
    }

    // transpose MKL_Complex8 matrix outplace same value

    {
        dense_matrix<MKL_Complex8> md1;
        dense_matrix<MKL_Complex8> md2;

        const MKL_Complex8 value = {123.456, 345.678};

        md1.allocate(rows, columns);
        md1 = value;
        const auto md_tmp = md1;

        md1.deallocate();

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md2 = Transpose(md_tmp);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md2 == value) << std::endl;
        std::cout << " --> " << (md_tmp == value) << std::endl;
        std::cout << " --> " << (md_tmp == md2) << std::endl;
    }

    // transpose MKL_complex16 matrix outplace same value

    {
        dense_matrix<MKL_Complex16> md1;
        dense_matrix<MKL_Complex16> md2;

        const MKL_Complex16 value = {123.456, 345.678};

        md1.allocate(rows, columns);
        md1 = value;
        const auto md_tmp = md1;

        md1.deallocate();

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md2 = Transpose(md_tmp);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        std::cout << " --> " << (md2 == value) << std::endl;
        std::cout << " --> " << (md_tmp == value) << std::endl;
        std::cout << " --> " << (md_tmp == md2) << std::endl;
    }

    // more generic benchmarks

    // transpose MKL_complex16 matrix outplace - not same value

    {
        dense_matrix<MKL_Complex16> md1;
        dense_matrix<MKL_Complex16> md2;

        const auto rows1 = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const auto columns1 = static_cast<uint64_t>(std::pow(10.0, 3.0));

        md1.allocate(rows1, columns1);

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {

                md1(i, j) = {static_cast<double>(i), static_cast<double>(j)};
            }
        }

        const auto md_tmp = md1;

        md1.deallocate();

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md2 = Transpose(md_tmp);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        md1.allocate(columns1, rows1);

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {

                md1(i, j) = {static_cast<double>(j), static_cast<double>(i)};
            }
        }

        std::cout << " --> " << (md1 == md2) << std::endl;
    }

    // transpose MKL_complex16 matrix inplace - not same value

    {
        dense_matrix<MKL_Complex16> md1;

        const auto rows1 = static_cast<uint64_t>(std::pow(10.0, 3.0));
        const auto columns1 = static_cast<uint64_t>(std::pow(10.0, 3.0));

        md1.allocate(rows1, columns1);

        for (uint64_t i = 0; i < md1.rows(); i++) {
            for (uint64_t j = 0; j < md1.columns(); j++) {

                md1(i, j) = {static_cast<double>(i), static_cast<double>(j)};
            }
        }

        auto t1 = std::chrono::high_resolution_clock::now();

        // TRY must be odd
        for (uint32_t i = 0; i != TRY; i++) {
            Transpose(md1);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_transpose_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = Transpose(md1);"
                  << time_transpose_matrix.count() << std::endl;

        dense_matrix<MKL_Complex16> md2;
        md2.allocate(columns1, rows1);

        for (uint64_t i = 0; i < md2.rows(); i++) {
            for (uint64_t j = 0; j < md2.columns(); j++) {

                md2(i, j) = {static_cast<double>(j), static_cast<double>(i)};
            }
        }

        std::cout << " --> " << (md1 == md2) << std::endl;
    }
}
