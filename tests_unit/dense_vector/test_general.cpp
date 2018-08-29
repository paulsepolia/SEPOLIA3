#include <gtest/gtest.h>
#include <cmath>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

TEST(tes_gen_1, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value = 123.456;

    dense_vector<double> vd(dimension);

    vd.set(value);

    for (auto &el: vd) {
        EXPECT_TRUE(el == value);
    }

    EXPECT_TRUE(vd.size() == dimension);
    EXPECT_TRUE(vd.allocated());
    EXPECT_TRUE(!vd.deallocated());

    vd.deallocate();

    EXPECT_TRUE(vd.size() == 0);
    EXPECT_TRUE(!vd.allocated());
    EXPECT_TRUE(vd.deallocated());
}

TEST(tes_gen_2, general) {

    const auto dimension = static_cast<uint64_t>(0);

    dense_vector<double> vd(dimension);

    vd.set(123.456);

    EXPECT_TRUE(vd.size() == dimension);
    EXPECT_TRUE(!vd.allocated());
    EXPECT_TRUE(vd.deallocated());

    vd.deallocate();

    EXPECT_TRUE(vd.size() == 0);
    EXPECT_TRUE(!vd.allocated());
    EXPECT_TRUE(vd.deallocated());
}

TEST(tes_gen_3, general) {

    {
        dense_vector<double> vd;

        vd.allocate(0);

        EXPECT_TRUE(vd.size() == 0);
        EXPECT_TRUE(!vd.allocated());
        EXPECT_TRUE(vd.deallocated());

        vd.deallocate();

        EXPECT_TRUE(vd.size() == 0);
        EXPECT_TRUE(!vd.allocated());
        EXPECT_TRUE(vd.deallocated());
    }

    {
        dense_vector<double> vd;

        vd.allocate(100);

        EXPECT_TRUE(vd.size() == 100);
        EXPECT_TRUE(vd.allocated());
        EXPECT_TRUE(!vd.deallocated());

        vd.deallocate();

        EXPECT_TRUE(vd.size() == 0);
        EXPECT_TRUE(!vd.allocated());
        EXPECT_TRUE(vd.deallocated());
    }
}

TEST(tes_gen_4, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value = 123.456;

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1.set(value);
    vd2.set(value);

    EXPECT_TRUE(vd1.size() == vd2.size());
    EXPECT_TRUE(vd1.allocated() == vd2.allocated());
    EXPECT_TRUE(vd1.deallocated() == vd2.deallocated());
    EXPECT_TRUE(vd1 == vd2);
    EXPECT_TRUE(vd1 == value);
    EXPECT_TRUE(value == vd1);
    EXPECT_TRUE(vd2 == value);
    EXPECT_TRUE(value == vd2);

    vd1.deallocate();
    vd2.deallocate();

    EXPECT_TRUE(vd1.size() == vd2.size());
    EXPECT_TRUE(vd1.allocated() == vd2.allocated());
    EXPECT_TRUE(vd1.deallocated() == vd2.deallocated());
    EXPECT_TRUE(!(vd1 == vd2));
    EXPECT_TRUE(!(vd1 == value));
    EXPECT_TRUE(!(value == vd1));
    EXPECT_TRUE(!(vd2 == value));
    EXPECT_TRUE(!(value == vd2));
}

TEST(tes_gen_5, general) {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        for (uint64_t i = 0; i != dimension; i++) {

            vd1[i] = static_cast<double>(i);
            vd2(i) = static_cast<double>(i);
        }

        EXPECT_TRUE(vd1 == vd2);

        vd1.deallocate();
        vd2.deallocate();

        EXPECT_TRUE(vd1 != vd2);
        EXPECT_TRUE(!(vd1 == vd2));
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 123.456789;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value);

        for (uint64_t i = 0; i != dimension; i++) {

            vd2(i) = value;
        }

        EXPECT_TRUE(vd1 == vd2);

        vd1.deallocate();
        vd2.deallocate();

        EXPECT_TRUE(vd1 != vd2);
        EXPECT_TRUE(!(vd1 == vd2));
    }
}

