#include <gtest/gtest.h>
#include "derived.hpp"


TEST(CPPLEARN, singleton) {
    cpplearn::Derived<int> const * const dptr1{&cpplearn::Derived<int>::getInstance()};
    cpplearn::Derived<int> const * const dptr2{&cpplearn::Derived<int>::getInstance()};
    ASSERT_EQ(dptr1, dptr2);
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
