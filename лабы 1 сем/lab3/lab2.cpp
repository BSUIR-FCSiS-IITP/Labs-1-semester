#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double d, s, k, a, b ;
    int n ;
    std::cout << "Введите n:" << '\n' ;
    std::cin >> n ;
    s = 0 ;
    k = 1 ;
    do {
        d = pow(0.5, k) + pow(0.33, k) ;
        s += d ;
        ++k ;
    } while (d >= pow(10,-3) && k <= n) ;
    std::cout << std::setprecision(3) << s ;
}