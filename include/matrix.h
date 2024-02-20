#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <iostream>
#include <vector>

template <typename T = double>
class Matrix {
public:
  // constructors
  // empty matrix
  Matrix(int32_t rows, int32_t cols);
  Matrix(int32_t rows, int32_t cols, const std::vector<T>& data);

  // predefined matrix unknown rows and cols (co-py constructor)
  Matrix(const Matrix<T>& other);

  /*
  To find the determinant of A where A is NxN
  recursivly break down the matrix until the mtrix is a 2x2 
  find the determinant of that and multiply it by a then add 
  it to the total.
  */
  double determinant();

  [inline] bool sameSize(const Matrix<T>& b) const { return m_data.size() == b.getData().size() };
  [inline] bool sameDim(const Matrix<T>& b) const { return m_rows == b.getRows() && m_cols == b.getCols() };

  // get functions
  [inline] int32_t getRows() const { return m_rows };
  [inline] int32_t getCols() const { return m_cols };
  [inline] std::vector<T>& getData() const { return m_data };

  // access operator
  double& operator()(uint32_t row, uint32_t col) {
      return matrix[row * col + col];
  }

private:
    std::vector<T> m_data;
    int32_t m_rows;
    int32_t m_cols;
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
  template <typename T>
  bool operator==(const Matrix<T> &a, const Matrix<T> &b);

/*
Purpose: prints a matrix
Return: returns a stream
*/
  template<typename T>
  std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);
/*
Purpose: Adds two matrices of the same size
Return: returns resulting matrix
Time Complexity: O(n X m)
*/
  template <typename T>
  Matrix<T> operator+(const Matrix<T> &a, const Matrix<T> &b);

/*
Purpose: Subtracts two matrices of the same size
Return: returns resulting matrix
Time Complexity: O(n X m)
*/
  template <typename T>
  Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b);

/*
Purpose: Subtracts two matrices of the same size
Return: returns resulting matrix
Time Complexity: O(n X m)
*/
  template <typename T>
  Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b);
#endif
