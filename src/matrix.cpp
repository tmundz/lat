#include "matrix.h"
#include "utils.h"
#include <iostream>

/*
Constructors
*/
// init a empty matrix with 0 values. may change where I can keep inserting a
// matrix with no defined row or col
template<typename T>
Matrix<T>::Matrix(int32_t rows, int32_t cols) :
    m_rows{ rows },
    m_cols{ cols },
    m_data(rows* col)
{
}

template<typename T>
Matrix<T>::Matrix(int32_t rows, int32_t cols, const std::vector<T>& data) :
    m_rows{ rows },
    m_cols{ cols },
    m_data{data}
{
    LAT_ASSERT(m_data.size() == rows * cols, "Matrix size mismatch");
}

// init a matrix with with values.
// no rows need to find the number of rows and cols manually
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : 
    m_data{ other.getData() },
    m_rows{ other.getRows() },
    m_cols{ other.getCols() } 
{
  LAT_ASSERT(m_data.size() == other.getData().size(), "Matrix size mismatch");
  matrix = tempMat;
}

/*
  Matrix Operations
*/
template<typename T>
bool operator==(const Matrix<T>& a, const Matrix<T>& b) {
    if (!a.sameSize(b))
        return false;
    for (int32_t row = 0; row < a.getRows(); row++) {
      for (int32_t col = 0; col < a.getCols(); col++) {
        if (a(row, col) != b(row, col))
            return false;
    }
  }
  return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int32_t row = 0; row < matrix.getRows(); row++) {
        for (int32_t col = 0; col < matrix.getCols(); col++) {
            os << matrix(row, col) << ' ';
        }
        os << "\n";
    }
    return os;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
    LAT_ASSERT(a.sameDim(b), "Matrix size mismatch");

    Matrix<T> sumMatrix(a.getRows(), a.getCols());
    for (int32_t row = 0; row < a.getRows(); row++) {
        for (int32_t col = 0; col < a.getCols(); col++) 
            sumMatrix(row, col) = a(row, col) + b(row, col);
    }
    return sumMatrix;
}


template <typename T>
Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b) {
    LAT_ASSERT(a.sameDim(b), "Matrix size mismatch");
    
    Matrix<T> diffMatrix(a.getRows(), a.getCols());
    for (int32_t row = 0; row < a.getRows(); row++) {
        for (int32_t col = 0; col < a.getCols(); col++) 
            diffMatrix(row, col) = a(row, col) - b(row, col);
    }
    return diffMatrix;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
    LAT_ASSERT(a.getCols() == b.getRows(), "Incompatible matrix dimensions for multiplication");

    Matrix<T> productMatrix(a.getRows(), b.getCols());
    for (int32_t i = 0; i < a.getRows(); i++) {
        for (int32_t j = 0; j < b.getCols(); j++) {
            T sum = 0;
            for (int32_t k = 0; k < a.getCols(); k++) 
                sum += a(i, k) * b(k, j);
            productMatrix(i, j) = sum;
        }
    }
    return productMatrix;
}

template <typename T>
double Matrix<T>::determinant() {
  LAT_ASSERT(m_rows == m_cols, "Matrix must be square to find determinant");

  // Base case 1
  if (m_rows == 1 && m_cols == 1)
    return matrix[0];
  // Base case 2
  if (m_rows == 2 && m_cols == 2)
    return matrix[0] * matrix[1] - matrix[1] * matrix[1];  
  // operations
  double det = 0.0;
  // recursive call
  
  for (int32_t j= 0; j < m_cols; j++) {
    //create a submatrix for the minor of elements (0,j)
    Matrix<T> subMatrix(m_rows - 1, m_cols - 1);
    for (int32_t subi = 0; subi < m_rows - 1; subi++) {
      for (int32_t subj = 0; subj < m_cols - 1; subj++) {
        int32_t sourceRow = subi + 1;
        int32_t sourceCol = subj < j ? subj: subj + 1;
        subMatrix(subi, subj) = matrix[sourceRow * sourceCol + sourceCol];
      }
    }
    double subDet = subMatrix.determinant();

    det += (j % 2 == 0 ? 1 : -1) * matrix[j] * subDet;
  }
  return det;
}


