#ifndef DERIVED_HPP
#define DERIVED_HPP

//#include <cstddef> // std::size_t
#include <iostream>
#include <vector>

#include "base.hpp"

namespace cpplearn {


class Derived : public Base {
 public:
  static Derived & GetInstance();
  ~Derived() override;

  // Deleted definition must be first declaration
  Derived(Derived const & other) = delete;
  Derived(Derived && other) noexcept = delete;

  Derived & operator=(Derived const & other) = delete;
  Derived & operator=(Derived && other) noexcept = delete;

  template <typename T>
  void Print(T value, char end='\n') const {
    std::cout << value << end;
  }

  template<typename T, std::size_t COLS>
  static void Print2dArray(T const * const arr) {
    std::cout << "Print 2d array as T const * const" << std::endl;
    for (std::size_t i{0}; i < sizeof(arr)/sizeof(*arr); ++i) {
      for (std::size_t j{0}; j < COLS; ++j) {
        std::cout << *(arr + i*COLS + j) << ' ';
      }
      std::cout << std::endl;
    }
  }

  template<typename T, std::size_t ROWS, std::size_t COLS>
  static void Print2dArray(T const (* const arr)[COLS]) {
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

  template <typename T>
  static void selectionSort(T * arr, std::size_t size, bool(* const comparisonFcn)(T const &, T const &)) {
    // Step through each element of the array
    for (std::size_t startIndex = 0; startIndex < size; ++startIndex) {
      // bestIndex is the index of the smallest/largest element we've encountered so far.
      std::size_t bestIndex = startIndex;

      // Look for smallest/largest element remaining in the array (starting at startIndex+1)
      for (std::size_t currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
        // If the current element is smaller/larger than our previously found smallest
        if (comparisonFcn(arr[bestIndex], arr[currentIndex])) // COMPARISON DONE HERE
          // This is the new smallest/largest number for this iteration
          bestIndex = currentIndex;
      }

      // Swap our start element with our smallest/largest element
      std::swap(arr[startIndex], arr[bestIndex]);
    }
  }


#if __cplusplus >= 201703L
  template<typename T, template<typename, typename> typename Container, typename Allocator = std::allocator<T>>
#else
  template<typename T, template<typename, typename> class Container, typename Allocator = std::allocator<T>>
#endif
  static typename Container<T, Allocator>::iterator beginItr(Container<T, Allocator> c) {
    return c.begin();
  }

 private:
  Derived();
};

}
#endif //DERIVED_HPP
