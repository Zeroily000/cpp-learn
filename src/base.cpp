#include <iostream>
#include "base.hpp"

cpplearn::Base::Base() : m_protected_string{"protected string from Base"} {
    std::cout << "Constructing Base" << std::endl;
}
cpplearn::Base::~Base() {
    std::cout << "Destructing Base" << std::endl;
}

cpplearn::Base::Base(Base const & other) {
    m_protected_string = other.m_protected_string;
}
cpplearn::Base::Base(Base && other) noexcept {
    m_protected_string = std::move(other.m_protected_string);
}

cpplearn::Base & cpplearn::Base::operator=(Base const & other) {
    m_protected_string = other.m_protected_string;
}
cpplearn::Base & cpplearn::Base::operator=(Base && other) noexcept {
    m_protected_string = std::move(m_protected_string);
}