#include "derived.hpp"

namespace cpplearn {

Derived::Derived() = default;

Derived::~Derived() = default;

Derived & Derived::GetInstance() {
  static Derived instance;
  return instance;
}

}