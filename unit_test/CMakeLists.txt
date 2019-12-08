find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_test unit_test.cpp)

target_link_libraries(unit_test ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
