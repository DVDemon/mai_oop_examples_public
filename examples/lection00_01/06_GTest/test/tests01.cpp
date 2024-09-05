#include <gtest/gtest.h>
#include "../include/calculator.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(calculator(1,1)==2);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(calculator(100,0)==100);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(calculator(-100,-20)==-120);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}