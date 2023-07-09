#include <iostream>
using namespace std ;

int main() {
    double x, a, p, q, p1, p2 ;
    cout << "Введите x = " ;
    cin >> x ;
    q = x * x ;
    p = 69 * q + 8 ;
    a = x * (23 * q + 32) ;
    p1 = p + a ;
    p2 = p - a ;
    cout << p1 << endl << p2 << endl ;
    return 0 ;
}