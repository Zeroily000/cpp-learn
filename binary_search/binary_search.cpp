#include <iostream>
#include <vector>

template <typename T>
int findLeft(std::vector<T> const & nums, T const target) {
    size_t lo{0}, hi{nums.size()-1};
    while (lo < hi) {
        size_t mi{lo + (hi - lo)/2};
        if (nums[mi] < target) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}

template <typename T>
int findRight(std::vector<T> const & nums, T const target) {
    size_t lo{0}, hi{nums.size()-1};
    while (lo < hi) {
        size_t mi{lo + (hi - lo + 1)/2};
        if (nums[mi] > target) hi = mi - 1;
        else lo = mi;
    }
    return lo;
}

int main(int argc, char ** argv) {
    std::vector<int> const nums{0,1,2,3,3,3,6};
    std::cout << "nums: ";
    for (int const & num : nums) std::cout << num << ' ';
    std::cout << std::endl;

    int idx;
    idx = findLeft(nums, 3);
    std::cout << "findLeft(nums, 3) = " << idx << ", nums[idx] = " << nums[idx] << std::endl;
    idx = findRight(nums, 3);
    std::cout << "findRight(nums, 3) = " << idx << ", nums[idx] = " << nums[idx] << std::endl;

    idx = findLeft(nums, 4);
    std::cout << "findLeft(nums, 4) = " << idx << ", nums[idx] = " << nums[idx] << std::endl;
    idx = findRight(nums, 4);
    std::cout << "findRight(nums, 4) = " << idx << ", nums[idx] = " << nums[idx] << std::endl;
    return 0;

}
