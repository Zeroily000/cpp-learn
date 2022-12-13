add_executable(test_lambda test.cpp)

target_include_directories(test_lambda PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_lambda PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_test(
    NAME test_lambda
    COMMAND test_lambda
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)