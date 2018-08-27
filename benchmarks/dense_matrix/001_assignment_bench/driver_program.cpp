#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    const uint32_t SPACE2 = 50;
    const uint32_t TRY = 100;
    std::cout << std::boolalpha;

    dense_matrix<double> md1;
    const auto rows = 1 * static_cast<uint64_t>(std::pow(10.0, 4.0));
    const auto columns = 1 * static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value = 123.456;

    // allocate matrix

    auto t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        md1.allocate(rows, columns);
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    const auto time_allocate_matrix =
            std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md1.allocate(rows, columns);"
              << time_allocate_matrix.count() << std::endl;

    std::cout << " --> " << md1.allocated() << std::endl;

    // set matrix to a specific value

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        md1.set(value);
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_matrix_to_value = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md1.set(value);"
              << time_set_matrix_to_value.count() << std::endl;

    std::cout << " --> " << (md1 == value) << std::endl;

    // set matrix to a specific value using =

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        md1 =  value;
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_matrix_to_value_equal = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md1 = value;"
              << time_set_matrix_to_value_equal.count() << std::endl;

    std::cout << " --> " << (md1 == value) << std::endl;

    // set matrix generic # 2

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        for (uint64_t j = 0; j != md1.size(); j++) {
            md1[j] = static_cast<double>(j);
        }
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_matrix_generic1 = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md1[j] = static_cast<double>(j);"
              << time_set_matrix_generic1.count() << std::endl;

    // set matrix generic # 2

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        for (uint64_t j = 0; j != md1.size(); j++) {
            md1[j] = value;
        }
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_matrix_generic2 = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md1[j] = value;"
              << time_set_matrix_generic2.count() << std::endl;

    std::cout << " --> " << (md1 == value) << std::endl;

    // set matrix from another matrix

    dense_matrix<double> md2;

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        md2 = md1;
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_matrix_from_another = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md2 = md1;"
              << time_set_matrix_from_another.count() << std::endl;

    std::cout << " --> " << (md2 == md1) << std::endl;

    // set matrix from another matrix element by element

    dense_matrix<double> md3;

    md3.allocate(rows, columns);

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        for (uint64_t j = 0; j != md1.size(); j++) {
            md3[j] = md1[j];
        }
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_matrix_from_another_elem_by_elem =
            std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: md3[j] = md1[j];"
              << time_set_matrix_from_another_elem_by_elem.count() << std::endl;

    std::cout << " --> " << (md3 == md1) << std::endl;
}
