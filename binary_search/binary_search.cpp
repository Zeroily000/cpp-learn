#include <vector>
#include "gtest/gtest.h"

template <typename T>
std::size_t findLeft(std::vector<T> const & nums, T const target) {
    std::size_t lo{0}, hi{nums.size()-1};
    while (lo < hi) {
        std::size_t mi{lo + (hi - lo)/2};
        if (nums[mi] < target) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}

template <typename T>
std::size_t findRight(std::vector<T> const & nums, T const target) {
    std::size_t lo{0}, hi{nums.size()-1};
    while (lo < hi) {
        std::size_t mi{lo + (hi - lo + 1)/2};
        if (nums[mi] > target) hi = mi - 1;
        else lo = mi;
    }
    return lo;
}

static std::vector<int> const nums{0,1,2,4,4,4,6};

TEST(BINARY_SEARCH, find_existing_element) {
    ASSERT_EQ(findLeft(nums, 4), 3);
    ASSERT_EQ(findRight(nums, 4), 5);
}

TEST(BINARY_SEARCH, find_nonexisting_element) {
    ASSERT_EQ(findLeft(nums, 5), 6);
    ASSERT_EQ(findRight(nums, 3), 2);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
