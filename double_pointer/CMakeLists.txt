add_executable(double_pointer double_pointer.cpp)

target_link_libraries(double_pointer ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})