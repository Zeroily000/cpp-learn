#include <iostream>
#include <string>
/**
 * @brief D can use protected methods from C
 *
 * @note unprotected inherits from C, so protected methods of C can be used INSIDE unprotected.
 *       D is a friend of unprotected, so D can use all the methods of unprotected INSIDE C.
 *       So, in this case, D can use C's protected methods
 */
template <typename C, typename D>
class unprotected : public C{
public:
    friend D;
};

class --heBase {
public:
    std::string const public_string{"public string"};

protected:
    std::string const protected_string{"protected string"};

private:
    std::string const private_string{"private string"};
};

class Test {
public:
    void print() {
        std::cout << "Printing " << unprotected_test.protected_string << " from Base" << std::endl;
    }
private:
    unprotected<Base, Test> unprotected_test;
};

int main(int argc, char ** argv) {
    Test test;
    test.print();
    return 0;
}