set(SOURCE_FILES main.cpp)
add_executable(eval ${SOURCE_FILES})
target_link_libraries(eval cpp-tesla-lib)
add_dependencies(eval cpp-tesla-lib)