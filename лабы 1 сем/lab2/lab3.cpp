#include <iostream>

int main() {
    int x, y ;
    double a, b, c, k ;
    std::cin >> x >> y ;
    if (x < y) x = 0 ;
    else if (x > y) y = 0 ;
    else {
        x = 0 ;
        y = 0 ;
    }
    std::cin >> a >> b >> c >> k ;
    if (a >= b && a >= c) a -= k ;
    else if (b >= a && b >= c) b -= k ;
    else if (c >= a && c >= b) c -= k ;
    std::cout << x << ' ' <<  y << "\n" ;
    std::cout << a << ' ' << b << ' ' <<  c ;
}
