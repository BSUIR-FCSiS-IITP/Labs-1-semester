#include <iostream>

double pow(double x, double n) ;
double pow(double x, double n){
    double num=1;
    for (int a=1; a<=n; a++){
        num=num*x;
    }
    return num;
}


int main() {
    double a, n, d, x, s, an ;
    int i ;
    std::cout << "Введите a0 = " ;
    std::cin >> a ;
    std::cout << "Введите разность d для прогрессии a = " ;
    std::cin >> d ;
    std::cout << "Введите a(n-1) = "  ;
    std::cin >> an ;
    i = 2 ;
    s = a ;
    n = (an- a) / d + 1 ;
    if (n != int(n)) {
        std::cout << "Введите корректные данные!" ;
        exit(0) ;
    }
    while (i <= n) {
        a = a + d ;
        x = pow(2, i-1) * a ;
        if (i % 2 == 0 && i > 1) x *= -1 ;
        s += x ;
        ++i ;
    }
    std::cout << s ;
}