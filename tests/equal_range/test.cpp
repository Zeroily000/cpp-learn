#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

/*
 * @note std::equal_range -> {std::lower_bound, std::upper_bound}
 *       std::lower_bound -> pointer (iterator) to the first element that comp(element, value) returns false
 *       std::upper_bound -> pointer (iterator) to the first element that comp(value, element) returns true
 */
TEST(CPP_LEARN, equal_range) {
  std::vector<std::pair<int, int>> intervals{{1,3}, {4,8}, {10, 12}, {15, 20}};
  auto comp = [](std::pair<int, int> const & interval1, std::pair<int, int> const & interval2) {
    return interval1.second < interval2.first;
  };
  std::pair<std::vector<std::pair<int, int>>::const_iterator, std::vector<std::pair<int, int>>::const_iterator> const range{std::equal_range(intervals.cbegin(), intervals.cend(), std::make_pair(8,10), comp)};
  ASSERT_EQ(range, std::make_pair(intervals.cbegin()+1, intervals.cbegin()+3)); // {4,8}, {15, 20}
}

int main(int argc, char ** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
