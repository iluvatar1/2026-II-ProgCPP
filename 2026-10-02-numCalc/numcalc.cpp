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

double trapezoid(double a, double b, int nrect, fptr f)
{
    double dx = (b-a)/nrect;
    double suma = 0.0;
    suma = suma + f(a)/2;
    suma = suma + f(b)/2;
    for(int k = 1; k <= nrect-1; k++) {
        double xk = a + k*dx;
        suma = suma + f(xk);
    }
    return suma*dx;
}

double richardson(double a, double b, int nrect, int alpha, algintptr I, fptr f)
{
    double aux = std::pow(2.0, alpha);
    double val1 = I(a, b, nrect, f);
    double val2 = I(a, b, 2*nrect, f);
    return (aux*val2 - val1)/(aux-1);
  
}
