#include <iostream>
#include <cmath>

int main() {
    long int n, c, i, t, q, s ;
    std::cin >> n ;
    if (n <= 0) {
        std::cout << "Incorrect input" << '\n' ;
        exit(0) ;
    }
    c = 0 ;
    s = 0 ;
    for (i = 1; i <= n; ++i) {
        t = i ;
        while (t != 0) {
            t /= 10 ;
            ++c ;
        }
        t = i ;
        while (t != 0){
            q = t % 10 ;
            t /= 10 ;
            s += pow(q,c) ;
            q = 0 ;
        }
        if (s == i) std::cout << i << '\n' ;
        s = 0 ;
        c = 0 ;
    }
}