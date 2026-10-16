#include <print>
#include <vector>
#include <iostream>

int main(void) {
    // crear un arreglo primitivo de 20 elementos e inicializar los tres primeros a 2.5, -9.8, -1.2e-10
    // stack: pequeña
    double data [20]{2.5, -9.8, -1.2e-10}; 
    data[9] = 67;
    std::println("{}", data[1]);
    std::cout << &data[0] << std::endl;
    std::cout << data << std::endl;
    //std::println("{}", &data[0]);
    //std::println("{}", data);
    
    // crear un vector equivalente: esta en el heap (grande)
    std::vector<double>  data2;
    data2.resize(4); // cambia la longitud y la capacidad
    data2.reserve(9); // esto cambia la capacity
    data2[2] = 67;
    std::println("{}", data2[2]);

    // size: tamaño que nosotros
    // capacity: cuanto puede guardar
    // l:4 , c:4

    data2.push_back(-7.87897897); //l:5, c:8 incrementamos el tamanho del arreglo para añadir algo al final
    data2.push_back(-1.4e10); //l:6, c:8 incrementamos el tamanho del arreglo para añadir algo al final
    data2.push_back(0.57); //l:7, c:8 incrementamos el tamanho del arreglo para añadir algo al final
    data2.push_back(-1.57); //l:8, c:8 incrementamos el tamanho del arreglo para añadir algo al final

    data2.push_back(-1012312.57); // l:9, c:16 incrementamos el tamanho del arreglo para añadir algo al final

    
    return 0;
}