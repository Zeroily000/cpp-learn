add_executable(test_template-template test.cpp)

target_include_directories(test_template-template PRIVATE
    ${GTEST_INCLUDES_DIRS}
)

target_link_libraries(test_template-template PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    cppLearnLib
)

add_test(
    NAME test_template-template
    COMMAND test_template-template
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
