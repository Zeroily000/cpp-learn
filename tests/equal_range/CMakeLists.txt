add_executable(test_equal_range test.cpp)

target_include_directories(test_equal_range PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_equal_range PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_test(
    NAME test_equal_range
    COMMAND test_equal_range
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
