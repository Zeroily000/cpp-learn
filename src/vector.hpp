#pragma once
#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include "vector.h"

#include <iterator>
#include <utility>

namespace cpplearn {

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T, dummy>::Vector() = default;

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T, dummy>::~Vector() = default;

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T, dummy>::Vector(Vector<T> const & other) : m_data(other.m_data) {}

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T, dummy>::Vector(Vector<T> && other) noexcept : m_data(std::move(other.m_data)) {}

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T> & Vector<T, dummy>::operator=(Vector<T> const & other) {
  if (&other != this) {
    m_data = other.data;
  }
  return *this;
}

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T> & Vector<T, dummy>::operator=(Vector<T> && other) noexcept {
  if (&other != this) {
    m_data = std::move(other.data);
  }
  return *this;
}

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, std::nullptr_t> dummy>
Vector<T, dummy>::Vector(std::initializer_list<T> init) : m_data(std::move(init)) {}

template <typename T>
std::ostream & operator<<(std::ostream& os, Vector<T> const & vec) {
  std::copy(vec.m_data.begin(), vec.m_data.end(), std::ostream_iterator<int>(os, " "));
  return os;
}

}  // cpplearn

#endif //  VECTOR_HPP_
