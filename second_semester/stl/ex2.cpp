#include <gtest/gtest.h>

#include "ex2.hpp"

TEST(ex2, simple) {
    // clang-format off
    EXPECT_EQ(my_std::findN({0,2,3}, 0), 0);
    EXPECT_EQ(my_std::findN({2,2,3,}, 4), -1);
    EXPECT_EQ(my_std::findN({0,2,3}, 3), 2);
    // clang-format on

    std::vector<int> randomized = my_std::randomize();
    randomized.at(15) = 100;
    EXPECT_EQ(my_std::findN(randomized, 100), 15);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
