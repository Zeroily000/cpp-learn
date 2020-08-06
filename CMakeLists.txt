cmake_minimum_required(VERSION 3.15)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(template_function)
add_subdirectory(std_functional)
add_subdirectory(std_bind)
add_subdirectory(lambda_function)
add_subdirectory(std_ostream)
add_subdirectory(std_equal_range)

add_subdirectory(src)
add_subdirectory(python)
add_subdirectory(test)