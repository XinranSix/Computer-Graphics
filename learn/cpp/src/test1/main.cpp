#include <iostream>
#include <gtest/gtest.h>

int add(int a, int b) { return a + b; }

TEST(testCase1, should_3_when_given_2_and_1) { EXPECT_EQ(add(2, 1), 3); }

TEST(testCase2, should_3_when_given_2_and_1) { EXPECT_EQ(add(2, 1), 3); }

TEST(testCase3, should_3_when_given_2_and_1) { EXPECT_EQ(add(2, 1), 3); }

TEST(testCase4, should_3_when_given_2_and_1) { EXPECT_EQ(add(2, 1), 3); }

TEST(testCase5, should_3_when_given_2_and_1) { EXPECT_EQ(add(2, 1), 3); }

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}