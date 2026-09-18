#include <iostream>
#include <cstdio>
#include <print>
#include <iomanip> // for setw, setfill, left/right

int main() {
    int x = 42;
    double y = 3.14159;

    // std::cout (stream manipulators)
    std::cout << "L:[" << std::left  << std::setw(5) << x << "] "
              << "R:[" << std::right << std::setw(5) << x << "]\n";

    // std::printf (C-style format specifiers)
    std::printf("L:[%-5d] R:[%5d]\n", x, x);

    // std::print (C++23, Python-style formatting, also supports center!)
    std::print("L:[{:<05}] R:[{:05}] C:[{:^5}]\n", x, x, x);

    return 0;
}