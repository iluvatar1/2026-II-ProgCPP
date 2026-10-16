#include <iostream>
#include <print>
#include <string>
#include <vector>

// leer el tamanho desde la linea de comando
/*
./a.out
argc = 1, argv = ["./a.out"]

./a.out 10
argc = 2, argv = ["./a.out", "10"]

./a.out 10 9.8
argc = 3, argv = ["./a.out", "10", "9.8"]
*/

void init(std::vector<double> &data);
double avg(const std::vector<double> &data);

int main(int argc, char **argv) { //
  int N = std::stoi(argv[1]);
  std::vector<double> x(N);

  std::cout << &x[0] << std::endl;
  init(x);
  std::println("{}", x);

  // calcular el promedio
  double result = avg(x);
  std::println("{:25.16e}", result);

  return 0;
}
void init(std::vector<double> &data) {
  // llenar el vector como v[i] = i
  std::cout << &data[0] << std::endl;
  for (int ii = 0; ii <= data.size(); ii = ii + 1) {
    data[ii] = ii;
    //*(&data[0] + ii) = ii;
  }
}

double avg(const std::vector<double> &data) {
  double avg = 0.0;
  for (int jj = 0; jj < data.size(); jj++) {
    avg += data[jj];
  }
  avg = avg / (data.size());
  return avg;
}