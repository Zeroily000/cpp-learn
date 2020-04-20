cmake_minimum_required(VERSION 3.15)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)
set(CMAKE_C_COMPILER /usr/bin/gcc-8)


#include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(double_pointer)
add_subdirectory(unprotected)

add_subdirectory(alias)
add_subdirectory(template_function)
add_subdirectory(function_pointer)
add_subdirectory(singleton)
add_subdirectory(std_functional)
add_subdirectory(std_bind)
add_subdirectory(member_pointer)
add_subdirectory(lambda_function)
add_subdirectory(parameter_pack)
add_subdirectory(std_ostream)
add_subdirectory(binary_search)
add_subdirectory(python_binding)
add_subdirectory(template_template)
add_subdirectory(std_equal_range)

add_subdirectory(src)
add_subdirectory(test)