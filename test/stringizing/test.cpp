#include <boost/core/demangle.hpp>
#include "cpp-learn.hpp"

int main(int argc, char ** argv) {
    std::cout << boost::core::demangle(typeid(FB1(F B)).name()) << std::endl;
    std::cout << FB1(F B) << std::endl;
    return 0;
}
