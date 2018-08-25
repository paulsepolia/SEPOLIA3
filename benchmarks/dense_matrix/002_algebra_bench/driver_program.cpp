#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "../../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

int main() {

    const uint32_t SPACE2 = 50;
    const uint32_t TRY = 100;
    std::cout << std::boolalpha;

    const auto dimension = 1 * static_cast<uint64_t>(std::pow(10.0, 6.0));
    const double value1 = 123.456;
    const double value2 = 345.678;

    // # 1

    {
        dense_matrix<double> md1;
        dense_matrix<double> md2;
        dense_matrix<double> md3;

        md1.allocate(dimension);
        md2.allocate(dimension);

        md1 = value1;
        md2 = value2;

        // add matrices

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 + md2;
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 + md2;"
                  << time_add_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 + md2) << std::endl;
        std::cout << " --> " << (md3 == value1 + value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // subtract matrices

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 - md2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 - md2;"
                  << time_subtract_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 - md2) << std::endl;
        std::cout << " --> " << (md3 == value1 - value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // multiply matrices

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 * md2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 * md2;"
                  << time_multiply_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 * md2) << std::endl;
        std::cout << " --> " << (md3 == value1 * value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // divide matrices

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 / md2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 / md2;"
                  << time_divide_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 / md2) << std::endl;
        std::cout << " --> " << (md3 == value1 / value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // add matrices element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != md1.size(); j++) {
                md3[j] = md1[j] + md2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_matrices_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3[j] = md1[j] + md2[j];"
                  << time_add_matrices_el_by_el.count() << std::endl;

        std::cout << " --> " << (md3 == md1 + md2) << std::endl;
        std::cout << " --> " << (md3 == value1 + value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // subtract matrices element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != md1.size(); j++) {
                md3[j] = md1[j] - md2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_matrices_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3[j] = md1[j] - md2[j];"
                  << time_subtract_matrices_el_by_el.count() << std::endl;

        std::cout << " --> " << (md3 == md1 - md2) << std::endl;
        std::cout << " --> " << (md3 == value1 - value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // multiply matrices element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != md1.size(); j++) {
                md3[j] = md1[j] * md2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_matrices_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3[j] = md1[j] * md2[j];"
                  << time_multiply_matrices_el_by_el.count() << std::endl;

        std::cout << " --> " << (md3 == md1 * md2) << std::endl;
        std::cout << " --> " << (md3 == value1 * value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;

        // divide matrices element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != md1.size(); j++) {
                md3[j] = md1[j] / md2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_matrices_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3[j] = md1[j] / md2[j];"
                  << time_divide_matrices_el_by_el.count() << std::endl;

        std::cout << " --> " << (md3 == md1 / md2) << std::endl;
        std::cout << " --> " << (md3 == value1 / value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
        std::cout << " --> " << (md2 == value2) << std::endl;
    }

    // # 2

    {
        dense_matrix<double> md1;
        dense_matrix<double> md3;

        md1.allocate(dimension);

        md1 = value1;

        // add matrix with value

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 + value2;
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 + value2;"
                  << time_add_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 + value2) << std::endl;
        std::cout << " --> " << (md3 == value1 + value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;

        // subtract value from matrices

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 - value2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 - value2;"
                  << time_subtract_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 - value2) << std::endl;
        std::cout << " --> " << (md3 == value1 - value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;

        // multiply matrices with value

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 * value2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 * value2;"
                  << time_multiply_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 * value2) << std::endl;
        std::cout << " --> " << (md3 == value1 * value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;

        // divide matrices with value

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = md1 / value2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = md1 / value2;"
                  << time_divide_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 / value2) << std::endl;
        std::cout << " --> " << (md3 == value1 / value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
    }

    // # 3

    {

        dense_matrix<double> md1;
        dense_matrix<double> md3;

        md1.allocate(dimension);

        md1 = value1;

        // add value with matrix

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = value2 + md1;
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = value2 + md1;"
                  << time_add_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == md1 + value2) << std::endl;
        std::cout << " --> " << (md3 == value1 + value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;

        // subtract matrix form value

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = value2 - md1;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = value2 - md1;"
                  << time_subtract_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == value2 - md1) << std::endl;
        std::cout << " --> " << (md3 == value2 - value1) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;

        // multiply value with matrix

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = value2 * md1;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = value2 * md1;"
                  << time_multiply_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == value2 * md1) << std::endl;
        std::cout << " --> " << (md3 == value1 * value2) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;

        // divide value by matrix

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = value2 / md1;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_matrices =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = value2 / md1;"
                  << time_divide_matrices.count() << std::endl;

        std::cout << " --> " << (md3 == value2 / md1) << std::endl;
        std::cout << " --> " << (md3 == value2 / value1) << std::endl;
        std::cout << " --> " << (md1 == value1) << std::endl;
    }
}
