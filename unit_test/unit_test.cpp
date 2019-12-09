#include "gtest/gtest.h"

void foo() {
    assert(false);
}

TEST(sample_test_name, sample_test) {
    ASSERT_DEATH(foo(), "");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
