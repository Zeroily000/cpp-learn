//
// Created by andy on 4/19/20.
//

#ifndef CPP_LEARN_HPP
#define CPP_LEARN_HPP

//#include <cstddef> // std::size_t
#include <iostream>

class CppLearn {
public:
    template<typename T, std::size_t COLS>
    static void print2dArray(T const * const arr) {
        std::cout << "Print 2d array as T const * const" << std::endl;
        for (std::size_t i{0}; i < sizeof(arr)/sizeof(*arr); ++i) {
            for (std::size_t j{0}; j < COLS; ++j) {
                std::cout << *(arr + i*COLS + j) << ' ';
            }
            std::cout << std::endl;
        }
    }

    template<typename T, std::size_t ROWS, std::size_t COLS>
    static void print2dArray(T const (* const arr)[COLS]) {
        std::cout << "Print 2d array as T(*)[COLS]" << std::endl;
        for (std::size_t i{0}; i < ROWS; ++i) {
            for (std::size_t j{0}; j < COLS; ++j) {
                std::cout << arr[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }


private:
};

#endif //CPP_LEARN_CPP_LEARN_HPP

//std::size_t const ROWS{sizeof(arr)/sizeof(arr[0])}, COLS{sizeof(arr[0])/ROWS};