cmake_minimum_required(VERSION 3.16)
project(LAT CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find MPI package
find_package(MPI REQUIRED)

# Include directories, including MPI
include_directories(include ${MPI_INCLUDE_PATH})

# Source files
set(SOURCES src/main.cpp src/matrix.cpp)

# Add subdirectories with code
add_subdirectory(external)

# Create executable
add_executable(lat ${SOURCES})

# Link external libraries if needed
target_link_libraries(lat ${MPI_LIBRARIES})

# Link MPI
if(MPI_COMPILE_FLAGS)
  set_target_properties(lat PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(lat PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
