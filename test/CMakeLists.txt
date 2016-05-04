# ADD OUR TEST EXECUTABLES
set(SOURCE_FILES main_test.cpp)
add_executable(main_test main_test.cpp)
target_link_libraries(main_test cpp-tesla-lib)
# OUR TEST NEEDS THIS LIB TO BE BUILT FIRST...
add_dependencies(main_test cpp-tesla-lib)
# ADD OUR TESTS
add_test(NAME test_main COMMAND main_test)

# VARIABLE_NAME_TEST
set(SOURCE_FILES variable_name_test.cpp)
add_executable(variable_name_test variable_name_test.cpp)
target_link_libraries(variable_name_test cpp-tesla-lib)
# OUR TEST NEEDS THIS LIB TO BE BUILT FIRST...
add_dependencies(variable_name_test cpp-tesla-lib)
add_test(NAME test_variable_name COMMAND variable_name_test)

# EQUATION_TEST
set(SOURCE_FILES equation_test.cpp)
add_executable(equation_test equation_test.cpp)
target_link_libraries(equation_test cpp-tesla-lib)
# OUR TEST NEEDS THIS LIB TO BE BUILT FIRST...
add_dependencies(equation_test cpp-tesla-lib)
add_test(NAME test_equation COMMAND equation_test)