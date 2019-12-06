find_package(pybind11 REQUIRED)

set(PYBIND11_CPP_STANDARD -std=c++14)

add_library(myPyLib MODULE wrapper/myPyLib.cpp)
target_link_libraries(myPyLib PRIVATE pybind11::module)
set_target_properties(myPyLib PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
                                         SUFFIX "${PYTHON_MODULE_EXTENSION}")