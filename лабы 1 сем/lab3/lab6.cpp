#include <iostream>
#include <cmath>

int main() {
    double x, n, f, min, minf ;
    std::cout << "Введите количество интервалов:" << '\n' ;
    std::cin >> n ;
    n = 1 / n ;
    min = 0 ;
    x = 0 ;
    minf =  sinh(x) + acos(x) - 1.5;
    f = 0 ;
    while (x <= 1) {
        f = sinh(x) + acos(x) - 1.5 ;
        if (fabs(minf) >= fabs(f)) {
            min = x ;
            minf = f ;

        }
        x += n ;
    }
    std::cout << min  ;
}