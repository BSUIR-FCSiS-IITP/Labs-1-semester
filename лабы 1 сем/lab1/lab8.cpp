#include <iostream>

using namespace std;


int main() {
    int h1, min1, h2, min2,h,min,m ;
    cout << "Введите время начала: " ;
    cin >> h1 >> min1 ;
    cout << "Введите время окончания: " ;
    cin >> h2 >> min2 ;
    if (h2 < h1) h2 = h2 + 24 ;
    m = (h2 * 60 + min2) - (h1 * 60 + min1) ;
    h = m / 60 ;
    min = m % 60 ;
    cout << "Длительность = " <<  h << " часов " << min << " минут" << endl ;
    return 0;
}