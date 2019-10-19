#include <iostream>

template <typename T, size_t length>
void printVector(T const * const vec) {
    for (size_t i{0}; i < length; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

template <typename T, size_t rows, size_t cols>
void print2DArray(T const arr[rows][cols]) {
    for (size_t i{0}; i < rows; ++i)
        printVector<T, cols>(arr[i]);
    std::cout << std::endl;
}

template <typename T, size_t rows, size_t cols>
void print2DArray(T (* const arr)[cols]) {
    for (size_t i{0}; i < rows; ++i)
        printVector<T, cols>(arr[i]);
    std::cout << std::endl;
}

int main() {

    size_t constexpr rows{2}, cols{3};
    int constexpr arr[rows][cols] = {{1,2,3}, {4,5,6}};
    print2DArray<int, rows, cols>(arr);
    print2DArray<int, rows, cols>((int (* const) [cols])arr);


    return 0;
}
