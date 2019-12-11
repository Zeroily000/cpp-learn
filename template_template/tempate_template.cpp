#include <iostream>
#include "gtest/gtest.h"
/**
 * @note typename and class are interchangeable in the basic case of specifying a template.
 *       There are specific cases where there is a difference between typename and class.
 *       The first one is in the case of dependent types. typename is used to declare when
 *       referencing a nested type that depends on another template parameter.
 *       When specifying a template template, the class keyword must be used before C++17.
 *       Since C++17, both keywords are allowed in this case.
 *
 * @param 199711L: C++98 or C++03
 * @param 201103L: C++11
 * @param 201402L: C++14
 * @param 201703L: C++17
 */

template <typename T>
struct Foo {
    explicit Foo(T const & d) : data{d} {}
    T data;
};

#if __cplusplus >= 201703L
template <typename T, template <typename> typename C>
#else
template <typename T, template <typename> class C>
#endif
T bar(C<T> c) {
    return c.data;
}

TEST(TEMPLATE_TEMPLATE, template_template) {
    Foo<int> foo{1};
    ASSERT_EQ(foo.data, bar(foo));
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
