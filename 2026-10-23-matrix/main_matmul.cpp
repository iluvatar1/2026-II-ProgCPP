#include <print>
#include "matrix_utils.h"

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> MA(M*N, 0.0);
  std::vector<double> MB(N*M, 0.0);
  std::vector<double> MC(M*M, 0.0);

  fill_matrix(MA, M, N);
  fill_matrix(MB, N, M);

  print_matrix(MA, M, N);
  print_matrix(MB, N, M);

  matmul(MA, M, N, MB, N, M, MC, M, M);
  print_matrix(MC, M, M);
  
  return 0;
}

