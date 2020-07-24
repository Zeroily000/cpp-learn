add_executable(test_unprotected test.cpp)

target_include_directories(test_unprotected PRIVATE
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_unprotected PRIVATE
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        cppLearnLib
        )

add_test(
        NAME test_unprotected
        COMMAND test_unprotected
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)