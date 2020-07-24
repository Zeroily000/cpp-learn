find_package(pybind11 REQUIRED)

set(PYBIND11_CPP_STANDARD -std=c++14)

pybind11_add_module(cppLearnPyLib wrapper.cpp)
target_include_directories(cppLearnPyLib PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(cppLearnPyLib PRIVATE cppLearnLib)

set_target_properties(cppLearnPyLib PROPERTIES
        PREFIX "${PYTHON_MODULE_PREFIX}"
        SUFFIX "${PYTHON_MODULE_EXTENSION}"
)

# In order to link the static library cppLearnLib. No need for shared libraries
set_target_properties(cppLearnLib PROPERTIES POSITION_INDEPENDENT_CODE TRUE)


## Setup Clion for debug
# target: <PYTHON-LIBRARY>
# executable: <PYTHON>
# program arguments: <PYTHON-SCRIPT>