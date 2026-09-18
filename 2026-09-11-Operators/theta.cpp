/*
Implementar la funcion theta
theta(x) = 0, si x es menor o igual a cero, 1 otherwise

entregar foto del codigo y de la cpmpilacion y de la ejecucion
Espero que impriman al menos 4 ejemplos usnado std::print
*/

#include <print>

int theta(double x);

int main()
{
    double x = 2.1;
    std::println("{} -> {}", x, theta(x));
    x = -2.1;
    std::println("{} -> {}", x, theta(x));
    x = 0.0;
    std::println("{} -> {}", x, theta(x));
    x = 2.1e3;
    std::println("{} -> {}", x, theta(x));
    return 0;
}

int theta(double x)
{
    if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}