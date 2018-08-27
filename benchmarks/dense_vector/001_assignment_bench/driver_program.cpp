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

    dense_vector<double> vd1;
    const auto dimension = 2 * static_cast<uint64_t>(std::pow(10.0, 6.0));
    const double value = 123.456;

    // allocate vector

    auto t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        vd1.allocate(dimension);
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    const auto time_allocate_vector =
            std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd1.allocate(dimension);"
              << time_allocate_vector.count() << std::endl;

    std::cout << " --> " << vd1.allocated() << std::endl;

    // set vector to a specific value

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        vd1.set(value);
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_vector_to_value = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd1.set(value);"
              << time_set_vector_to_value.count() << std::endl;

    std::cout << " --> " << (vd1 == value) << std::endl;

    // set vector to a specific value using =

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        vd1 =  value;
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_vector_to_value_equal = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd1 = value;"
              << time_set_vector_to_value_equal.count() << std::endl;

    std::cout << " --> " << (vd1 == value) << std::endl;

    // set vector generic # 2

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        for (uint64_t j = 0; j != vd1.size(); j++) {
            vd1[j] = static_cast<double>(j);
        }
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_vector_generic1 = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd1[j] = static_cast<double>(j);"
              << time_set_vector_generic1.count() << std::endl;

    // set vector generic # 2

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        for (uint64_t j = 0; j != vd1.size(); j++) {
            vd1[j] = value;
        }
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_vector_generic2 = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd1[j] = value;"
              << time_set_vector_generic2.count() << std::endl;

    std::cout << " --> " << (vd1 == value) << std::endl;

    // set vector from another vector

    dense_vector<double> vd2;

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        vd2 = vd1;
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_vector_from_another = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd2 = vd1;"
              << time_set_vector_from_another.count() << std::endl;

    std::cout << " --> " << (vd2 == vd1) << std::endl;

    // set vector from another vector element by element

    dense_vector<double> vd3;

    vd3.allocate(dimension);

    t1 = std::chrono::high_resolution_clock::now();

    for (uint32_t i = 0; i != TRY; i++) {
        for (uint64_t j = 0; j != vd1.size(); j++) {
            vd3[j] = vd1[j];
        }
    }

    t2 = std::chrono::high_resolution_clock::now();

    auto time_set_vector_from_another_elem_by_elem =
            std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << " --> " << __LINE__ << std::endl;
    std::cout << std::left << std::setw(SPACE2) << " --> time for: vd3[j] = vd1[j];"
              << time_set_vector_from_another_elem_by_elem.count() << std::endl;

    std::cout << " --> " << (vd3 == vd1) << std::endl;
}
