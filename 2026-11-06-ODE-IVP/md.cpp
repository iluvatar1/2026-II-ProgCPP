// oscilador armonico
#include <print>
#include <valarray>

int main()
{
  // parametros del problema
  const double W0 = 1.45789;
  const double M = 1.23456;
  const double B = 0.0; // 1/s
  const double TF = 10.34543;
  const double DT = 0.0123;

  // estructuras de datos para guardar posicion y velocidad
  std::valarray<double> R(3), V(3), F(3);

  // condiciones iniciales
  R = 0.0; R[0] = 2.7654;
  V = 0.0; //V[0] = 0.0; V[2] = 23.98766;
  F = 0.0; 

  // loop de evolucion temporal
  //   calcular la fuerza en este momento
  //   nueva posicion y nueva velocidad
  //   imprimir el estado del sistema
  for (double t = 0.0; t <= TF; t += DT) {
    // fuerza
    F = 0.0; // reset
    F[0] -= M*W0*W0*R[0]; // add gravitational force
    //F += -M*B*V;

    // time integration: euler algorithm
    R = R + DT*V;
    V = V + DT*F/M;
    
    // print
    std::println("{} {} {} {} {} {} {}", t, R[0], R[1], R[2], V[0], V[1], V[2]);
  }
}