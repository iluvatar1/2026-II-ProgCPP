// oscilador armonico
#include <print>
#include <valarray>
//#include <vector>

using state_t = std::valarray<double>;

void fun(double t, const state_t & y, state_t & dydt); // ecuacion diferencial
void print(double t, const state_t & y);

template <class deriv_t, class state_t, class writer_t>
void integrate_euler(deriv_t fderiv, state_t & y, double tinit, double tend, double dt, writer_t writer)
{
  state_t dydt(y.size());
  
  for (double t = tinit; t <= tend; t += dt) {
    // fuerza
    fderiv(t, y, dydt);

    // time integration: euler algorithm
    y = y + dt*dydt; // componente a componente
    
    // print
    writer(t, y);
  }
  
}

template <class deriv_t, class state_t, class writer_t>
void integrate_rk4(deriv_t fderiv, state_t & y, double tinit, double tend, double dt, writer_t writer)
{
  state_t dydt(y.size());
  state_t k1(y.size()), k2(y.size()), k3(y.size()), k4(y.size());
  
  for (double t = tinit; t <= tend; t += dt) {
    // fuerza
    fderiv(t, y, k1);
    fderiv(t+dt/2, y + dt*k1/2, k2);
    fderiv(t+dt/2, y + dt*k2/2, k3);
    fderiv(t+dt, y + dt*k3, k4);
    
    // time integration: rk4 algorithm
    y = y + dt*(k1 + 2*k2 + 2*k3 + k4)/6;
    
    // print
    writer(t, y);
  }
  
}


int main()
{
  // parametros del problema
  const double W0 = 1.45789;
  const double M = 1.23456;
  const double B = 0.0; // 1/s
  const double TF = 90.34543;
  const double DT = 0.0123;

  // estructuras de datos para guardar posicion y velocidad
  state_t S(2); // movimiento en 1d , x y vx

  // condiciones iniciales
  S[0] = 2.7654;

  // definir las derivadas
  auto fun = [M, W0](double t, const state_t & y, state_t & dydt){
    // y = (x, vx)
    dydt[0] = y[1];
    dydt[1] = -M*W0*W0*y[0]*y[0]*y[0];
  };
  
  // loop de evolucion temporal
  //integrate_euler(fun, S, 0.0, TF, DT, print);
  integrate_rk4(fun, S, 0.0, TF, DT, print);

  return 0;
}

void print(double t, const state_t & y)
{
   std::println("{} {} {}", t, y[0], y[1]);
}
