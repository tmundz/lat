#include "matrix.h"
#include <chrono>
#include <mpi.h>
#include <random>

// create a random num by using the current time to generate the seed for it
double randomNum() {
  // use the high resolution clock to generate a seed for the random num
  auto seed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 generator(static_cast<unsigned>(seed));

  // define range 0 to 10 for testing purposes
  float min = 0.0f;
  float max = 10.0f;

  std::uniform_real_distribution<double> distribution(min, max);

  // generate the float
  return std::round(distribution(generator) * 100) / 100;
}

// create generate matrices
Matrix genMatrix(int32_t rows, int32_t cols) {
  Matrix m(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      m.insert(randomNum(), i, j);
  }
  return m;
}

int main() {
  MPI_Init(NULL, NULL);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);
  Matrix m1 = genMatrix(2, 2);
  Matrix m2 = genMatrix(2, 2);
  m1.display();
  std::cout << std::endl;
  m2.display();
  std::cout << std::endl;

  Matrix m3 = m1.add(m2);
  m3.display();
  std::cout << std::endl;

  Matrix m4 = m1.sub(m2);
  m4.display();
  std::cout << std::endl;

  // Print off a hello world message
  printf("Hello world from processor %s, rank %d out of %d processors\n",
         processor_name, world_rank, world_size);

  // Finalize the MPI environment.
  MPI_Finalize();
}
