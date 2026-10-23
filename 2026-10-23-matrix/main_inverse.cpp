#include <print>
#include "matrix_utils.h"

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> MA(M*N, 0.0);
  std::vector<double> MB(N*M, 0.0);
  
  // como llenarlas?
  assert(M == 2 and N == 2);
  MA[0*N + 0] =  3; MA[0*N + 1] =  4;
  MA[1*N + 0] = -2; MA[1*N + 1] = -3;
  MB[0*M + 0] =  3; MB[0*M + 1] =  4.00001;
  MB[1*M + 0] = -2; MB[1*M + 1] = -3;

  print_matrix(MA, M, N);
  print_matrix(MB, N, M);

  bool result = check_inverse(MA, M, N, MB, N, M, 1.0e-3);
  std::println("inversas : {}", result);
  
  return 0;
}

