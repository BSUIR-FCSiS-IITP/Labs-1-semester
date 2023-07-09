#include <iostream>
#include <iomanip>
using namespace std ;

int main() {
    long double t, v0, a, s ;
    cin >> a ;
    cin >> t ;
    cin >> v0 ;
    s = v0*t + a*t*t/2 ;
    cout << setprecision(20) << s << endl ;
    return 0 ;
}