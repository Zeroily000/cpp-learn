cmake_minimum_required(VERSION 3.14)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(2d_array)
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

add_subdirectory(binary_search)