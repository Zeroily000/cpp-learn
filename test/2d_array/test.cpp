#include "cpp-learn.hpp"
#include <gtest/gtest.h>

/**
 * @note Multidimensional arrays are not multi-pointer, e.g. int** is not equal to int[][].
 *       When arrays are passed to functions, they decay to pointers to their first element:
 *       int[] = int*
 *       int[][COLS] = int(*)[COLS]
 *       ...
 */

TEST(ND_ARRAY, 2d_array) {
    std::size_t constexpr M{2}, N{3};
    int constexpr arr[M][N] = {{1,2,3}, {4,5,6}};
    CppLearn::print2dArray<int, N>((int *)arr);
    CppLearn::print2dArray<int, M>(arr);
    SUCCEED();
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
