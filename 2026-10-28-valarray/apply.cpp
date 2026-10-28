// apply: aplicar una funcion a todos los elementos del valarray
#include <iostream>
#include <valarray>
#include <cmath>
#include <print>

int sq(int num);

int main()
{
    std::valarray<int> v = {1,2,3,4,5,6,7,8,9,10};

    v = v.apply(sq);
    std::println("{}", v);

    return 0;
}

int sq(int num)
{
    return num*num;
}
