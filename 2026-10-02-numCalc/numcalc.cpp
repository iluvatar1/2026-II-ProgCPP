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

double richardson(double x, double h, int alpha, algptr I, fptr f)
{
    double aux = std::pow(2.0, alpha);
    double val1 = I(x, h, f);
    double val2 = I(x, h/2, f);
    return (aux*val2 - val1)/(aux-1);

}

