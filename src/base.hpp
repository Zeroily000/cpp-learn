#ifndef BASE_HPP
#define BASE_HPP

#include <string>
namespace cpplearn {

class Base {
public:
    Base();
    virtual ~Base();

    Base(Base const & other);
    Base(Base && other) noexcept;

    Base & operator=(Base const & other);
    Base & operator=(Base && other) noexcept;

    std::string getProtectedString() const;

    std::string Base::* m_mptr;
    std::string m_public_string;

protected:
    std::string m_protected_string;
};
}
#endif //BASE_HPP
