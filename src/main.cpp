#include "matrix.h"
#include <random>
#include <chrono>


//create a random num by using the current time to generate the seed for it
double randomNum() {
    // use the high resolution clock to generate a seed for the random num
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 generator(static_cast<unsigned>(seed));

    // define range 0 to 10 for testing purposes
    float min = 0.0f;
    float max = 10.0f;

    std::uniform_real_distribution<double> distribution(min, max);

    //generate the float
    return std::round(distribution(generator)* 100)/100;
}

// create generate matrices 
Matrix genMatrix(int32_t rows, int32_t cols) {
    Matrix m(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            m.insert(randomNum(),i,j);
    }
    return m;
}


int main() { 
    Matrix m1 = genMatrix(5,5);
    Matrix m1 = genMatrix(5,5);
    m1.display();
}
