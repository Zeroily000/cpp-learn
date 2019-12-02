#include <iostream>
#include <type_traits>
#include <vector>


template <typename T, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
class Vector;

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T> const & vec);

template <typename T, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t>>
class Vector{
public:
    Vector() = default;
    ~Vector() = default;

    explicit Vector(Vector<T> const & other) : m_data(other.m_data) {}
    explicit Vector(Vector<T> && other) noexcept : m_data(other.m_data) {}

    Vector& operator=(Vector<T> const & other) {
        if (&other != this) {
            m_data = other.data;
        }
        return *this;
    }
    Vector& operator=(Vector<T> && other) noexcept {
        if (&other != this) {
            m_data = other.data;
        }
        return *this;
    }

    Vector(std::initializer_list<T> l) : m_data(l) {}

    friend std::ostream& operator<< <> (std::ostream&, Vector const &);
private:
    std::vector<T> m_data;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T> const & vec) {
    for (T const & v : vec.m_data) {
        os << v << ' ';
    }
    return os;
}

int main(int argc, char** argv) {
    Vector<int> vec{1, 2, 3, 4, 5, 6};
    std::cout << vec << std::endl;
    return 0;
}
