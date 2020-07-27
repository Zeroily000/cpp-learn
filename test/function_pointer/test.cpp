#include <gtest/gtest.h>

#include "derived.hpp"

/**
 * @note Function pointers are useful primarily when you want to store functions in an array (or other structure), or when
 *       you need to pass a function to another function (callback function).
 *       A function pointer is defined as
 *       <return type>(* <function pointer>)(<typename_1... typename_N>)
 */

template <typename T>
bool ascending(T const & x, T const & y) {
    return x > y;
}

template <typename T>
bool descending(T const & x, T const & y) {
    return x < y;
}

TEST(FUNCTION_POINTER, basic) {
    // C++ will implicitly convert a function into a function pointer if needed.
    // But default parameters won’t work for functions called through function pointers.
    int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
    cpplearn::Derived::selectionSort(array, 9, ascending);
    ASSERT_TRUE(std::is_sorted(array, array+9, std::less<>()));

    cpplearn::Derived::selectionSort(array, 9, descending);
    ASSERT_TRUE(std::is_sorted(array, array+9, std::greater<>()));
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}