find_package(pybind11 REQUIRED)

set(PYBIND11_CPP_STANDARD -std=c++14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(my_cpp_lib)
add_subdirectory(wrapper)
