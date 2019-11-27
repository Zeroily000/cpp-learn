/**
 * @note Mutidimensional arrays are not multi-pointer. This line of code is incorrect:
 *       int **ptr = (int**)matrix;
 *       When arrays are passed to functions, they decay to pointers to their first element.
 *       For a 2d array, this would be int (*)[cols].
 */
#include <iostream>

template <typename T, std::size_t length>
void printVector(T const * const vec) {
    for (std::size_t i{0}; i < length; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

template <typename T, std::size_t rows, std::size_t cols>
void print2DArray1(T const arr[rows][cols]) {
    for (std::size_t i{0}; i < rows; ++i)
        printVector<T, cols>(arr[i]);
    std::cout << std::endl;
}

template <typename T, std::size_t rows, std::size_t cols>
void print2DArray2(T const (* const arr)[cols]) {
    for (std::size_t i{0}; i < rows; ++i)
        printVector<T, cols>(arr[i]);
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    std::size_t constexpr rows{2}, cols{3};
    int constexpr arr[rows][cols] = {{1,2,3}, {4,5,6}};

    print2DArray1<int, rows, cols>(arr);
    print2DArray2<int, rows, cols>(arr);

    return 0;
}
