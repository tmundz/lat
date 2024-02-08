cmake_minimum_required(VERSION 3.16)
project(LAT CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Specify the include directory
include_directories(include/)

# Source files
set(SOURCES src/main.cpp src/matrix.cpp)

# Create executable
add_executable(lat ${SOURCES})
# Add testing support

# Add subdirectories with code
add_subdirectory(external)

# Link external libraries if needed
target_link_libraries(lat PRIVATE Matrix)


enable_testing()

# Add a target for unit tests
add_subdirectory(tests)
