add_executable(test_member-pointer test.cpp)

target_include_directories(test_member-pointer PRIVATE
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_member-pointer PRIVATE
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        cppLearnLib
        )

add_test(
        NAME test_member-pointer
        COMMAND test_member-pointer
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)