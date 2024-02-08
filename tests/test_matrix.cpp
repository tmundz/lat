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

TEST(MatrixTestDet, NonSquare) {
    std::vector<std::vector<double>> noDet = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}, {10.0, 11.0, 12.0}};
    Matrix mNoDet(noDet);
    // Assuming your determinant method throws an exception for non-square matrices.
    EXPECT_THROW(mNoDet.determinant(), std::invalid_argument);
}

TEST(MatrixTestDet, Det2x2) {
    std::vector<std::vector<double>> values1 = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix m1(values1);
    EXPECT_DOUBLE_EQ(m1.determinant(), -2.0); // det = 1*4 - 2*3 = -2
}

TEST(MatrixTestDet, Det3x3) {
    std::vector<std::vector<double>> values2 = {{1.0, 2.0, 3.0}, {4.0, 3.0, 6.0}, {7.0, 8.0, 10.0}};
    Matrix m2(values2);
    EXPECT_DOUBLE_EQ(m2.determinant(), 19.0);
}

TEST(MatrixTestDet, Det4x4) {
    std::vector<std::vector<double>> values3 = {{5.0, 80.0, -2.0, 3.0}, {10.0, 5.0, 12.0, 76.0}, {2.0, 7.0, 23.0, 65.0}, {2.0, 13.0, 26.0, 32.0}};
    Matrix m3(values3);
    // Provide the expected determinant value for this test or use EXPECT_NO_THROW if you just want to ensure it doesn't throw an error.
    EXPECT_NO_THROW(m3.determinant());
    // If you know the expected determinant, replace the above line with:
    // EXPECT_DOUBLE_EQ(m3.determinant(), expected_value);
    EXPECT_DOUBLE_EQ(m3.determinant(),645414.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}