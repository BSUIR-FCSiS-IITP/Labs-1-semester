#include <iostream>

int main() {
    double k;
    int a ;
    std::cin >> k ;
    a = int(k) ;
    if (a != k) {
        std::cout << "Мы нашли " << k << " гриба в лесу" ;
        exit(0) ;
    }
    if (a % 100 > 10 &&  a % 100 < 20) {
        std::cout << "Мы нашли " << k << " грибов в лесу" ;
        exit(0) ;
    }
    else if (a % 10 > 1 && a % 10 < 5) {
        std::cout << "Мы нашли " << k << " гриба в лесу" ;
        exit(0) ;
    }
    else if (a % 10 == 1) {
        std::cout << "Мы нашли " << k << " гриб в лесу" ;
        exit(0) ;
    }
    else std::cout << "Мы нашли " << k << " грибов в лесу" ;
    return 0;
}