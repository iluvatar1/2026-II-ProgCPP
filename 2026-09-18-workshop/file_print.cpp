#include <print>
#include <cmath>
#include <string>
#include <fstream> // para imprimir y leer archivos


bool is_prime(long mynum);
void prime_factors(long mynum, std::string filename);

int main(void)
{
    long a = 333;
    prime_factors(a, "factores_primos.txt");

    return 0;
}

void prime_factors(long mynum, std::string filename)
{
    // abrir el archivo
    std::ofstream fout(filename); // abre archivo

    std::print(fout, "{} : ", mynum);
    //si soy primo imprimo y me devuelvo
    if (is_prime(mynum) == true) {
        std::println(fout, "{}", mynum);
        return ;
    }

    //para todos los numeros desde 2 hasta mi numeros -> ii
    long limit = mynum;
    for(long ii = 2; ii <= limit; ii++) { 
      // si ii es divisor y ademas es primo
      if(limit%ii == 0 and is_prime(ii)) { 
        std::print(fout, "{} ", ii);
        limit = limit/ii;
        ii = 1; 
      }
    }
    std::println(fout, "");

    // cerrar el archivo
    fout.close();
}


bool is_prime(long mynum)
{
    if (mynum <= 1) return false;

    for (long ii = 2; ii <= std::sqrt(mynum); ii++) 
    {
        if (mynum%ii == 0) { // encontre uyn divisor
            return false;
        }
    }
    return true;
}
