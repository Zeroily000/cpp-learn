#include "derived.hpp"

using namespace cpplearn;

Derived & Derived::getInstance() {
    static Derived instance{Derived()};
    return instance;
}

Derived::Derived() : Base() {
    std::cout << "Constructing Derived" << std::endl;
}
Derived::~Derived() {
    std::cout << "Destructing Derived" << std::endl;
}

//Derived::Derived(Derived const & other) = delete;
//Derived::Derived(Derived && other) noexcept = default;
//
//Derived & Derived::operator=(Derived const & other) = default;
//Derived & Derived::operator=(Derived && other) noexcept = default;
