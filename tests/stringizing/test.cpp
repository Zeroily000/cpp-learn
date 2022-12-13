#include <boost/core/demangle.hpp>
#include <gtest/gtest.h>

/**
 * @brief The number-sign or "stringizing" operator (#) converts macro parameters to string literals without expanding
 *        the parameter definition. It's used only with macros that take arguments. If it precedes a formal parameter in
 *        the macro definition, the actual argument passed by the macro invocation is enclosed in quotation marks and
 *        treated as a string literal. The string literal then replaces each occurrence of a combination of the stringizing
 *        operator and formal parameter within the macro definition.
 *
 * @note White space that precedes the first token and follows the last token of the actual argument is ignored. Any
 *       white space between the tokens in the actual argument is reduced to a single white space in the resulting string literal.
 *       Further, if a character contained in the argument usually requires an escape sequence when used in a string literal,
 *       for example, the quotation mark (") or backslash (\) character, the necessary escape backslash is automatically
 *       inserted before the character.
 */

#define F abc
#define B def
#define FB(arg) #arg
#define FB1(arg) FB(arg)


TEST(CPP_LEARN, stringizing) {
    // FB(F B) -> #F B -> "F B"
    ASSERT_EQ(typeid(FB(F B)), typeid(char[4]))
    << "FB(F B) = \"" << FB(F B) << "\" (" << boost::core::demangle(typeid(FB(F B)).name()) << ")";

    // FB1(F B) -> FB1(abc def) -> FB(abc def) -> #abc def -> "abc def"
    ASSERT_EQ(typeid(FB1(F B)), typeid(char[8]))
    << "FB1(F B) = \"" << FB1(F B) << "\" (" << boost::core::demangle(typeid(FB1(F B)).name()) << ")";
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}