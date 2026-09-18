#include <fstream>
#include <string>
#include <print>
#include <vector>

int main(void)
{
    // nombre de archivo 
    std::string filename = "data.txt";

    // abrir el archivo
    std::ifstream fin(filename);

    // leer los datos y guardarlos
    double x, y;
    std::vector<double> xdata, ydata;

    // procesarlos
    while(fin.eof() == false) {
        fin >> x >> y;
        if(fin.eof() == true) break;
        std::println("{} {}", x, y);
        xdata.push_back(x);
        ydata.push_back(y);
    }
    std::println("size: {}", xdata.size());
    std::println("{} {} ", xdata[0], xdata[1]);

    // cerrar el archivo
    fin.close();

    return 0;
}