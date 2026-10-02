#include <print>
#include "numcalc.h"

// ejemplo 
double fun(double x);

int main(int argc, char **argv)
{
    double x = 0.3;
    double a = 0.0, b = 2.0;
    std::println("Exact : {}", 0.25 - std::cos(2.0) +1 );
    std::println("t 10  : {}", trapezoid(a, b, 10, fun));
    std::println("t 100 : {}", trapezoid(a, b, 100, fun));
    std::println("rt 100: {}", richardson(a, b, 100, 1, trapezoid, fun));
    return 0;
}

double fun(double x)
{
    return std::sin(x) + x/8.0;
}

