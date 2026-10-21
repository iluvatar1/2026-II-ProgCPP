#include "matrix_utils.h"

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> array2d(M*N, 0.0);

  fill_matrix(array2d, M, N);
  print_matrix(array2d, M, N);

  std::vector<double> array2d_T(M*N, 0.0);
  transpose_matrix(array2d, M, N, array2d_T);
  print_matrix(array2d_T, N, M);

  return 0;
}

