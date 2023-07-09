#include <iostream>
#include <cmath>
using namespace std ;


int main() {
    double b1, n, q, s ;
    cout <<"b1=" ;
    cin >> b1 ;
    cout << "Введите n=" ;
    cin >> n ;
    q = 1/(n+1) ;
    s = b1 * (pow(q,n)-1) / (q-1) ;
    cout << "summa=" << s << endl ;
    return 0 ;
}
