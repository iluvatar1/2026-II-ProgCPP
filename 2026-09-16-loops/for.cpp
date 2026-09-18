#include <print>

void print_numbers(int mymin, int mymax);

int main(void)
{
    //print_numbers(5, 223);
    print_numbers(15, 22);

    return 0;
}

void print_numbers(int mymin, int mymax)
{
    for (int ii = mymin; ii <= mymax; ii += 1) {
    //   if (ii % 3 == 0 and ii % 7 == 0) {
    //     std::println("{} ", ii);
    //   }
    if (ii % 3 != 0 or ii % 7 != 0) continue;
    std::println("{} ", ii);
    }

}
