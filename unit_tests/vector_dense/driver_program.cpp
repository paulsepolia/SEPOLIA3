#include "/opt/gtest/1.7.0/include/gtest/gtest.h"

int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);

    int res = RUN_ALL_TESTS();

    return res;
}
