#include <print>
#include <limits>

int main() {
    std::println("Machine epsilon (double): {:.18}", 
                 std::numeric_limits<double>::epsilon());

    double one = 1.0;
    double tiny = 1e-17;
    std::println("1.0 + 1e-17 == 1.0? {}", 
                 (one + tiny) == one ? "True (Lost in truncation)" : "False");

    return 0;
}