#include <gtest/gtest.h>
#include <cmath>
#include "../../sepolia/sepolia.h"

using namespace sepolia;

TEST(test_gen_1, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value = 123.456;

    dense_container<double> dcon(dimension);

    dcon.set(value);

    for (auto &el: dcon) {
        EXPECT_TRUE(el == value);
    }

    EXPECT_TRUE(dcon.size() == dimension);
    EXPECT_TRUE(dcon.allocated());
    EXPECT_TRUE(!dcon.deallocated());

    dcon.deallocate();

    EXPECT_TRUE(dcon.size() == 0);
    EXPECT_TRUE(!dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());
}

TEST(test_gen_2, general) {

    const auto dimension = static_cast<uint64_t>(0);

    dense_container<double> dcon(dimension);

    EXPECT_TRUE(dcon.size() == dimension);
    EXPECT_TRUE(!dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());

    dcon.deallocate();

    EXPECT_TRUE(dcon.size() == 0);
    EXPECT_TRUE(!dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());
}

TEST(test_gen_3, general) {

    dense_container<double> dcon;

    dcon.allocate(0);

    EXPECT_TRUE(dcon.size() == 0);
    EXPECT_TRUE(!dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());

    dcon.deallocate();

    EXPECT_TRUE(dcon.size() == 0);
    EXPECT_TRUE(!dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());
}

TEST(test_gen_4, general) {

    dense_container<double> dcon;

    dcon.allocate(100);

    EXPECT_TRUE(dcon.size() == 100);
    EXPECT_TRUE(dcon.allocated());
    EXPECT_TRUE(!dcon.deallocated());

    dcon.deallocate();

    EXPECT_TRUE(dcon.size() == 0);
    EXPECT_TRUE(!dcon.allocated());
    EXPECT_TRUE(dcon.deallocated());
}

TEST(test_gen_5, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value = 123.456;

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value);
    dcon2.set(value);

    EXPECT_TRUE(dcon1.size() == dcon2.size());
    EXPECT_TRUE(dcon1.allocated() == dcon2.allocated());
    EXPECT_TRUE(dcon1.deallocated() == dcon2.deallocated());
    EXPECT_TRUE(dcon1 == dcon2);
    EXPECT_TRUE(dcon1 == value);
    EXPECT_TRUE(value == dcon1);
    EXPECT_TRUE(dcon2 == value);
    EXPECT_TRUE(value == dcon2);

    dcon1.deallocate();
    dcon2.deallocate();

    EXPECT_TRUE(dcon1.size() == dcon2.size());
    EXPECT_TRUE(dcon1.allocated() == dcon2.allocated());
    EXPECT_TRUE(dcon1.deallocated() == dcon2.deallocated());
    EXPECT_TRUE(!(dcon1 == dcon2));
    EXPECT_TRUE(!(dcon1 == value));
    EXPECT_TRUE(!(value == dcon1));
    EXPECT_TRUE(!(dcon2 == value));
    EXPECT_TRUE(!(value == dcon2));
}

TEST(test_gen_6, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    for (uint64_t i = 0; i != dimension; i++) {

        dcon1[i] = static_cast<double>(i);
        dcon2(i) = static_cast<double>(i);
    }

    EXPECT_TRUE(dcon1 == dcon2);

    dcon1.deallocate();
    dcon2.deallocate();

    EXPECT_TRUE(dcon1 != dcon2);
    EXPECT_TRUE(!(dcon1 == dcon2));
}

TEST(test_gen_7, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value = 123.456789;

    dense_container<double> dcon1(dimension);

    dcon1.set(value);

    dense_container<double> dcon2(dimension);

    for (uint64_t i = 0; i != dimension; i++) {

        dcon2(i) = value;
    }

    EXPECT_TRUE(dcon1 == dcon2);

    dcon1.deallocate();
    dcon2.deallocate();

    EXPECT_TRUE(dcon1 != dcon2);
    EXPECT_TRUE(!(dcon1 == dcon2));
}

TEST(test_gen_8, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value = 123.456789;

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value);
    dcon2 = dcon1;

    EXPECT_TRUE(dcon1 == dcon2);
    EXPECT_TRUE(!(dcon1 != dcon2));

    dcon2.deallocate();

    dcon2 = dcon1;

    EXPECT_TRUE(dcon1 == dcon2);
    EXPECT_TRUE(!(dcon1 != dcon2));

    dcon2.deallocate();

    EXPECT_TRUE(!(dcon1 == dcon2));
    EXPECT_TRUE(dcon1 != dcon2);
}

TEST(test_gen_9, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 1.0));
    const double value1 = 400.0;
    const double coeff = 20.0;
    const double value2 = value1 / coeff;

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    EXPECT_TRUE(dcon2 * coeff == dcon1);
    EXPECT_TRUE(dcon1 / coeff == dcon2);

    dcon2.deallocate();

    dcon2 = dcon1 * dcon1;

    EXPECT_TRUE(dcon1 * dcon1 == dcon2);
    EXPECT_TRUE(dcon2 / dcon1 == dcon1);
}

