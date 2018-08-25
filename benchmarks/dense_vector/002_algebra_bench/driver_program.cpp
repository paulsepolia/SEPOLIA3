#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "../../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

int main() {

    const uint32_t SPACE2 = 50;
    const uint32_t TRY = 100;
    std::cout << std::boolalpha;

    const auto dimension = 1 * static_cast<uint64_t>(std::pow(10.0, 6.0));
    const double value1 = 123.456;
    const double value2 = 345.678;

    // # 1

    {
        dense_vector<double> vd1;
        dense_vector<double> vd2;
        dense_vector<double> vd3;

        vd1.allocate(dimension);
        vd2.allocate(dimension);

        vd1 = value1;
        vd2 = value2;

        // add vectors

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 + vd2;
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 + vd2;"
                  << time_add_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 + vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 + value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // subtract vectors

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 - vd2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 - vd2;"
                  << time_subtract_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 - vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 - value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // multiply vectors

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 * vd2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 * vd2;"
                  << time_multiply_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 * vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 * value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // divide vectors

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 / vd2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 / vd2;"
                  << time_divide_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 / vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 / value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // add vectors element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != vd1.size(); j++) {
                vd3[j] = vd1[j] + vd2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_vectors_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3[j] = vd1[j] + vd2[j];"
                  << time_add_vectors_el_by_el.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 + vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 + value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // subtract vectors element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != vd1.size(); j++) {
                vd3[j] = vd1[j] - vd2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_vectors_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3[j] = vd1[j] - vd2[j];"
                  << time_subtract_vectors_el_by_el.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 - vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 - value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // multiply vectors element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != vd1.size(); j++) {
                vd3[j] = vd1[j] * vd2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_vectors_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3[j] = vd1[j] * vd2[j];"
                  << time_multiply_vectors_el_by_el.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 * vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 * value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;

        // divide vectors element by element

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            for (uint64_t j = 0; j != vd1.size(); j++) {
                vd3[j] = vd1[j] / vd2[j];
            }
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_vectors_el_by_el =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3[j] = vd1[j] / vd2[j];"
                  << time_divide_vectors_el_by_el.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 / vd2) << std::endl;
        std::cout << " --> " << (vd3 == value1 / value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
        std::cout << " --> " << (vd2 == value2) << std::endl;
    }

    // # 2

    {
        dense_vector<double> vd1;
        dense_vector<double> vd3;

        vd1.allocate(dimension);

        vd1 = value1;

        // add vector with value

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 + value2;
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 + value2;"
                  << time_add_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 + value2) << std::endl;
        std::cout << " --> " << (vd3 == value1 + value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;

        // subtract value from vectors

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 - value2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 - value2;"
                  << time_subtract_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 - value2) << std::endl;
        std::cout << " --> " << (vd3 == value1 - value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;

        // multiply vectors with value

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 * value2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 * value2;"
                  << time_multiply_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 * value2) << std::endl;
        std::cout << " --> " << (vd3 == value1 * value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;

        // divide vectors with value

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = vd1 / value2;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = vd1 / value2;"
                  << time_divide_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 / value2) << std::endl;
        std::cout << " --> " << (vd3 == value1 / value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
    }

    // # 3

    {

        dense_vector<double> vd1;
        dense_vector<double> vd3;

        vd1.allocate(dimension);

        vd1 = value1;

        // add value with vector

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = value2 + vd1;
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_add_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = value2 + vd1;"
                  << time_add_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == vd1 + value2) << std::endl;
        std::cout << " --> " << (vd3 == value1 + value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;

        // subtract vector form value

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = value2 - vd1;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_subtract_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = value2 - vd1;"
                  << time_subtract_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == value2 - vd1) << std::endl;
        std::cout << " --> " << (vd3 == value2 - value1) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;

        // multiply value with vector

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = value2 * vd1;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_multiply_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = value2 * vd1;"
                  << time_multiply_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == value2 * vd1) << std::endl;
        std::cout << " --> " << (vd3 == value1 * value2) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;

        // divide value by vector

        t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            vd3 = value2 / vd1;
        }

        t2 = std::chrono::high_resolution_clock::now();

        const auto time_divide_vectors =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3 = value2 / vd1;"
                  << time_divide_vectors.count() << std::endl;

        std::cout << " --> " << (vd3 == value2 / vd1) << std::endl;
        std::cout << " --> " << (vd3 == value2 / value1) << std::endl;
        std::cout << " --> " << (vd1 == value1) << std::endl;
    }
}
