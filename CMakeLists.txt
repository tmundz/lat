cmake_minimum_required(VERSION 3.16)
project(LAT CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)
include(cmake/updateSubmodules.cmake)
# Source files
set(SOURCES src/main.cpp src/matrix.cpp)
# Add subdirectories with code
add_subdirectory(external)
# Create executable
add_executable(lat ${SOURCES})

# Link external libraries if needed target_link_libraries(LAT_cpp Eigen)
