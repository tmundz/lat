# Setting this will only affect the folders down from the current one
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest)

# Add your Matrix library
add_library(Matrix STATIC ../src/matrix.cpp)
