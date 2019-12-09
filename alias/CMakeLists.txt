add_executable(alias alias.cpp)

target_link_libraries(alias ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})