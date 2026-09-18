#include <print>
#include <cmath>

bool is_prime(long mynum);
void prime_factors(long mynum);

int main(void)
{
    long a = 7;
    prime_factors(a);

    a = 111;
    prime_factors(a);

    a = 333;
    prime_factors(a);

    a = 8;
    prime_factors(a);

    a = 1000000006;
    prime_factors(a);

    a = 1000000007;
    prime_factors(a);

    a = 100000000003;
    prime_factors(a);

    return 0;
}

void prime_factors(long mynum)
{
    std::print("{} : ", mynum);
    //si soy primo imprimo y me devuelvo
    if (is_prime(mynum) == true) {
        std::println("{}", mynum);
        return ;
    }

    //para todos los numeros desde 2 hasta mi numeros -> ii
    long limit = mynum;
    for(long ii = 2; ii <= limit; ii++) { 
      // si ii es divisor y ademas es primo
      if(limit%ii == 0 and is_prime(ii)) { 
        std::print("{} ", ii);
        limit = limit/ii;
        ii = 1; 
      }
    }
    std::println("");
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
