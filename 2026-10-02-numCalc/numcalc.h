#pragma once
#include <functional>
#include <cmath>

//using fptr = double (*f)(double); // tipo de datos de una funcion que recibe un double y retorna un double
using fptr = std::function<double(double)>; // version moderna, general, comoda. 
using algptr = std::function<double(double, double, fptr)>;
using algintptr = std::function<double(double, double, int, fptr)>;

// declaracion derivadas
double deriv_forward(double x, double h, fptr f);
double deriv_central(double x, double h, fptr f);

double richardson(double x, double h, int alpha, algptr I, fptr f);

// declaraciones integrales
double trapezoid(double a, double b, int nrect, fptr f);
double richardson(double a, double b, int nrect, int alpha, algintptr I, fptr f);
