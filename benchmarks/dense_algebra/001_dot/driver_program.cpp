#include <cmath>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <complex>
#include "../../../sepolia/sepolia.h"

using namespace sepolia;

int main() {

    const uint32_t SPACE2 = 50;
    const uint32_t TRY = 10;
    std::cout << std::boolalpha;
    const auto rows = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const auto columns = static_cast<uint64_t>(std::pow(10.0, 4.0));

    // dot double matrix - same value

    {
        dense_matrix<double> md1;
        dense_matrix<double> md2;
        const double value = 1.0;

        md1.allocate(rows, columns);
        md2.allocate(rows, columns);
        md1 = value;
        md2 = value;

        dense_matrix<double> md3;

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = Dot(md1, md2);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_dot_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = Dot(md1, md2);"
                  << time_dot_matrix.count() << std::endl;

        std::cout << " --> " << (md3 == static_cast<double>(rows)) << std::endl;
    }

    // dot complex<double> matrix - same value

    {
        dense_matrix<std::complex<double>> md1;
        dense_matrix<std::complex<double>> md2;
        const std::complex<double> value = {1.0, 1.0};

        md1.allocate(rows, columns);
        md2.allocate(rows, columns);
        md1 = value;
        md2 = value;

        dense_matrix<std::complex<double>> md3;

        auto t1 = std::chrono::high_resolution_clock::now();

        for (uint32_t i = 0; i != TRY; i++) {
            md3 = Dot(md1, md2);
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        const auto time_dot_matrix =
                std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

        std::cout << " --> " << __LINE__ << std::endl;
        std::cout << std::left << std::setw(SPACE2) << " --> time for: md3 = Dot(md1, md2);"
                  << time_dot_matrix.count() << std::endl;

        std::complex<double> v2 = {0.0, 2.0 * rows};

        std::cout << " --> " << (md3 == v2) << std::endl;
    }
}