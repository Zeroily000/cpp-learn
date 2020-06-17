#include "derived.hpp"

using namespace cpplearn;

Derived::Derived() : Base() {}
Derived::~Derived() {
    std::cout << "Destructing Derived" << std::endl;
}

Derived::Derived(Derived const & other) = default;
Derived::Derived(Derived && other) noexcept = default;

Derived & Derived::operator=(Derived const & other) = default;
Derived & Derived::operator=(Derived && other) noexcept = default;
