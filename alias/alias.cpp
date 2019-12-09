#include <iostream>
#include <type_traits>
#include "boost/core/demangle.hpp"
#include "gtest/gtest.h"

typedef unsigned long ulong;

typedef int int_t, *intp_t, (&fr)(int, ulong), (*fp)(int, ulong), arr_t[10];

typedef struct {int a; int b;} S, *pS;

long unsigned typedef long ullong;

template <typename T>
struct add_const {
    typedef T const type;
};

TEST(ALIAS, type_define) {
    ASSERT_TRUE(static_cast<bool>(std::is_same<ulong, unsigned long>::value))
        << "ulong: " << boost::core::demangle(typeid(ulong).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<int_t, int>::value))
        << "int_t: " << boost::core::demangle(typeid(int_t).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<intp_t, int*>::value))
        << "intp_t: " << boost::core::demangle(typeid(intp_t).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<fr, int(&)(int, unsigned long)>::value))
        << "fp: " << boost::core::demangle(typeid(fr).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<fp, int(*)(int, unsigned long)>::value))
        << "fp: " << boost::core::demangle(typeid(fp).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<arr_t , int[10]>::value))
        << "fp: " << boost::core::demangle(typeid(arr_t).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<pS, S*>::value))
        << "fp: " << boost::core::demangle(typeid(pS).name());

    ASSERT_TRUE(static_cast<bool>(std::is_same<add_const<int>::type, int const>::value))
        << "fp: " << boost::core::demangle(typeid(add_const<int>::type).name());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}