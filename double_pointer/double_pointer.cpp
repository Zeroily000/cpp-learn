#include <iostream>

/**
 *@brief T const * const * const = (T const) (* const) (* const)
 *       is a const pointer of A
 *       where A is a const pointer of B
 *       where B is a const T
 */
template <typename T>
void printDoublePointer(T const * const * const arr) {
    std::cout << arr[0][0] << " " << arr[0][1] << " " <<arr[0][2] << std::endl;
    std::cout << arr[1][0] << " " << arr[1][1] << " " <<arr[1][2] << std::endl;
}

int main(int argc, char ** argv)
{
    int const p1[3] = {1, 2, 3};
    int const p2[3] = {4, 5, 6};
    int const p3[3] = {7, 8, 9};

    int const * const p4[2] = {p1, p2};
    int const * const p5[2] = {p2, p3};
    int const * const * p6 = p4;
    printDoublePointer(p6);
    std::cout << std::endl;
    p6 = p5;
    printDoublePointer(p6);
    return 0;
}