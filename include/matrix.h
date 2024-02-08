#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <iostream>
#include <vector>

class Matrix {
public:
  // constructors
  // empty matrix
  Matrix(int32_t rows, int32_t cols);

  // predefined matrix unknown rows and cols
  Matrix(const std::vector<std::vector<double>>& tempMat);

  // simple functions
  void insert(double value, int32_t row_index, int32_t col_index);
  void remove(const uint32_t &value);
  void display();

  /*
    Purpose: Adds two Matrices together
    Return: returns the new matrix
    Time Complexity: O(n^2)
  */
  Matrix add(Matrix &b);

  /*
    Purpose: Subtracts two Matrices together
    Return: Returns the new matrix
    Time Complexity: O(n^2)
  */
  Matrix sub(Matrix &b);

  /*
    Purpose: Multiplies two Matrices together
    Return: Returns the new matrix
    Time Complexity: 
  */
  Matrix Multiply(const Matrix &b);

  /*
  To find the determinant of A where A is NxN
  recursivly break down the matrix until the mtrix is a 2x2 
  find the determinant of that and multiply it by a then add 
  it to the total.
  */
  double determinant();

  bool sameSize(const Matrix &b) const;

  // get functions
  int32_t getRows() const;
  int32_t getCols() const;
  double getVal(int row, int col) const;

private:
  std::vector<std::vector<double>> matrix;
  int32_t totalRows;
  int32_t totalCols;

 
};

/*
    matrix functions
  */

  // Matrix Comparison

  /*
    Purpose: Check of the matrices are equal
    Return: returns a bool
    Time Complexity: O(n^2)
  */
  bool operator==(const Matrix &a, const Matrix &b);

#endif
