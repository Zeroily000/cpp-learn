#include "derived.hpp"

namespace cpplearn {

Derived::Derived() = default;

Derived::~Derived() = default;

Derived & Derived::getInstance() {
    static Derived instance;
    return instance;
}

}