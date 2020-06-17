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

