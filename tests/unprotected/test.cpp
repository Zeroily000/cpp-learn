#include <gtest/gtest.h>
#include "base.hpp"

/**
 * @brief D can use C's protected methods inside D
 *
 * @note the unprotected template class inherits from C, so protected methods of C can be used INSIDE unprotected.
 *       D is a friend of unprotected, so D can use unprotected's protected methods, which are C's protected methods, INSIDE D.
 */
template <typename C, typename D>
class unprotected : public C{
public:
    friend D;
};

class BinarySearchTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::cout << m_unprotected_base.m_protected_string << std::endl;
    }
private:
    unprotected<cpplearn::Base, BinarySearchTest> m_unprotected_base;
};

TEST_F(BinarySearchTest, find_existing_element) {
    SUCCEED();
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
