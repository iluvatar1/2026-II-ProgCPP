#include <print>
#include <cmath>

bool is_prime(long mynum);

int main(void)
{
    long a = 7;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 2;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 3;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 111;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 1;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 20;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 0;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 1000000006;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 1000000007;
    std::println("is_prime({}) = {}", a, is_prime(a));

    a = 100000000003;
    std::println("is_prime({}) = {}", a, is_prime(a));

    return 0;
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
