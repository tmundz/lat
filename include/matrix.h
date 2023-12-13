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
  void insert(const std::vector<double> &values);
  void remove(const uint32_t &value);
  void display();

  // matrix functions
  Matrix add(const Matrix &b) const;
  Matrix sub(const Matrix &b) const;
  Matrix Multiply(const Matrix &b) const;

  double determinant() const;

private:
  std::vector<std::vector<double>> matrix;
  int32_t totalRows;
  int32_t totalCols;
};

#endif
