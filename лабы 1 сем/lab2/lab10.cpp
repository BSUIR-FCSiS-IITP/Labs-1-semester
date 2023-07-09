#include <iostream>
#include <cmath>

int main() {
    double x1, y1, r, x2, y2, R, a ;
    std::cout << "Введите x1, y1, r, x2, y2, R:" << '\n' ;
    std::cin >> x1 >> y1 >>  r >>  x2 >> y2 >> R ;
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) ;
    if (R > r && a <= r) {
        std::cout << "Да" ;
        exit(0) ;
    }
    else if (r > R && a <= R) {
        std::cout << "Да, но справедливо обратное для двух фигур" ;
        exit(0) ;
    }
    else if (a <= r + R) {
        std::cout << "Фигуры пересекаются" ;
        exit(0) ;
    }
    else std::cout << "Ни одно условие не выполнено" ;
}