#include <iostream>
#include <string>

int main() {
    std::string s ;
    long long n ;
    std::cin >> n ;
    while (n >= 1000) {
        s.push_back('M') ;
        n -= 1000 ;
    }
    while (n >= 100) {
        if (n / 900 == 1 && n % 900 >= 0 && n % 900 < 100) {
            s.push_back('C') ;
            s.push_back('M') ;
            n -= 900 ;
        }
        else {
            s.push_back('C') ;
            n -= 100 ;
        }
    }
    while (n >= 10) {
        if (n / 90 == 1 && n % 90 >= 0 && n % 90 < 10) {
            s.push_back('X') ;
            s.push_back('C') ;
            n -= 90 ;
        }
        else if (n / 50 == 1 && n % 50 >= 0 && n % 50 < 10) {
            s.push_back('L') ;
            n -= 50 ;
        }
        else if (n / 40 == 1 && n % 40 >= 0 && n % 40 < 10) {
            s.push_back('X') ;
            s.push_back('L') ;
            n -= 40 ;
        }
        else {
            s.push_back('X') ;
            n -= 10 ;
        }
    }
    while (n > 0) {
        if (n == 9) {
            s.push_back('I') ;
            s.push_back('X') ;
            n -= 9 ;
        }
        else if (n >= 5) {
            s.push_back('V') ;
            n -= 5 ;
        }
        else if (n >= 4) {
            s.push_back('I') ;
            s.push_back('V') ;
            n -= 4 ;
        }
        else {
            s.push_back('I') ;
            n -= 1 ;
        }
    }
    std::cout << s ;
}