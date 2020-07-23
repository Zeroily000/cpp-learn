#include <gtest/gtest.h>
#include "derived.hpp"


class BinarySearchTest : public ::testing::Test {
protected:
    void SetUp() override {
        nums = {0,1,2,4,4,4,6};
    }
    std::vector<int> nums;
};

TEST_F(BinarySearchTest, find_existing_element) {
    ASSERT_EQ(cpplearn::Derived::findLeft(nums, 4), 3);
    ASSERT_EQ(cpplearn::Derived::findRight(nums, 4), 5);
}

TEST_F(BinarySearchTest, find_nonexisting_element) {
    ASSERT_EQ(cpplearn::Derived::findLeft(nums, 5), 6);
    ASSERT_EQ(cpplearn::Derived::findRight(nums, 3), 2);
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
