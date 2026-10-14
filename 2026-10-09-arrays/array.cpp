#include <print>
#include <vector>

int main(void)
{
    int numbers[20000]  = {2, -1}; // arreglo primitivo
    std::println("{}", numbers[1]);
    //std::println("{}", numbers);

    std::vector<double> data;
    data.resize(3200000000);
    data[3] = -9.8765;
    data[4] = 2 + data[3];


    return 0;
}