TEST(test_gen_10, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value1 = 400.0;
    const double coeff = 20.0;
    const double value2 = value1 + coeff;

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    EXPECT_TRUE(dcon2 - coeff == dcon1);
    EXPECT_TRUE(dcon1 + coeff == dcon2);

    dcon2.deallocate();

    dcon2 = dcon1 + dcon1;

    EXPECT_TRUE(dcon1 + dcon1 == dcon2);
    EXPECT_TRUE(dcon1 == dcon2 - dcon1);
}

TEST(test_gen_11, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value1 = 400.0;
    const double coeff = 20.0;
    const double value2 = value1 - coeff;

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    EXPECT_TRUE(dcon2 + coeff == dcon1);
    EXPECT_TRUE(dcon1 - coeff == dcon2);

    dcon2.deallocate();

    dcon2 = dcon1 - dcon1;

    EXPECT_TRUE(dcon1 - dcon1 == dcon2);
    EXPECT_TRUE(dcon1 != dcon2 - dcon1);
    EXPECT_TRUE(dcon2 == 0.0);
    EXPECT_TRUE(0.0 == dcon2);
    EXPECT_TRUE(dcon1 == value1);
}

TEST(test_gen_12, general) {

    const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
    const double value1 = 400.0;
    const double coeff = 2.0;
    const double value2 = coeff * value1;

    dense_container<double> dcon1(dimension);
    dense_container<double> dcon2(dimension);

    dcon1.set(value1);
    dcon2.set(value2);

    EXPECT_TRUE(dcon2 == coeff * dcon1);
    EXPECT_TRUE(dcon1 == dcon2 / coeff);

    dcon2.deallocate();

    dcon2 = dcon1 / dcon1;

    EXPECT_TRUE(1.0 == dcon2);
    EXPECT_TRUE(dcon1 == value1);

    dcon2.deallocate();

    dcon2 = (dcon1 / dcon1) * dcon1;

    EXPECT_TRUE(dcon1 == dcon2);
    EXPECT_TRUE(dcon2 == value1);
    EXPECT_TRUE(dcon1 == value1);
}

TEST(test_gen_13, general) {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        double value = 400.0;

        dense_container<double> dcon(dimension);

        dcon.set(value);

        dcon++;
        value++;

        EXPECT_TRUE(dcon == value);

        ++dcon;
        ++value;

        EXPECT_TRUE(dcon == value);

        --dcon;
        --value;

        EXPECT_TRUE(dcon == value);

        dcon--;
        value--;

        EXPECT_TRUE(dcon == value);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon(dimension);
        dcon.set(value);

        dcon += dcon;

        EXPECT_TRUE(dcon == 2 * value);

        dcon -= dcon;

        EXPECT_TRUE(dcon == 0.0);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon(dimension);
        dcon.set(value);

        dcon *= dcon;

        EXPECT_TRUE(dcon == value * value);

        dcon /= dcon;

        EXPECT_TRUE(dcon == 1.0);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        dcon2 *= dcon1;

        EXPECT_TRUE(dcon2 == value1 * value2);
        EXPECT_TRUE(dcon1 == value1);

        dcon2 /= dcon1;

        EXPECT_TRUE(dcon2 == value2);
        EXPECT_TRUE(dcon1 == value1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value1 = 400.0;
        const double value2 = 800.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value1);
        dcon2.set(value2);

        dcon2 += dcon1;

        EXPECT_TRUE(dcon2 == value1 + value2);
        EXPECT_TRUE(dcon1 == value1);

        dcon2 -= dcon1;

        EXPECT_TRUE(dcon2 == value2);
        EXPECT_TRUE(dcon1 == value1);
    }
}

TEST(test_gen_14, general) {

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value);

        for (auto &el : dcon2) {
            el = value;
        }

        EXPECT_TRUE(dcon2 == dcon1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value);

        dcon2 = dcon1;

        EXPECT_TRUE(dcon2 == dcon1);
    }

    {
        const auto dimension = static_cast<uint64_t>(std::pow(10.0, 4.0));
        const double value = 400.0;

        dense_container<double> dcon1(dimension);
        dense_container<double> dcon2(dimension);

        dcon1.set(value);

        dcon2 = std::move(dcon1);

        EXPECT_TRUE(dcon2 == value);
        EXPECT_TRUE(dcon2.allocated());
        EXPECT_TRUE(dcon1.deallocated());

        dcon1.deallocate();
        dcon2.deallocate();

        EXPECT_TRUE(dcon1.deallocated());
        EXPECT_TRUE(dcon2.deallocated());
    }
}