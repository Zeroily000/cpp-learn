add_executable(test_alias test.cpp)

target_include_directories(test_alias PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_alias PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_test(
    NAME test_alias
    COMMAND test_alias
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)