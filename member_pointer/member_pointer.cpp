#include <iostream>

struct C {
    int m;
    void f(int n) { std::cout << n << '\n'; }
};

struct Base {
    int m;
    void f(int n) {std::cout << n << std::endl;}
};
struct Derived : Base {};

struct A {
    int m;
    int A::* const p;
};

int main(int argc, char ** argv)
{
    C c{7};
    C* cp = &c;

    Derived d;
    Base b{6};

    A const a{1, &A::m};
    /*******************************pointer to data members*******************************/
    // pointer to data member m of class C
    int C::* cmp = &C::m;

    // pointer to member of object
    std::cout << "c.*cmp = " << c.*cmp << std::endl;

    cp->m = 10;
    // pointer to member pointer
    std::cout << "cp->*cmp = " << cp->*cmp << std::endl;

    // Pointer to data member of an accessible unambiguous non-virtual base class can be implicitly converted to pointer
    // to the same data member of a derived class.
    // Conversion in the opposite direction, from a pointer to data member of a derived class to a pointer to data member
    // of an unambiguous non-virtual base class, is allowed with static_cast and explicit cast, even if the base class
    // does not have that member.
    int Base::* bmp = &Base::m;
    int Derived::* dmp = bmp;

    d.m = 1;
    std::cout << "d.*dmp = " << d.*dmp << ", d.*bmp = " << d.*bmp << std::endl;


    // non-const pointer to data member which is a const pointer to non-const member
    int A::* const A::* p1 = &A::p;

    std::cout << "a.*(*p1) = " << a.*(a.*p1) << std::endl;

    // non-const pointer to a const pointer-to-member
    int A::* const * p2 = &a.p;
    std::cout << "a.**p2 = " << a.**p2 << std::endl;
    std::cout << std::endl;

    /*******************************pointer to member functions*******************************/
    // pointer to member function f of C
    void (C::* cfp)(int) = &C::f;

    std::cout << "(c.*cfp)(1):"; (c.*cfp)(1);
    std::cout << "(cp->*cfp)(2):"; (cp->*cfp)(2);


    // Pointer to member function of a base class can be implicitly converted to pointer to the same member function of
    // a derived class.
    // Conversion in the opposite direction, from a pointer to member function of a derived class to a pointer to member
    // function of an unambiguous non-virtual base class, is allowed with static_cast and explicit cast, even if the base
    // class does not have that member function.
    void (Base::* bfp)(int) = &Base::f;
    void (Derived::* dfp)(int) = bfp;

    std::cout << "(d.*dfp)(1): "; (d.*dfp)(1);
    std::cout << "(d.*bfp)(2): "; (d.*bfp)(2);

    return 0;
}