TEST(tes_gen_6, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value = 123.456789;

    dense_vector<double> vd1(dimension);
    dense_vector<double> vd2(dimension);

    vd1.set(value);

    vd2 = vd1;

    EXPECT_TRUE(vd1 == vd2);
    EXPECT_TRUE(!(vd1 != vd2));

    vd2.deallocate();

    vd2 = vd1;

    EXPECT_TRUE(vd1 == vd2);
    EXPECT_TRUE(!(vd1 != vd2));

    vd2.deallocate();

    EXPECT_TRUE(!(vd1 == vd2));
    EXPECT_TRUE(vd1 != vd2);
}

TEST(tes_gen_7, general) {
    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 / coeff;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        EXPECT_TRUE(vd2 * coeff == vd1);
        EXPECT_TRUE(vd1 / coeff == vd2);

        vd2.deallocate();

        vd2 = vd1 * vd1;

        EXPECT_TRUE(vd1 * vd1 == vd2);
        EXPECT_TRUE(vd1 == vd2 / vd1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 + coeff;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        EXPECT_TRUE(vd2 - coeff == vd1);
        EXPECT_TRUE(vd1 + coeff == vd2);

        vd2.deallocate();

        vd2 = vd1 + vd1;

        EXPECT_TRUE(vd1 + vd1 == vd2);
        EXPECT_TRUE(vd1 == vd2 - vd1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 20.0;
        const double value2 = value1 - coeff;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        EXPECT_TRUE(vd2 + coeff == vd1);
        EXPECT_TRUE(vd1 - coeff == vd2);

        vd2.deallocate();

        vd2 = vd1 - vd1;

        EXPECT_TRUE(vd1 - vd1 == vd2);
        EXPECT_TRUE(vd1 != vd2 - vd1);
        EXPECT_TRUE(vd2 == 0.0);
        EXPECT_TRUE(0.0 == vd2);
        EXPECT_TRUE(vd1 == value1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double coeff = 2.0;
        const double value2 = coeff * value1;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        EXPECT_TRUE(vd2 == coeff * vd1);
        EXPECT_TRUE(vd1 == vd2 / coeff);

        vd2.deallocate();

        vd2 = vd1 / vd1;

        EXPECT_TRUE(1.0 == vd2);
        EXPECT_TRUE(vd1 == value1);

        vd2.deallocate();

        vd2 = (vd1 / vd1) * vd1;

        EXPECT_TRUE(vd1 == vd2);
        EXPECT_TRUE(vd2 == value1);
        EXPECT_TRUE(vd1 == value1);
    }
}

TEST(tes_gen_8, general) {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        double value = 400.0;

        dense_vector<double> vd(dimension);

        vd.set(value);

        vd++;
        value++;

        EXPECT_TRUE(vd == value);

        ++vd;
        ++value;

        EXPECT_TRUE(vd == value);

        --vd;
        --value;

        EXPECT_TRUE(vd == value);

        vd--;
        value--;

        EXPECT_TRUE(vd == value);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd(dimension);

        vd.set(value);

        vd += vd;

        EXPECT_TRUE(vd == 2 * value);

        vd -= vd;

        EXPECT_TRUE(vd == 0.0);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd(dimension);

        vd.set(value);

        vd *= vd;

        EXPECT_TRUE(vd == value * value);

        vd /= vd;

        EXPECT_TRUE(vd == 1.0);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        vd2 *= vd1;

        EXPECT_TRUE(vd2 == value1 * value2);
        EXPECT_TRUE(vd1 == value1);

        vd2 /= vd1;

        EXPECT_TRUE(vd2 == value2);
        EXPECT_TRUE(vd1 == value1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value1);
        vd2.set(value2);

        vd2 += vd1;

        EXPECT_TRUE(vd2 == value1 + value2);
        EXPECT_TRUE(vd1 == value1);

        vd2 -= vd1;

        EXPECT_TRUE(vd2 == value2);
        EXPECT_TRUE(vd1 == value1);
    }
}

TEST(tes_gen_9, general) {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value);

        for (auto &el : vd2) {
            el = value;
        }

        EXPECT_TRUE(vd2 == vd1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value);

        vd2 = vd1;

        EXPECT_TRUE(vd2 == vd1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_vector<double> vd1(dimension);
        dense_vector<double> vd2(dimension);

        vd1.set(value);

        vd2 = std::move(vd1);

        EXPECT_TRUE(vd2 == value);
        EXPECT_TRUE(vd2.allocated());
        EXPECT_TRUE(vd1.deallocated());

        vd1.deallocate();
        vd2.deallocate();

        EXPECT_TRUE(vd1.deallocated());
        EXPECT_TRUE(vd2.deallocated());
    }
}
