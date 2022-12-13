#include <functional>
#include <gtest/gtest.h>
#include <iostream>

#include "derived.hpp"

TEST(CPP_LEARN, function_wrapper) {
  ::testing::internal::CaptureStdout();

  // Store a lambda
  std::function<void(int)> wrapper1{[](int value){ std::cout << value << std::endl; }};

  // Store a call to a member function
  std::function<void(cpplearn::Derived const &, int, char)> wrapper2{&cpplearn::Derived::Print<int>};

  // Store a call to a member function and object ptr
  std::function<void(int)> wrapper3{std::bind(&cpplearn::Derived::Print<int>, &cpplearn::Derived::getInstance(), std::placeholders::_1, '\n')};

  // Evaluate
  wrapper1(1);
  wrapper2(cpplearn::Derived::getInstance(), 2, '\n');
  wrapper3(3);
  ASSERT_EQ(::testing::internal::GetCapturedStdout(), "1\n2\n3\n");
}

int main(int argc, char ** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
