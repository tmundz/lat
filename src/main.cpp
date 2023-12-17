#include "matrix.h"
// create generate matrices

int main() { 
    Matrix m(100000,100000);
    //m.display();
    std::cout << '\n';
    m.insert(1.0, 0, 0);
    m.insert(2.0, 1, 0);
    m.insert(3.0, 0, 1);
    m.insert(4.0, 1, 1);
    //m.display();
}
