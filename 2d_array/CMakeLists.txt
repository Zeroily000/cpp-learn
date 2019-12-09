add_executable(2d_array 2d_array.cpp)

target_link_libraries(2d_array ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})