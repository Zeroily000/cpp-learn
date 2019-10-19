/**
 * @note Function pointers are useful primarily when you want to store functions in an array (or other structure), or when
 *       you need to pass a function to another function (callback function).
 *       A function pointer is defined as
 *       <return type>(* <function pointer>)(<typename_1... typename_N>)
 */
#include <iostream>

#include <typeinfo> // typeid
#include "boost/core/demangle.hpp" // demangle

#include <utility> // std::swap

int foo() { return 5;}

int bar(int a = 0) { return a;}

template <typename T>
void printArray(T const * const arr, size_t size) {
    for (size_t idx{0}; idx < size; ++idx)
        std::cout << arr[idx] << " ";
    std::cout << std::endl;
}

template <typename T>
bool ascending(T x, T y) {
    return x > y;
}

template <typename T>
bool descending(T x, T y) {
    return x < y;
}

template <typename T>
void selectionSort(T * arr, size_t size, bool(*comparisonFcn)(T, T)) {
    // Step through each element of the array
    for (size_t startIndex = 0; startIndex < size; ++startIndex) {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex = startIndex;

        // Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (size_t currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
            // If the current element is smaller/larger than our previously found smallest
            if (comparisonFcn(arr[bestIndex], arr[currentIndex])) // COMPARISON DONE HERE
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
        }

        // Swap our start element with our smallest/largest element
        std::swap(arr[startIndex], arr[bestIndex]);
    }
}

// typedef function pointer
template <typename T>
struct ComparisonFunctionPointerTypedef {
    typedef bool (* const type)(T, T);
};
template <typename T>
using ComparisonFunctionPointerTypedef_t = typename ComparisonFunctionPointerTypedef<T>::type;

// alias function pointer
template <typename T>
using ComparisonFunctionPointerAlias = bool (* const)(T, T);

template <typename T>
void selectionSortTypedef(T * arr, size_t size, ComparisonFunctionPointerTypedef_t<T> pcf) {
    selectionSort(arr, size, pcf);
}

template <typename T>
void selectionSortAlias(T * arr, size_t size, ComparisonFunctionPointerAlias<T> pcf) {
    selectionSort(arr, size, pcf);
}

int main(int argc, char** argv)
{
    // C++ will implicitly convert a function into a function pointer if needed
    int (* const foo_ptr)() = foo; // same as &foo

    // functions have their own lvalue function type. Here foo is a function type that returns an integer and take no parameters.
    std::cout << "Type of foo is " << boost::core::demangle(typeid(foo).name()) << std::endl;
    std::cout << "Type of &foo is " << boost::core::demangle(typeid(&foo).name()) << std::endl;
    std::cout << "Type of foo_ptr is " << boost::core::demangle(typeid(foo_ptr).name()) << std::endl;
    std::cout << "Type of *foo_ptr is " << boost::core::demangle(typeid(*foo_ptr).name()) << std::endl;
    std::cout << std::endl;

    std::cout << "foo() = " << foo() << std::endl;
    std::cout << "Explicit dereference: (*foo_ptr)() = " << (*foo_ptr)() << std::endl;
    std::cout << "Implicit dereference: foo_ptr() = " << foo_ptr() << std::endl;


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Default parameters won’t work for functions called through function pointers
    auto bar_ptr = bar;

    std::cout << "bar() = " << bar() << std::endl;
    std::cout << "bar_ptr(1) = " << bar_ptr(1) << std::endl;
    std::cout << std::endl;


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    // Sort the array in descending order using the descending() function
    selectionSortTypedef(array, 9, descending);
    printArray(array, 9);

    // Sort the array in ascending order using the ascending() function
    selectionSortAlias(array, 9, ascending);
    printArray(array, 9);

    return 0;
}
