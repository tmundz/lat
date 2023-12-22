#include "matrix.h"
#include <stdexcept>

/*
Init functions
*/

// init a empty matrix with 0 values. may change where I can keep inserting a mtrix with 
// no defined row or col
Matrix::Matrix(int32_t rows, int32_t cols) : totalRows(rows), totalCols(cols) {
    matrix.resize(totalRows, std::vector<double>(totalCols, 0.0));
}


// insert a single value at an index
void Matrix::insert(double value, int32_t row_index, int32_t col_index) {
    if (row_index < 0 || col_index < 0 || row_index > totalRows || col_index > totalCols) {
        throw std::out_of_range("Invalid row or column index for matrix");
    }
    matrix[col_index][row_index] = value;
}

void Matrix::display() {
    for (const auto& row: matrix) {
        for (const auto& value : row) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }
}
bool Matrix::sameSize(const Matrix &b) const {
    return (getRows)
}
Matrix Matrix::add(const Matrix &b) const{
    if (b.totalRows != )
    
    /* 
    I want to redo this add a resize init
    so I can init an empty value and change the matrix size
    when I insert.
    */
    Matrix newMatrix(getdate_r, totalCols);
    

}

/*
Get functions
*/
int32_t Matrix::getRows() {
    return totalRows;
}

int32_t Matrix::getCols() {
    return totalCols;
}