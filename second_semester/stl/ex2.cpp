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

TEST(ex3, insert_0_to_10_into_list) {
    std::list<int> list;
    my_std::insert_to_list(list);
    std::list<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(list, expected);
}

TEST(ex4, print_container_with_std_for_each) {
    std::vector<std::string> toPrint{"test 1", "test 1"};
    const std::string expectedOutput{"test 1, test 1"};

    std::ostringstream ss;
    my_std::print(toPrint, ss);
    EXPECT_EQ(expectedOutput, ss.str());
}

TEST(ex5, string_to_upper) {
    const std::string lowerCase{"lowerCaseString"};
    EXPECT_EQ(my_std::upper(lowerCase), "LOWERCASESTRING");
}

TEST(ex6, mean_of_std_vector_int) {
    std::vector<int> v;
    iota_n(std::back_inserter(v) , 101, 0);

    EXPECT_EQ(static_cast<int>(my_std::mean(v)), 50);
    EXPECT_EQ(my_std::mean({}), 0.0f);
}

TEST(ex7_count_odd_elements, simple)
{
    EXPECT_EQ(my_std::count_odd({1, 3, 4}), 2);
}

TEST(ex7_count_odd_elements, proper)
{
    std::vector<int> v;
    iota_n(std::back_inserter(v) , 101, 0);

    EXPECT_EQ(my_std::count_odd(v), 50);
    v.push_back(4);
    EXPECT_EQ(my_std::count_odd(v), 50);
}

TEST(ex7_count_odd_elements, empty)
{
    EXPECT_EQ(my_std::count_odd({}), 0);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
