add_executable(binary_search binary_search.cpp)
target_link_libraries(binary_search ${GTEST_LIBRARIES} pthread)