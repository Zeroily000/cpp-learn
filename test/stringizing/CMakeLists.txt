add_executable(test_stringizing test.cpp)

target_link_libraries(test_stringizing PRIVATE
        cppLearnLib
        )

add_test(
        NAME test_stringizing
        COMMAND test_stringizing
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)