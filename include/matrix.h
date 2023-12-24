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
  // predefined matrix
  Matrix(int32_t rows, int32_t cols,
         const std::vector<std::vector<double>> &values);

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
