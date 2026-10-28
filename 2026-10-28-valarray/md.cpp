#include <print>
#include <valarray>

int main()
{
  // parametros del problema
  const double G = 9.81;
  const double M = 1.23456;
  const double B = 1.98; // 1/s
  const double TF = 10.34543;
  const double DT = 0.123;

  // estructuras de datos para guardar posicion y velocidad
  std::valarray<double> R(3), V(3), F(3);

  // condiciones iniciales
  R = 0.0;
  V = 0.0; V[0] = 4.322345345; V[2] = 23.98766;
  F = 0.0; 

  // loop de evolucion temporal
  //   calcular la fuerza en este momento
  //   nueva posicion y nueva velocidad
  //   imprimir el estado del sistema
  for (double t = 0.0; t <= TF; t += DT) {
    // fuerza
    F = 0.0; // reset
    F[2] -= M*G; // add gravitational force
    F += -M*B*V;

    // time integration: euler algorithm
    R = R + DT*V;
    V = V + DT*F/M;
    
    // print
    std::println("{} {} {} {} {} {} {}", t, R[0], R[1], R[2], V[0], V[1], V[2]);
  }
}