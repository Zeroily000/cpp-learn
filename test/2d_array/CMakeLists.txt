find_package(GTest REQUIRED)

add_executable(test_2d-array test.cpp)

target_include_directories(test_2d-array PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_2d-array PRIVATE
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    cppLearnLib
)

add_test(
    NAME test_2d-array
    COMMAND test_2d-array
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)