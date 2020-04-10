#add_library(myPyLib MODULE myPyLib.cpp)
#target_link_libraries(myPyLib PRIVATE pybind11::module)
pybind11_add_module(myPyLib myPyLib.cpp)
target_link_libraries(myPyLib PRIVATE myCppLib)
set_target_properties(myPyLib PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
        SUFFIX "${PYTHON_MODULE_EXTENSION}")