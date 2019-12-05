#add_subdirectory(myPyLib)
find_package(PythonLibs 3 REQUIRED)
find_package(Boost COMPONENTS python3)

python_add_module(myPyLib myPyLib/boost_python.cpp)

target_include_directories(myPyLib PUBLIC
        ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
target_link_libraries(myPyLib
        ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

