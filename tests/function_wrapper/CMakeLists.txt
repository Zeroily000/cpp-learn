add_executable(test_function_wrapper test.cpp)

target_include_directories(test_function_wrapper PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_function_wrapper PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    cppLearnLib
)

add_test(
    NAME test_function_wrapper
    COMMAND test_function_wrapper
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
