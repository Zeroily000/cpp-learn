#include <iostream>

#include "gtest/gtest.h"
#include "vector.hpp"

TEST(CPP_LEARN, ostream) {
  ::testing::internal::CaptureStdout();
  cpplearn::Vector<int, nullptr> vec{1, 2, 3, 4, 5, 6};
  std::cout << vec << std::endl;
  ASSERT_EQ(::testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 \n");
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
