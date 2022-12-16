add_executable(test_ostream test.cpp)

target_include_directories(test_ostream PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_ostream PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    cppLearnLib
    vector
)

add_test(
    NAME test_ostream
    COMMAND test_ostream
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
