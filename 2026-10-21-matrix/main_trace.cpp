#include <print>
#include "matrix_utils.h"

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> array2d(M*N, 0.0);

  fill_matrix(array2d, M, N);
  print_matrix(array2d, M, N);

  double t = trace(array2d, M, N);
  std::println("{}", t);

  return 0;
}

