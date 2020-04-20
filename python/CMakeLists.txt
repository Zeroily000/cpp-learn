find_package(pybind11 REQUIRED)

set(PYBIND11_CPP_STANDARD -std=c++14)

pybind11_add_module(cppLearnPyLib wrapper.cpp)
target_include_directories(cppLearnPyLib PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(cppLearnPyLib PRIVATE cppLearnLib)

set_target_properties(cppLearnPyLib PROPERTIES
    PREFIX "${PYTHON_MODULE_PREFIX}"
    SUFFIX "${PYTHON_MODULE_EXTENSION}"
)