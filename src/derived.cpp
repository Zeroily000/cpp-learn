#include "derived.hpp"

namespace cpplearn {

Derived::Derived() : Base() {
    std::cout << "Constructing Derived" << std::endl;
}

Derived::~Derived() {
    std::cout << "Destructing Derived" << std::endl;
}

Derived & Derived::getInstance() {
    static Derived instance;
    return instance;
}

}