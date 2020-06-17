#include <iostream>
#include "base.hpp"

cpplearn::Base::~Base() {
    std::cout << "Destructing Base" << std::endl;
}