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

    std::string GetProtectedString() const;
    std::string GetPrivateString() const;

    std::string Base::* m_mptr;
    std::string m_public_string;

protected:
    std::string m_protected_string;

private:
    std::string m_private_string;
};
}
#endif //BASE_HPP
