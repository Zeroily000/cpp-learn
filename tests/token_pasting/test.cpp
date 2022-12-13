#include <gtest/gtest.h>
#include "base.hpp"

/**
 * @brief The double-number-sign or token-pasting operator (##), which is sometimes called the merging or
 *        combining operator, is used in both object-like and function-like macros. It permits separate
 *        tokens to be joined into a single token, and therefore, can't be the first or last token
 *        in the macro definition.
 */

#define getString(type) get##type##String

TEST(TOKEN_PASTING, basic) {
    cpplearn::Base base;
    std::cout << base.getString(Private)() << std::endl;
    SUCCEED();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}