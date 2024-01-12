#include <gtest/gtest.h>
#include "matrix.h"


// Test case for Matrix class
TEST(MatrixTest, Constructor) {
    // Test Matrix constructor with specific dimensions
    Matrix mat1(3, 3);
    EXPECT_EQ(mat1.getRows(), 3);
    EXPECT_EQ(mat1.getCols(), 3);

    // Test Matrix constructor with vector of vectors
    std::vector<std::vector<double>> values = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    Matrix mat2(values);
    EXPECT_EQ(mat2.getRows(), 3);
    EXPECT_EQ(mat2.getCols(), 3);
    // Add more tests as needed
}

// Test case for Matrix Class
TEST(MatrixTestEqual, Equal) { 
    std::vector<std::vector<double>> values = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    std::vector<std::vector<double>> values2 = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}, {7.0, 8.0, 9.0}};
    Matrix mat1(values);
    Matrix mat2(values);
    Matrix mat3(values2);
    EXPECT_TRUE(mat1 == mat2);
    EXPECT_FALSE(mat1 == mat3);
    mat2.insert(-1.0,0,0);
    EXPECT_FALSE(mat1 == mat2);
    mat1.insert(-1.0,0,0);
    EXPECT_TRUE(mat1 == mat2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}