#include <iostream>
#include <iomanip>

int main() {
    long double a, b ,c ,d, Z ;
    std::cin >> a >> b >> c >> d ;
    if (c == 0) {
        std::cout << "ERROR" ;
        exit(0) ;
    }
    if (c >= d && a < d) Z = a + b / c ;
    else if (c < d && a >= d ) Z = a - b / c ;
    else Z = 0 ;
    std::cout << std::setprecision(20) << Z ;
    return 0 ;
}