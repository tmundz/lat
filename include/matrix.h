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

  // matrix functions

  /*
    Takes in a second matrix as a param will not modify
    this function will return the resulting matrix.
  */
  Matrix add(Matrix &b);
  Matrix sub(Matrix &b);
  Matrix Multiply(const Matrix &b) const;

  /*
  To find the determinant of A where A is NxN
  recursivly break down the matrix until the mtrix is a 2x2 
  find the determinant of that and multiply it by a then add 
  it to the total.
  */
  double determinant() const;

  // get functions
  int32_t getRows();
  int32_t getCols();
  double getVal(int row, int col);

private:
  std::vector<std::vector<double>> matrix;
  int32_t totalRows;
  int32_t totalCols;

  bool sameSize(const Matrix &b) const;
};

#endif
