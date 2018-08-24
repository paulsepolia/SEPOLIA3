#include <cmath>
#include <iostream>
#include <iomanip>
#include "../../../dense_vector/dense_vector.h"

using sepolia::dense_vector;

int main() {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        double value = 400.0;

        dense_vector<double> vd(dimension);

        vd.set(value);

        std::cout << std::boolalpha;

        vd++;
        value++;

        std::cout << (vd == value) << std::endl;

        ++vd;
        ++value;

        std::cout << (vd == value) << std::endl;

        --vd;
        --value;

        std::cout << (vd == value) << std::endl;

        vd--;
        value--;

        std::cout << (vd == value) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd(dimension);

        vd.set(value);

        std::cout << std::boolalpha;

        vd += vd;

        std::cout << (vd == 2 * value) << std::endl;

        vd -= vd;

        std::cout << (vd == 0.0) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd(dimension);

        vd.set(value);

        std::cout << std::boolalpha;

        vd *= vd;

        std::cout << (vd == value * value) << std::endl;

        vd /= vd;

        std::cout << (vd == 1.0) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        std::cout << std::boolalpha;

        vd2 *= vd1;

        std::cout << (vd2 == value1 * value2) << std::endl;
        std::cout << (vd1 == value1) << std::endl;

        vd2 /= vd1;

        std::cout << (vd2 == value2) << std::endl;
        std::cout << (vd1 == value1) << std::endl;
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        std::cout << std::boolalpha;

        vd2 += vd1;

        std::cout << (vd2 == value1 + value2) << std::endl;
        std::cout << (vd1 == value1) << std::endl;

        vd2 -= vd1;

        std::cout << (vd2 == value2) << std::endl;
        std::cout << (vd1 == value1) << std::endl;
    }
}
