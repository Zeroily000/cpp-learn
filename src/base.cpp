#include <iostream>
#include "base.hpp"

cpplearn::Base::Base()
    : m_mptr(&cpplearn::Base::m_public_string),
      m_public_string("public string from Base"),
      m_protected_string("protected string from Base"),
      m_private_string("private string from Base") {}

cpplearn::Base::~Base() = default;

cpplearn::Base::Base(Base const & other)
    : m_mptr(other.m_mptr),
      m_public_string(other.m_public_string),
      m_protected_string(other.m_protected_string),
      m_private_string(other.m_private_string) {}

cpplearn::Base::Base(Base && other) noexcept
    : m_mptr(other.m_mptr),
      m_public_string(std::move(other.m_public_string)),
      m_protected_string(std::move(other.m_protected_string)),
      m_private_string(std::move(other.m_private_string)) {}

cpplearn::Base & cpplearn::Base::operator=(Base const & other) {
  if (this != &other) {
    m_mptr = other.m_mptr;
    m_public_string = other.m_public_string;
    m_protected_string = other.m_protected_string;
    m_private_string = other.m_private_string;
  }
  return *this;
}

cpplearn::Base & cpplearn::Base::operator=(Base && other) noexcept {
  if (this != &other) {
    m_mptr = other.m_mptr;
    m_public_string = std::move(other.m_public_string);
    m_protected_string = std::move(m_protected_string);
    m_private_string = std::move(m_private_string);
  }
  return *this;
}

std::string cpplearn::Base::getProtectedString() const {
  return m_protected_string;
}
std::string cpplearn::Base::getPrivateString() const {
  return m_private_string;
}
