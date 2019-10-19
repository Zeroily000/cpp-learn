#include <iostream>

class foo {
public:
    static foo & getInstance() {
        std::cout << "getting an instance of foo" << std::endl;
        static foo ins;
        std::cout << "Done" << std::endl;
        return ins;
    }

    ~foo() = default;

    foo(foo const &) = delete;
    foo& operator=(foo const &) = delete;

    foo(foo &&) = delete;
    foo& operator=(foo &&) = delete;
private:
    foo() {
        std::cout << "A foo instance is created" << std::endl;
    }
};

int main()
{
    foo& ins0 = foo::getInstance();
    foo& ins1 = foo::getInstance();
    return 0;
}