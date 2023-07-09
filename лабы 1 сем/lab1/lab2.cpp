#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;


int main() {
    double g = 9.8 ;
    double h , t ;
    cin >> h ;
    t = sqrt(2 * h / g) ;
    cout << setprecision(9) << t ;
    return 0 ;
}