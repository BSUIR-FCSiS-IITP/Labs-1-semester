#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double y, x, i, h ;
    const int m = 20 ;
    const int a = 0 ;
    const double b = M_PI / 2 ;
    h = (b-a) / m ;
    for (i = 0; i <= 20; ++i) {
        x = a + i * h ;
        y = sin(x) - cos(x) ;
        std::cout << y << '\n' ;
    }
}