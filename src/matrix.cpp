#include "matrix.h"
#include <iostream>

/*
Constructors
*/
// init a empty matrix with 0 values. may change where I can keep inserting a
// matrix with no defined row or col
Matrix::Matrix(int32_t rows, int32_t cols) : totalRows(rows), totalCols(cols) {
  matrix.resize(totalRows, std::vector<double>(totalCols, 0.0));
}

// init a matrix with with values.
// no rows need to find the number of rows and cols manually
Matrix::Matrix(const std::vector<std::vector<double>>& tempMat) : totalRows(tempMat.size()), totalCols(tempMat.empty() ? 0: tempMat[0].size()) {
  for (const auto& row: tempMat) {
    if (row.size() != totalCols) {
        throw std::invalid_argument("invalid matrix columns and rows are not the same throughout.");
    }
  }
  matrix = tempMat;
}

// insert a single value at an index
void Matrix::insert(double value, int32_t row_index, int32_t col_index) {
  if (row_index < 0 || col_index < 0 || row_index > totalRows ||
      col_index > totalCols) {
    throw std::out_of_range("Invalid row or column index for matrix");
  }
  matrix[row_index][col_index] = value;
}

void Matrix::display() {

  for (int row = 0; row < totalRows; row++) {
    for (int col = 0; col < totalCols; col++) {
      std::cout << row << " " << col << " " << getVal(row, col) << std::endl;
      std::cout << "\n";
      // std::cout << matrix[row][col] << ' ';
    }
    // std::cout << "\n";
  }
}

bool Matrix::sameSize(const Matrix &b) const {
  return ((totalRows == b.totalRows) && (totalCols == b.totalCols));
}

/*
  Matrix Operations
*/
bool operator==(const Matrix &a, const Matrix &b) {
    if (!a.sameSize(b))
        return false;
    for (int row = 0; row < a.getRows(); row++) {
      for (int col = 0; col < a.getCols(); col++) {
        if (a.getVal(row, col) != b.getVal(row, col))
            return false;
    }
  }
  return true;
}

Matrix Matrix::add(Matrix &b) {
  /*
   I want to redo this add a resize init
   so I can init an empty value and change the matrix size
   when I insert.
   */
  Matrix sumMatrix(totalRows, totalCols);
  if (!sameSize(b)) {
    std::cerr << "Matrix A and Matrix B are different sizes returning a zeroed "
                 "matrix the same size as A"
              << std::endl;
    return sumMatrix;
  }

  for (int row = 0; row < totalRows; row++) {
    for (int col = 0; col < totalCols; col++) {
      double val = getVal(row, col) + b.getVal(row, col);
      sumMatrix.insert(val, row, col);
    }
  }
  return sumMatrix;
}

Matrix Matrix::sub(Matrix &b) {
  /*
   I want to redo this add a resize init
   so I can init an empty value and change the matrix size
   when I insert.
   */
  Matrix sumMatrix(totalRows, totalCols);
  if (!sameSize(b)) {
    std::cerr << "Matrix A and Matrix B are different sizes returning a zeroed "
                 "matrix the same size as A"
              << std::endl;
    return sumMatrix;
  }

  for (int row = 0; row < totalRows; row++) {
    for (int col = 0; col < totalCols; col++) {
      double val = getVal(row, col) - b.getVal(row, col);
      sumMatrix.insert(val, row, col);
    }
  }
  return sumMatrix;
}

double Matrix::determinant() const{
  if (totalRows != totalCols) {
     std::cerr << "Matrix A and Matrix B are different sizes returning a zeroed "
                 "matrix the same size as A"
              << std::endl;
    return -1;
  }

  // Base case 1

  // Base case 2

  // operations

  // recursive call
}

/*
Get Operations
*/
double Matrix::getVal(int row, int col) const { return matrix[row][col]; }
int32_t Matrix::getRows() const { return totalRows; }
int32_t Matrix::getCols() const { return totalCols; }

