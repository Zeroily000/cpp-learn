#include <functional>
#include <iostream>
#include <memory>

#include "base.hpp"
#include "derived.hpp"
#include "gtest/gtest.h"

TEST(CPP_LEARN, std_function) {
  ::testing::internal::CaptureStdout();

  // Store a lambda
  std::function<void(int)> wrapper1{[](int value){ std::cout << value << std::endl; }};

  // Store a call to a member function
  std::function<void(cpplearn::Derived const &, int, char)> wrapper2{&cpplearn::Derived::Print<int>};

  // Store a call to a member function and object ptr
  std::function<void(int)> wrapper3{std::bind(&cpplearn::Derived::Print<int>, &cpplearn::Derived::GetInstance(), std::placeholders::_1, '\n')};

  // Evaluate
  wrapper1(1);
  wrapper2(cpplearn::Derived::GetInstance(), 2, '\n');
  wrapper3(3);
  ASSERT_EQ(::testing::internal::GetCapturedStdout(), "1\n2\n3\n");
}

TEST(CPP_LEARN, std_bind) {
  auto f1{[](int n1, int n2, int n3, int const & n4, int n5) {
    return std::vector<int>{n1, n2, n3, n4, n5};
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << std::endl;
  }};

  auto f2{[](int n){ return n; }};

  // Demonstrates argument reordering and pass-by-reference
  int n{7};
  // _1 and _2 represent future arguments that will be passed to f1
  auto const wrapper1{std::bind(f1, std::placeholders::_2, 42, std::placeholders::_1, std::cref(n), n)};
  n = 10;
  ASSERT_EQ(wrapper1(1, 2, 1001), f1(2, 42, 1, n, 7));  // 1 is bound by _1, 2 is bound by _2, 1001 is unused

  // Nested bind subexpression share the placeholders
  auto wrapper2{std::bind(f1, std::placeholders::_3, std::bind(f2, std::placeholders::_3), std::placeholders::_3, 4, 5)};
  ASSERT_EQ(wrapper2(10, 11, 12), f1(12, f2(12), 12, 4, 5));

  // Bind to a pointer to data member
  auto wrapper3{std::bind(&cpplearn::Base::m_public_string, std::placeholders::_1)};
  cpplearn::Base b;
  ASSERT_EQ(wrapper3(b), b.m_public_string);
  ASSERT_EQ(wrapper3(&b), b.m_public_string);

  auto b_ptr1{std::make_shared<cpplearn::Base>()};
  ASSERT_EQ(wrapper3(b_ptr1), b_ptr1->m_public_string);

  auto b_ptr2{std::make_unique<cpplearn::Base>()};
  ASSERT_EQ(wrapper3(b_ptr2), b_ptr2->m_public_string);
}

int main(int argc, char ** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
