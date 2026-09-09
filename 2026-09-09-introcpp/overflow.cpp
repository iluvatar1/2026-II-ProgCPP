#include <print>

int main(void) {
  // con enteros
  int c; // what value?
  std::println("c = {}", c);
  //int b {-3000000000};
  int b = -3000000000;
  std::println("b = {}", b);
  std::println("3*b = {}", 3*b);
  int a = -2000000000;
  std::println("a = {}", a);

  // con flotantes
  double x = 3000000000;
  std::println("x = {}", x);
  x = 3.24e307;
  std::println("x = {}", x);
  std::println("100000*x = {}", 1.0e5*x);
  x = 3.24e310;
  std::println("x = {}", x);
  x = 3.24e-310;
  std::println("x = {}", x);
  x = 3.24e-326;
  std::println("x = {}", x);

  return 0;
}