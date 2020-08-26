#include <iostream>
#include <typeinfo>
#include <gtest/gtest.h>
#include <boost/core/demangle.hpp>

/**
 * @brief template function overload
 *
 * @note std::enable_if<bool B, class T = void>
 *       If B is true, std::enable_if has a public member typedef type, equal to T; otherwise, there is no member typedef.
 *       So if B if false, the function is ill-formed and will be ignored during overload. If B is true, the second one
 *       will be a non-type parameter. Template non-type parameter is a special type of parameter that does not substitute
 *       for a type but is instead replaced by a value. A non-type parameter can be any of the following:
 *       std::nullptr_t, integral type, pointer type, pointer to member type, enumeration type.
 */
template <typename T, std::enable_if_t<std::is_integral<T>::value, int> i = 1>
int foo(T) {
    std::cout << "Type of T is " << boost::core::demangle(typeid(T).name()) << std::endl;
    return i;
}

template <typename T, std::enable_if_t<std::is_floating_point<T>::value, std::nullptr_t> n = nullptr>
std::nullptr_t foo(T) {
    std::cout << "Type of T is " << boost::core::demangle(typeid(T).name()) << std::endl;
    return n;
}

TEST(TEMPLATE_FUNCTION, basic) {
    ASSERT_EQ(1, foo(0));
    ASSERT_EQ(nullptr, foo(0.));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
