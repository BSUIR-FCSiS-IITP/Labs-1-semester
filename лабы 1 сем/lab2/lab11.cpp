#include <iostream>
#include <cmath>

int main() {
    long double r, p, q, r_vp, d1 ;
    const double Pi = 3.14159 ;
    std::cout << "Введите радиус шара, сторону отверстия и угол(в градусах):" << '\n' ;
    std::cin >> r >> p >> q ;
    if (r <= 0 || p <= 0 || q <= 0) {
        std::cout << "Incorrect input" ;
        exit(0) ;
    }
    q = q / 2;
    q = (q * Pi) / 180;
    if (q > 0 && q < 90) d1 = 2 * p * sin(q);
    else if (q > 90 && q < 180) d1 = 2 * p * cos(q);
    else if (q == 90) d1 = p ;
    if (2 * r <= d1) std::cout << "YES" ;
    else std::cout << "NO" ;
}

