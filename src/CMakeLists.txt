set(SOURCE_FILES main.cpp)
add_executable(cpp_tesla ${SOURCE_FILES})
target_link_libraries(cpp_tesla cpp-tesla-lib)
add_dependencies(cpp_tesla cpp-tesla-lib)