#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

// help display function

void fc() {

    static uint32_t i(0);
    std::cout << " --> " << std::setw(3) << ++i << " --> ";
}

int main(int argc, char **argv) {

    std::cout << std::boolalpha;
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    const auto dim = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const auto dim_large = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const auto dim_small = static_cast<uint64_t>(std::pow(10.0, 1.0));
    dense_vector<double> vd(dim, 2.0);
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
        fc();
        std::cout << vd.allocated() << std::endl;
        fc();
        std::cout << !vd.deallocated() << std::endl;
        fc();

        vd = value1;

        fc();
        std::cout << (vd[test_index] == value1) << std::endl;

        vd[test_index] = value1;

        fc();
        std::cout << (vd[test_index] == value1) << std::endl;

        vd = value2;

        fc();
        std::cout << (vd[0] == value2) << std::endl;

        vd.deallocate();
        vd.allocate(dim_large);

        vd = value3;

        fc();
        std::cout << (vd[test_index] == value3) << std::endl;
        fc();
        std::cout << (vd[dim_large - 1] == value3) << std::endl;

        vd.deallocate();
        vd.allocate(test_dim);

        fc();
        std::cout << (vd.size() == test_dim) << std::endl;

        for (uint64_t i = 0; i < dim_small; i++) {

            vd.deallocate();
            vd.allocate(dim_large);
            vd = value1;

            if (i == dim_small - 1) {
                fc();
                std::cout << (vd[0] == value1) << std::endl;
                fc();
                std::cout << (vd[dim_large - 1] == value1) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_vector<double> vd_tmp(dim_large, value3);
            vd = vd_tmp;

            if (i == dim_small - 1) {
                fc();
                std::cout << (vd[0] == value3) << std::endl;
                fc();
                std::cout << (vd[dim_large - 1] == value3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_vector<double> vd_tmp(dim_large, value3);
            vd = std::move(vd_tmp);

            if (i == dim_small - 1) {
                fc();
                std::cout << (vd[0] == value3) << std::endl;
                fc();
                std::cout << (vd[dim_large - 1] == value3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_vector<double> vd_tmp(dim_large, value3);
            dense_vector<double> vd(std::move(vd_tmp));

            if (i == dim_small - 1) {
                fc();
                std::cout << (vd[0] == value3) << std::endl;
                fc();
                std::cout << (vd[dim_large - 1] == value3) << std::endl;
            }
        }

        for (uint64_t i = 0; i < dim_small; i++) {
            dense_vector<double> vd_tmp(dim_large, value3);
            dense_vector<double> vd(std::move(vd_tmp));

            if (i == dim_small - 1) {
                fc();
                std::cout << (vd[0] == value3) << std::endl;
                fc();
                std::cout << (vd[dim_large - 1] == value3) << std::endl;
            }
        }
    }

    //=====================================//
    // copy vs move constructor test light //
    //=====================================//

    {
        // using move constructor to create the v2 vector from v1

        auto t1(std::chrono::system_clock::now());

        for (uint64_t i = 0; i != dim_small; i++) {
            dense_vector<double> v1(dim_large, value1);
            dense_vector<double> v2(std::move(v1));
        }

        auto t2(std::chrono::system_clock::now());
        auto time_span_move(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the v2 vector from v1

        t1 = std::chrono::system_clock::now();

        for (uint64_t i = 0; i != dim_small; i++) {
            dense_vector<double> v1(dim_large, value1);
            dense_vector<double> v2(v1);
        }

        t2 = std::chrono::system_clock::now();
        auto time_span_copy(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor0) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor1) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor2) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor3) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor4) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor5) >= time_span_copy.count()) << std::endl;
    }

    //=====================================//
    // copy vs move constructor test heavy //
    //=====================================//

    {
        // using move constructor to create the v2 vector from v1

        auto t1(std::chrono::system_clock::now());

        for (uint64_t i = 0; i != dim; i++) {
            dense_vector<double> v1(dim_large, value1);
            dense_vector<double> v2(std::move(v1));
        }

        auto t2(std::chrono::system_clock::now());
        auto time_span_move(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        // using copy constructor to create the v2 vector from v1

        t1 = std::chrono::system_clock::now();

        for (uint64_t i = 0; i != dim; i++) {
            dense_vector<double> v1(dim_large, value1);
            dense_vector<double> v2(v1);
        }

        t2 = std::chrono::system_clock::now();
        auto time_span_copy(std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(t2 - t1));

        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor0) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor1) <= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor2) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor3) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor4) >= time_span_copy.count()) << std::endl;
        fc();
        std::cout << "OKAY IF --> "
                  << ((time_span_move.count() * factor5) >= time_span_copy.count()) << std::endl;
    }

    //==============//
    // algebra test //
    //==============//

    {
        dense_vector<double> v1(dim, value1);
        const double val(value2);
        dense_vector<double> v2;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            v2 = v1 + val;
        }

        fc();
        std::cout << ((v1[0] + val) == v2[0]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim; i++) {
            v2 = v1 - val;
        }

        fc();
        std::cout << ((v1[0] - val) == v2[0]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim; i++) {
            v2 = v1 * val;
        }

        fc();
        std::cout << ((v1[0] * val) == v2[0]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim; i++) {
            v2 = v1 / val;
        }

        fc();
        std::cout << ((v1[0] / val) == v2[0]) << std::endl;

    }

    //=======================//
    // algebra parallel test //
    //=======================//

    {
        dense_vector<double> v1(dim, value1);
        const double val(value2);
        dense_vector<double> v2;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            v2 = v1 + val;
        }

        fc();
        std::cout << ((v1[0] + val) == v2[0]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim; i++) {
            v2 = v1 - val;
        }

        fc();
        std::cout << ((v1[0] - val) == v2[0]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim; i++) {
            v2 = v1 * val;
        }

        fc();
        std::cout << ((v1[0] * val) == v2[0]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim; i++) {
            v2 = v1 / val;
        }

        fc();
        std::cout << ((v1[0] / val) == v2[0]) << std::endl;
    }

    //==============//
    // algebra test //
    //==============//

    {
        dense_vector<double> v1(dim, value1);
        dense_vector<double> v2(dim, value2);
        dense_vector<double> v3;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 + v2;
        }

        fc();
        std::cout << ((v1[test_index] + v2[test_index]) ==
                      v3[test_index]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim; i++) {
            v3 = v1 - v2;
        }

        fc();
        std::cout << ((v1[test_index] - v2[test_index]) ==
                      v3[test_index]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim; i++) {
            v3 = v1 * v2;
        }

        fc();
        std::cout << ((v1[test_index] * v2[test_index]) ==
                      v3[test_index]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim; i++) {
            v3 = v1 / v2;
        }

        fc();
        std::cout << ((v1[test_index] / v2[test_index]) ==
                      v3[test_index]) << std::endl;
    }

    //=======================//
    // algebra parallel test //
    //=======================//

    {
        dense_vector<double> v1(dim, value1);
        dense_vector<double> v2(dim, value2);
        dense_vector<double> v3;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 + v2;
        }

        fc();
        std::cout << ((v1[test_index] + v2[test_index]) ==
                      v3[test_index]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim; i++) {
            v3 = v1 - v2;
        }

        fc();
        std::cout << ((v1[test_index] - v2[test_index]) ==
                      v3[test_index]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim; i++) {
            v3 = v1 * v2;
        }

        fc();
        std::cout << ((v1[test_index] * v2[test_index]) ==
                      v3[test_index]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim; i++) {
            v3 = v1 / v2;
        }

        fc();
        std::cout << ((v1[test_index] / v2[test_index]) ==
                      v3[test_index]) << std::endl;
    }

    //==============================//
    // algebra test using operators //
    //==============================//

    {
        dense_vector<double> v1(dim, value1);
        dense_vector<double> v2(dim, value2);
        dense_vector<double> v3;

        // plus

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 + v2;
        }

        fc();
        std::cout << ((v1[test_index] + v2[test_index]) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 + value3;
        }

        fc();
        std::cout << ((v1[test_index] + value3) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = value3 + v1;
        }

        fc();
        std::cout << ((v1[test_index] + value3) ==
                      v3[test_index]) << std::endl;

        // subtract

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 - v2;
        }

        fc();
        std::cout << ((v1[test_index] - v2[test_index]) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 - value3;
        }

        fc();
        std::cout << ((v1[test_index] - value3) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = value3 - v1;
        }

        fc();
        std::cout << ((v1[test_index] - value3) ==
                      v3[test_index]) << std::endl;

        // times

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 * v2;
        }

        fc();
        std::cout << ((v1[test_index] * v2[test_index]) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 * value3;
        }

        fc();
        std::cout << ((v1[test_index] * value3) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = value3 * v1;
        }

        fc();
        std::cout << ((v1[test_index] * value3) ==
                      v3[test_index]) << std::endl;

        // divide

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 / v2;
        }

        fc();
        std::cout << ((v1[test_index] / v2[test_index]) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = v1 / value3;
        }

        fc();
        std::cout << ((v1[test_index] / value3) ==
                      v3[test_index]) << std::endl;

        for (uint64_t i = 0; i != dim_large; i++) {
            v3 = value3 / v1;
        }

        fc();
        std::cout << ((value3 / v1[test_index]) ==
                      v3[test_index]) << std::endl;
    }

    return 0;
}
