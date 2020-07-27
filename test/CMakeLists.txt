find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(2d_array)
add_subdirectory(binary_search)
add_subdirectory(template_template)
add_subdirectory(stringizing)
add_subdirectory(singleton)
add_subdirectory(unprotected)
add_subdirectory(member_pointer)
add_subdirectory(function_pointer)