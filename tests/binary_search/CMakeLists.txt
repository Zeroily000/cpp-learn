add_executable(test_binary-search test.cpp)

target_include_directories(test_binary-search PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_binary-search PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    cppLearnLib
)

add_test(
    NAME test_binary-search
    COMMAND test_binary-search
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)