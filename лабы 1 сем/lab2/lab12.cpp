#include <iostream>

int main() {
    long double a, b, c, x, y, pl , m, n;
    int q ;
    std::cin >> a >> b >> c >> x >> y;
    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        std::cout << "Incorrect input" ;
        exit(0) ;
    }
    pl = 1 ;
    m = 0 ;
    n = 0 ;
    if ((a <= b || a <= c) && (q < 2)) {
        if (m == 0) m = a ;
        else n = a ;
        ++q ;
    }
    if ((b <= a || b <= c) && (q < 2)) {
        if (m == 0) m = b ;
        else n = b ;
        ++q ;
    }
    if ((c <= a || c <= b) && (q < 2)) {
        if (m == 0) m = c ;
        else n = c ;
        ++q ;
    }
    if ((pl <= x * y) && (((m <= x) && (n <= y)) || ((n <= x) && (m <= y))) ) std::cout << "YES" ;
    else std::cout << "NO" ;
}
