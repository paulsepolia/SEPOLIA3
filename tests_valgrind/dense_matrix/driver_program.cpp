#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "../../dense_matrix/dense_matrix.h"

using sepolia::dense_matrix;

// help display function

void fc(uint64_t line_loc) {
    std::cout << " --> " << std::setw(3) << line_loc << " --> ";
}

int main(int argc, char **argv) {

    std::cout << std::boolalpha;
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    const auto dim = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const auto dim_large = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const auto dim_small = static_cast<uint64_t>(std::pow(10.0, 1.0));
    dense_matrix<double> md(dim, dim, 2.0);
    const uint64_t test_index = 5;
    const uint64_t test_dim = 10;
    const double value1 = 1234.56789;
    const double value2 = 9876.54321;
    const double value3 = 0.1234567;
    const double factor0 = 1.0;
    const double factor1 = 2.0;
    const double factor2 = 5.0;
    const double factor3 = std::pow(10.0, 1.0);
    const double factor4 = std::pow(10.0, 2.0);
    const double factor5 = std::pow(10.0, 3.0);

    //====================================//
    // allocations and deallocations test //
    //====================================//

    {
        fc(__LINE__);
        std::cout << md.allocated() << std::endl;
        fc(__LINE__);
        std::cout << !md.deallocated() << std::endl;
        fc(__LINE__);

        md = value1;

        fc(__LINE__);
        std::cout << (md[test_index] == value1) << std::endl;

        md[test_index] = value1;

        fc(__LINE__);
        std::cout << (md[test_index] == value1) << std::endl;

        md = value2;

        fc(__LINE__);
        std::cout << (md[0] == value2) << std::endl;

        md.deallocate();
        md.allocate(dim_large);

        md = value3;

        fc(__LINE__);
        std::cout << (md[test_index] == value3) << std::endl;
        fc(__LINE__);
        std::cout << (md[dim_large - 1] == value3) << std::endl;

        md.deallocate();
        md.allocate(test_dim);

        fc(__LINE__);
        std::cout << (md.size() == test_dim) << std::endl;

        for (uint64_t i = 0; i < dim_small; i++) {

            md.deallocate();
            md.allocate(dim_large);
            md = value1;

            if (i == dim_small - 1) {
                fc(__LINE__);
                std::cout << (md[0] == value1) << std::endl;
                fc(__LINE__);
                std::cout << (md[dim_large - 1] == value1) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_matrix<double> md_tmp(dim_large, dim_large, value3);
            md = md_tmp;

            if (i == dim_small - 1) {
                fc(__LINE__);
                std::cout << (md[0] == value3) << std::endl;
                fc(__LINE__);
                std::cout << (md[dim_large - 1] == value3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_matrix<double> md_tmp(dim_large, dim_large, value3);
            md = std::move(md_tmp);

            if (i == dim_small - 1) {
                fc(__LINE__);
                std::cout << (md[0] == value3) << std::endl;
                fc(__LINE__);
                std::cout << (md[dim_large - 1] == value3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_matrix<double> md_tmp(dim_large, dim_large, value3);
            dense_matrix<double> md(std::move(md_tmp));

            if (i == dim_small - 1) {
                fc(__LINE__);
                std::cout << (md[0] == value3) << std::endl;
                fc(__LINE__);
                std::cout << (md[dim_large - 1] == value3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_matrix<double> md_tmp(dim_large, dim_large, value3);
            dense_matrix<double> md(std::move(md_tmp));

            if (i == dim_small - 1) {
                fc(__LINE__);
                std::cout << (md[0] == value3) << std::endl;
                fc(__LINE__);
                std::cout << (md[dim_large - 1] == value3) << std::endl;
            }
        }
    }

    //=====================================//
    // copy vs move constructor test light //
    //=====================================//

    {
        // using move constructor to create the md2 vector from md1

        auto t1(std::chrono::system_clock::now());

        for (uint64_t i = 0; i != dim_small; i++) {
            dense_matrix<double> md1(dim_large, value1);
            dense_matrix<double> md2(std::move(md1));
        }

        auto t2(std::chrono::system_clock::now());
        auto time_span_move(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the md2 vector from md1

        t1 = std::chrono::system_clock::now();

        for (uint64_t i = 0; i != dim_small; i++) {
            dense_matrix<double> md1(dim_large, value1);
            dense_matrix<double> md2(md1);
        }

        t2 = std::chrono::system_clock::now();
        auto time_span_copy(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor0) <= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor1) <= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor2) >= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor3) >= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor4) >= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor5) >= time_span_copy.count()) << std::endl;
    }

    //=====================================//
    // copy vs move constructor test heavy //
    //=====================================//

    {
        // using move constructor to create the md2 vector from md1

        auto t1(std::chrono::system_clock::now());

        for (uint64_t i = 0; i != dim; i++) {
            dense_matrix<double> md1(dim_large, dim_large, value1);
            dense_matrix<double> md2(std::move(md1));
        }

        auto t2(std::chrono::system_clock::now());
        auto time_span_move(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the md2 vector from md1

        t1 = std::chrono::system_clock::now();

        for (uint64_t i = 0; i != dim; i++) {
            dense_matrix<double> md1(dim_large, dim_large, value1);
            dense_matrix<double> md2(md1);
        }

        t2 = std::chrono::system_clock::now();
        auto time_span_copy(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor0) <= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor1) <= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor2) >= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor3) >= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor4) >= time_span_copy.count()) << std::endl;
        fc(__LINE__);
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor5) >= time_span_copy.count()) << std::endl;
    }

    //==============//
    // algebra test //
    //==============//

    {
        dense_matrix<double> md1(dim, dim, value1);
        const double val(value2);
        dense_matrix<double> md2;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            md2 = md1 + val;
        }

        fc(__LINE__);
        std::cout << ((md1[0] + val) == md2[0]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim; i++) {
            md2 = md1 - val;
        }

        fc(__LINE__);
        std::cout << ((md1[0] - val) == md2[0]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim; i++) {
            md2 = md1 * val;
        }

        fc(__LINE__);
        std::cout << ((md1[0] * val) == md2[0]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim; i++) {
            md2 = md1 / val;
        }

        fc(__LINE__);
        std::cout << ((md1[0] / val) == md2[0]) << std::endl;

    }

    //==============//
    // algebra test //
    //==============//

    {
        dense_matrix<double> md1(dim, dim, value1);
        dense_matrix<double> md2(dim, dim, value2);
        dense_matrix<double> md3;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            md3 = md1 + md2;
        }

        fc(__LINE__);
        std::cout << ((md1[test_index] + md2[test_index]) == md3[test_index]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim; i++) {
            md3 = md1 - md2;
        }

        fc(__LINE__);
        std::cout << ((md1[test_index] - md2[test_index]) == md3[test_index]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim; i++) {
            md3 = md1 * md2;
        }

        fc(__LINE__);
        std::cout << ((md1[test_index] * md2[test_index]) == md3[test_index]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim; i++) {
            md3 = md1 / md2;
        }

        fc(__LINE__);
        std::cout << ((md1[test_index] / md2[test_index]) == md3[test_index]) << std::endl;
    }

    return 0;
}
