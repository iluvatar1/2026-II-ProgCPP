#include <print>
#include "numcalc.h"

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

