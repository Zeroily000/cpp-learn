#include <iostream>
#include <vector>
#include <algorithm>

/*
 * @note std::equal_range -> {std::lower_bound, std::upper_bound}
 *       std::lower_bound -> pointer (iterator) to the first element that comp(element, value) returns false
 *       std::upper_bound -> pointer (iterator) to the first element that comp(value, element) returns true
 */

int main(int argc, char ** argv) {

    std::vector<std::pair<int, int>> intervals{{1,3}, {4,8}, {10, 12}, {15, 20}};

    auto comp = [](std::pair<int, int> const & interval1, std::pair<int, int> const & interval2) {
        return interval1.second < interval2.first;
    };

    std::pair<std::vector<std::pair<int, int>>::iterator, std::vector<std::pair<int, int>>::iterator> range = std::equal_range(intervals.begin(), intervals.end(), std::make_pair(8,10), comp);
    std::cout << range.first->first << ' ' << range.first->second << std::endl;
    std::cout << range.second->first << ' ' << range.second->second << std::endl;
    
    return 0;
}
