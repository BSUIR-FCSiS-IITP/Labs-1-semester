#include <iostream>

int main() {
    int x, y ;
    std::cin >> x >> y ;
    if (x == 0 && y == 0) {
        std::cout <<"ERROR" ;
        exit(0) ;
    }
    if ((x == 0 && y != 0) || (x != 0 && y == 0)) {
        std::cout << "YES" ;
        exit(0) ;
    }
    if (x % y == 0 || y % x == 0) {
        std::cout << "YES" ;
        exit(0) ;
    }
    if (x % y != 0 || y % x != 0) {
        std::cout << "NO" ;
        exit (0) ;
    }
    else std::cout << "ERROR" ;
}