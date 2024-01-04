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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}