find_package(GTest REQUIRED)

add_executable(test_singleton test.cpp)

target_include_directories(test_singleton PRIVATE
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_singleton PRIVATE
        ${GTEST_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        cppLearnLib
        )

add_test(
        NAME test_singleton
        COMMAND test_singleton
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)