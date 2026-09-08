#include <print> // para imprimir a la pantalla

void greet(void); // declaracion
int add(int a, int b);

int main(void) // declaracion
{
    greet();

    int resultado;
    resultado = add(2, 3); 
    std::println("hola {}", resultado);

    return 0;
}

//implementacion

int add(int a, int b)
{
    int c = a + b;
    return c;
}

void greet(void)
{
    std::println("Hola mundo!");
}
