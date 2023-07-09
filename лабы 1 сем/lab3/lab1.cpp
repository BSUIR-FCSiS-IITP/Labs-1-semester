#include <iostream>
#include <cmath>

int main() {
    int  N, a, b ;
    int i ;
    N = 0 ;
    i = 1 ;
    while (i <= 30) {
        if (i % 2 == 1) {
            a = i ;
            b = pow(i, 2) ;
        }
        else {
            a = i / 2 ;
            b = pow(i, 3) ;
        }
        N += pow(a - b, 2) ;
        ++i ;
    }
    std::cout << N ;
}