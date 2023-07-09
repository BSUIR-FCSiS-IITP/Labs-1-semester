#include <iostream>

int main() {
    double x, y, max ;
    std::cin >> x >> y ;
    max = x >= y ? max = x : max = y ;
    std::cout << max ;
}
