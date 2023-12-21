#include "matrix.h"
#include <random>
#include <chrono>

float randomNum() {
    // use the high resolution clock to generate a seed for the random num
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 generator(static_cast<unsigned>(seed));

    // define range 0 to 10 for testing purposes
    float min = 0.0f;
    float max = 10.0f;

    std::uniform_real_distribution<float> distribution(min, max);
}

// create generate matrices
Matrix genMatrix(int32_t rows, int32_t cols) {
    Matrix m(rows, cols);


    for (int i = 0; i < rows; i++) {
        for (int i = 0; j < cols; j++)
            m.insert(, 0,);
    }
    return m;
}


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
