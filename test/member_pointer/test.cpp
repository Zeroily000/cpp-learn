#include <gtest/gtest.h>

#include "base.hpp"
#include "derived.hpp"

class member_pointer : public ::testing::Test {
protected:
    cpplearn::Base b{};
    cpplearn::Derived & d{cpplearn::Derived::getInstance()};
};

TEST_F(member_pointer, pointer_to_data_members) {
    std::string cpplearn::Base::* const bmp{&cpplearn::Base::m_public_string};
    ASSERT_EQ(b.*bmp, b.m_public_string);

    std::string cpplearn::Base::* const * pbmp{&bmp};
    ASSERT_EQ(b.*bmp, b.**pbmp);

    std::string cpplearn::Base::* cpplearn::Base::* bmpbmp{&cpplearn::Base::m_mptr};
    ASSERT_EQ(b.*(b.*bmpbmp), b.*bmp);

    // Pointer to data member of an accessible unambiguous non-virtual base class can be implicitly converted to pointer
    // to the same data member of a derived class.
    // Conversion in the opposite direction, from a pointer to data member of a derived class to a pointer to data member
    // of an unambiguous non-virtual base class, is allowed with static_cast and explicit cast, even if the base class
    // does not have that member.
    std::string cpplearn::Derived::* const dmp{bmp};
    ASSERT_EQ(d.*bmp, d.*dmp);
}

TEST_F(member_pointer, pointer_to_member_funtions) {
    std::string (cpplearn::Base::* bfp)() const = &cpplearn::Base::getProtectedString;
    ASSERT_EQ(b.getProtectedString(), (b.*bfp)());

    // Pointer to member function of a base class can be implicitly converted to pointer to the same member function of
    // a derived class.
    // Conversion in the opposite direction, from a pointer to member function of a derived class to a pointer to member
    // function of an unambiguous non-virtual base class, is allowed with static_cast and explicit cast, even if the base
    // class does not have that member function.
    std::string (cpplearn::Derived::* dfp)() const = bfp;
    ASSERT_EQ((d.*bfp)(), (d.*dfp)());
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}