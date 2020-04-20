//
// Created by andy on 4/19/20.
//

#include "cpp-learn.hpp"

//template<typename T>
//void CppLearn::print1dArray(T const arr[]) {
//    for (std::size_t i{0}; i < sizeof(arr)/sizeof(arr[0]); ++i) {
//        std::cout << arr[i] << ' ';
//    }
//    std::cout << std::endl;
//}
//template<typename T, std::size_t M, std::size_t N>
//void CppLearn::print2dArray(T const * const arr) {
//    std::cout << "Print 2d array as T const" << std::endl;
//    for (std::size_t i{0}; i < M; ++i) {
//        for (std::size_t j{0}; j < N; ++j) {
//            std::cout << *(arr + i*N + j) << ' ';
//        }
//        std::cout << std::endl;
//    }
//}






//#include "gtest/gtest.h"
///**
// * @note Mutidimensional arrays are not multi-pointer. This line of code is incorrect:
// *       int **ptr = (int**)matrix;
// *       When arrays are passed to functions, they decay to pointers to their first element.
// *       For a 2d array, this would be int (*)[cols].
// */
//template <typename T, std::size_t length>
//void printVector(T const * const vec) {
//    for (std::size_t i{0}; i < length; ++i)
//        std::cout << vec[i] << " ";
//    std::cout << std::endl;
//}
//
//template <typename T, std::size_t rows, std::size_t cols>
//void print2DArray1(T const arr[rows][cols]) {
//    std::cout << "Print 2D array as T[rows][cols]:" << std::endl;
//    for (std::size_t i{0}; i < rows; ++i)
//        printVector<T, cols>(arr[i]);
//}
//
//template <typename T, std::size_t rows, std::size_t cols>
//void print2DArray2(T const (* const arr)[cols]) {
//    std::cout << "Print 2D array as T(*)[cols]:" << std::endl;
//    for (std::size_t i{0}; i < rows; ++i)
//        printVector<T, cols>(arr[i]);
//}
//
//TEST(ND_ARRAY, 2d_array) {
//    std::size_t constexpr rows{2}, cols{3};
//    int constexpr arr[rows][cols] = {{1,2,3}, {4,5,6}};
//    print2DArray1<int, rows, cols>(arr);
//    print2DArray2<int, rows, cols>(arr);
//    SUCCEED();
//}
//
//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

