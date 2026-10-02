#include <print>
#include "numcalc.h"

// ejemplo 
double fun(double x);

int main(int argc, char **argv)
{
    double x = 0.3;
    std::println("Exact : {}", 0.1077085771);
    std::println("f 0.1 : {}", deriv_forward(x, 0.1, fun));
    std::println("f 0.01: {}", deriv_forward(x, 0.01, fun));
    std::println("c 0.1 : {}", deriv_central(x, 0.1, fun));
    std::println("c 0.01: {}", deriv_central(x, 0.01, fun));
    std::println("rf 0.01: {}", richardson(x, 0.01, 1, deriv_forward, fun));
    std::println("rc 0.01: {}", richardson(x, 0.01, 2, deriv_central, fun));
    return 0;
}

double fun(double x)
{
    return x*x*std::sin(x*x);
}

