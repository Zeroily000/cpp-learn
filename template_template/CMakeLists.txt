add_executable(tempate_template tempate_template.cpp)

target_link_libraries(tempate_template ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})