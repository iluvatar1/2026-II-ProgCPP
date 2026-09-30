#include "numcalc.h" 

// implementacion
double deriv_forward(double x, double h, fptr f)
{
    return (f(x+h) - f(x))/h;
}

double deriv_central(double x, double h, fptr f)
{
    return (f(x+h) - f(x-h))/(2*h);
}
