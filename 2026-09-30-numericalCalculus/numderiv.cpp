/*
1. derivada forward
1.1 Punteros a functions
2. central
3. Richardson
4. Modularizar
*/
#include <functional>
#include <print>

//using fptr = double (*f)(double); // tipo de datos de una funcion que recibe un double y retorna un double
using fptr = std::function<double(double)>; // version moderna, general, comoda. 


// declaracion
double deriv_forward(double x, double h, fptr f);
double deriv_central(double x, double h, fptr f);

// ejemplo 
double fun(double x);


int main(int argc, char **argv)
{
    double x = 0.3;
    std::println("{}", deriv_forward(x, 0.1, fun));
    std::println("{}", deriv_forward(x, 0.01, fun));
    std::println("{}", deriv_central(x, 0.1, fun));
    std::println("{}", deriv_central(x, 0.01, fun));
    return 0;
}

double fun(double x)
{
    return x*x;
}


// implementacion
double deriv_forward(double x, double h, fptr f)
{
    return (f(x+h) - f(x))/h;
}

double deriv_central(double x, double h, fptr f)
{
    return (f(x+h) - f(x-h))/(2*h);
}
