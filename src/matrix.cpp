#include "matrix.h"

Matrix::Matrix(int32_t rows, int32_t cols) : totalRows(rows), totalCols(cols) {
    matrix.resize(totalRows, std::vector<double>(totalCols, 0.0));
}

/*Matrix::Matrix(int32_t rows, int32_t cols,
               const std::vector<std::vector<double>>)
    : totalRows(rows), totalCols(cols);
*/