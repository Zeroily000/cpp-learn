add_executable(test_template-function template_function.cpp)

target_include_directories(test_template-function PRIVATE
    ${GTEST_INCLUDES_DIRS}
)

target_link_libraries(test_template-function PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_test(
    NAME test_template-function
    COMMAND test_template-function
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
