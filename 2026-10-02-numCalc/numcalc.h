#pragma once
#include <functional>

//using fptr = double (*f)(double); // tipo de datos de una funcion que recibe un double y retorna un double
using fptr = std::function<double(double)>; // version moderna, general, comoda. 


// declaracion
double deriv_forward(double x, double h, fptr f);
double deriv_central(double x, double h, fptr f);
