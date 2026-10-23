#include "matrix_utils.h"

void fill_matrix(std::vector<double> &data, int m, int n) {
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii * n + jj] = ii * n + jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> &data, int m, int n) {
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii * n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void transpose_matrix(const std::vector<double> &datain, int m, int n,
                      std::vector<double> &dataout) {
  // TODO
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      // dataout[jj, ii] = datain[ii, jj]
      dataout[jj * m + ii] = datain[ii * n + jj];
    }
  }
}

double trace(const std::vector<double> &indata, int m, int n) {
  // suma de la diagonal
  // verificar que m==n
  assert(m == n);

  double result = 0.0;
  for (int ii = 0; ii < m; ii++) {
    result = result + indata[ii * n + ii];
  }

  return result;
}

void matmul(const std::vector<double> &A, int mA, int nA,
            const std::vector<double> &B, int mB, int nB,
            std::vector<double> &C, int mC, int nC) {
  assert(nA == mB);
  assert(mC == mA);
  assert(nC == nB);
  for (int ii = 0; ii < mC; ++ii) {
    for (int jj = 0; jj < nC; ++jj) {
      C[ii * nC + jj] = 0.0;
      for (int kk = 0; kk < nA; kk++) {
        C[ii * nC + jj] += A[ii*nA + kk]*B[kk*nB + jj]; 
      }
    }
  }
}
