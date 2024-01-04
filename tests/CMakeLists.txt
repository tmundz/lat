# tests/CMakeLists.txt

# Add the testing executable
add_executable(lat_tests test_matrix.cpp)

# Link with gtest and gtest_main
target_link_libraries(lat_tests gtest gtest_main)

# Link with your Matrix library and any other dependencies
target_link_libraries(lat_tests Matrix)

# Register the test
add_test(NAME lat_tests COMMAND lat_tests)
