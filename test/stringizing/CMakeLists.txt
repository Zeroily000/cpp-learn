add_executable(test_stringizing test.cpp)

target_include_directories(test_stringizing PRIVATE
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_stringizing PRIVATE
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        cppLearnLib
        )

add_test(
        NAME test_stringizing
        COMMAND test_stringizing
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)