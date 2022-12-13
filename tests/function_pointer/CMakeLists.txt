add_executable(test_function-pointer test.cpp)

target_include_directories(test_function-pointer PRIVATE
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_function-pointer PRIVATE
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        cppLearnLib
        )

add_test(
        NAME test_function-pointer
        COMMAND test_function-pointer
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)