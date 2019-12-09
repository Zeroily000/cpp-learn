#include <iostream>
#include "gtest/gtest.h"
/**
 *@brief T const * const * const = (T const) (* const) (* const)
 *       is a const pointer of A
 *       where A is a const pointer of B
 *       where B is a const T
 */
template <typename T>
void printDoublePointer(T const * const * const arr) {
    std::cout << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << std::endl;
    std::cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << std::endl;
}


class DoublePointerTest : public ::testing::Test {
public:
    DoublePointerTest() : p1{1,2,3}, p2{4,5,6}, p3{7,8,9}, p4{p1, p2}, p5{p2, p3}, p6{nullptr} {}

protected:
    int const * const p4[2];
    int const * const p5[2];
    int const * const * p6;

private:
    int const p1[3];
    int const p2[3];
    int const p3[3];
};

TEST_F(DoublePointerTest, double_pointer) {
    p6 = p4;
    printDoublePointer(p6);
    p6 = p5;
    printDoublePointer(p6);
    SUCCEED();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}