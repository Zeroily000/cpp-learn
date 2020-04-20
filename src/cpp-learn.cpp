#include "cpp-learn.hpp"

CppLearn::CppLearn() = default;
CppLearn::~CppLearn() = default;

CppLearn::CppLearn(CppLearn const & other) = default;
CppLearn::CppLearn(CppLearn && other) noexcept = default;

CppLearn & CppLearn::operator=(CppLearn const & other) = default;
CppLearn & CppLearn::operator=(CppLearn && other) noexcept = default;