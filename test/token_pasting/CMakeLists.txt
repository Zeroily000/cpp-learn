add_executable(test_token-pasting test.cpp)

target_include_directories(test_token-pasting PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_token-pasting PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    cppLearnLib
)

add_test(
    NAME test_token-pasting
    COMMAND test_token-pasting
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)