#ifndef DERIVED_HPP
#define DERIVED_HPP

//#include <cstddef> // std::size_t
#include <iostream>
#include <vector>

#include "base.hpp"

#define F abc
#define B def
#define FB(arg) #arg
#define FB1(arg) FB(arg)

namespace cpplearn {

class Derived : public Base {
public:
    Derived();
    ~Derived() override;

    Derived(Derived const & other);
    Derived(Derived && other) noexcept;

    Derived & operator=(Derived const & other);
    Derived & operator=(Derived && other) noexcept;

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

    template<typename T>
    static std::size_t findLeft(std::vector<T> const & nums, T&& target) {
        std::size_t lo{0}, hi{nums.size()-1};
        while (lo < hi) {
            std::size_t mi{lo + (hi - lo)/2};
            if (target > nums[mi]) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }

    template<typename T>
    static std::size_t findRight(std::vector<T> const & nums, T&& target) {
        std::size_t lo{0}, hi{nums.size()-1};
        while (lo < hi) {
            std::size_t mi{lo + (hi - lo + 1)/2};
            if (target < nums[mi]) hi = mi - 1;
            else lo = mi;
        }
        return lo;
    }


#if __cplusplus >= 201703L
    template<template<typename, typename> typename Container, typename T, typename Allocator = std::allocator<T>>
#else
    template<template<typename, typename> class Container, typename T, typename Allocator = std::allocator<T>>
#endif
    static typename Container<T, Allocator>::iterator beginItr(Container<T, Allocator> c) {
        return c.begin();
    }

private:
};
}
#endif //CPP_LEARN_HPP
