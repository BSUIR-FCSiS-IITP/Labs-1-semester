#include <iostream>
#include <cmath>

int main(){
    int q ;
    double x, f, y, z, a, c ;
    std::cout << "Введите z, a, c:" << '\n' ;
    std::cin >> z >> a >> c ;
    if (z < 1)  x = z * z + 1 ;
    else x = 1 / sqrt((z - 1)) ;
    std::cout << "Введите вариант(1, 2, 3): " ;
    std::cin >> q ;
    if (q == 1) {
        f = 2 * x ;
    }
    else if (q == 2) {
        f = pow(x, 3) ;
    }
    else if (q == 3) {
        f = x / 3 ;
    }
    else {
        std::cout << "Введите правильный номер!" ;
        exit(0) ;
    }
    y = a * pow(sin(pow(f, 2) - 1), 3) + c * log(fabs(x)) + exp(x) ;
    std::cout << "y = " << y ;
}