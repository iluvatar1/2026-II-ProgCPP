#include <print>
#include <valarray>

int main()
{
  std::valarray<int> data = {0,1,2,3,4,5,6,7,8,9};

  std::println("Initial valarray: ");
  for(int n: data) { // for automatico en limites
    std::print("{}", n);
  }
  std::println();

  data[data > 5] = -1; // valarray<bool> overload of operator[]
  // the type of data>5 is std::valarray<bool>
  // the type of data[data>5] is std::mask_array<int>

  std::println("After v[v>5]=-1: ");
  std::println("{}", data);
}