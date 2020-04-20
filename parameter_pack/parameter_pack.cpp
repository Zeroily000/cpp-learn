#include <iostream>

template <typename T>
struct Data {
    T data;
    std::size_t ref;
    // Constructors that are callable with a single argument must be marked explicit to avoid unintentional implicit conversions
    template <typename... Ts>
    explicit Data(Ts... params) : data(T(params...)), ref(1) {}
};

template <typename T>
class SharedPtr {
public:
    template <typename... Ts>
    explicit SharedPtr(Ts... params) : data_ptr(new Data<T>(params...)) {}
    ~SharedPtr() {
        if (--data_ptr->ref == 0) {
            delete data_ptr;
        }
        data_ptr = nullptr;
    }

    SharedPtr(SharedPtr const & other) {
        data_ptr = other.data_ptr;
        ++data_ptr->ref;
    }
    // Move constructors should be marked noexcept
    SharedPtr(SharedPtr && other) noexcept {
        data_ptr = other.data_ptr;
        ++data_ptr->ref;
    }

    SharedPtr& operator=(SharedPtr const & other) {
        if (this != &other) {
            data_ptr=other.data_ptr;
            ++data_ptr->ref;
        }
    }
    // Move assignment operators should be marked noexcept
    SharedPtr& operator=(SharedPtr && other) noexcept {
        data_ptr=other.data_ptr;
        ++data_ptr->ref;
    }

    T* get() const {
        std::cout << "Get data pointer" << std::endl;
        return &data_ptr->data;
    }

private:
    Data<T>* data_ptr;
};

class Foo {
public:
    Foo(int i, char c) {
        std::cout << "Construct Foo" << std::endl;
    }
};

class Bar {
public:
    Bar() {
        std::cout << "Construct Bar" << std::endl;
    }
};

int main(int argc, char** argv) {
    SharedPtr<Foo> shared_ptr0(0, '1');
    SharedPtr<Bar> shared_ptr1;

    shared_ptr0.get();
    shared_ptr1.get();
    return 0;
}

