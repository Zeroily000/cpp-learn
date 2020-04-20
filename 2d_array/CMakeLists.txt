find_package(GTest REQUIRED)

add_executable(2d_array 2d_array.cpp)
target_include_directories(2d_array PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(2d_array PRIVATE ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})