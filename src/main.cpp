#include "matrix.h"
// create generate matrices

int main() { 
    Matrix m(2,2);
    std::cout << m.matrix[0][0] << std::endl;
    m.insert(1.0, 0, 0);
    std::cout << m.matrix[0][0] << std::endl;
}
