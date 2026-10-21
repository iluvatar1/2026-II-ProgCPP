#include "matrix_utils.h"

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  // TODO
    for (int ii = 0; ii < m; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
            // dataout[jj, ii] = datain[ii, jj]
            dataout[jj*m + ii] = datain[ii*n + jj];
        }
    }

}

double trace(const std::vector<double> & indata, int m, int n)
{
    // suma de la diagonal
    // verificar que m==n
    assert(m==n);
    
    double result = 0.0;
    for (int ii = 0; ii < m; ii++) {
        result = result + indata[ii*n + ii];
    }

    return result;
}