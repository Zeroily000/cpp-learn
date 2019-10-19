#include <iostream>
#include <typeinfo>
#include "boost/core/demangle.hpp"

typedef unsigned long ulong;

typedef int int_t, *intp_t, (&fp)(int, ulong), arr_t[10];

typedef struct {int a; int b;} S, *pS;

long unsigned typedef int long ullong;

template <typename T>
struct add_const {
    typedef T const type;
};

int main(int argc, char** argv)
{
    std::cout << "ulong: " << boost::core::demangle(typeid(ulong).name()) << std::endl;

    std::cout << "int_t: " << boost::core::demangle(typeid(int_t).name()) << std::endl;
    std::cout << "intp_t: " << boost::core::demangle(typeid(intp_t).name()) << std::endl;
    std::cout << "fp: " << boost::core::demangle(typeid(fp).name()) << std::endl;
    std::cout << "arr_t: " << boost::core::demangle(typeid(arr_t).name()) << std::endl;

    std::cout << "S: " << boost::core::demangle(typeid(S).name()) << std::endl;
    std::cout << "pS: " << boost::core::demangle(typeid(pS).name()) << std::endl;

    std::cout << "ullong: " << boost::core::demangle(typeid(ullong).name()) << std::endl;

    std::cout << "add_const<int>::type: " << boost::core::demangle(typeid(add_const<int>::type).name()) << std::endl;
    return 0;
}