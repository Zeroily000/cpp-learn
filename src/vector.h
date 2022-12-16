#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <type_traits>
#include <vector>

namespace cpplearn {

// Forward declaration
template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> = nullptr>
class Vector;

template <typename T>
std::ostream & operator<<(std::ostream& os, Vector<T> const & vec);

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t>>
class Vector{
 public:
  Vector();
  ~Vector();

  explicit Vector(Vector<T> const & other);
  explicit Vector(Vector<T> && other) noexcept;
  Vector<T> & operator=(Vector<T> const & other);
  Vector<T> & operator=(Vector<T> && other) noexcept;

  Vector(std::initializer_list<T> l);

  friend std::ostream & operator<< <> (std::ostream &, Vector const &);

 private:
  std::vector<T> m_data;
};

}  // cpplearn


#endif  // VECTOR_H_
