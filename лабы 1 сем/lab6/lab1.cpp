#include <iostream>
#include <string>

int main() {
    std::string s, s1, s2 ;
    std::cout << "Введите строку:\n" ;
    getline(std::cin, s) ;
    std::cout << "Введите k:\n" ;
    long long k ;
    std::cin >> k ;
    while (k < 0 || k > s.length() - 1) {
        std::cerr << "Введите корректное значение k:\n" ;
        std::cin.clear() ;
        std::cin.ignore() ;
        std::cin >> k ;
    }
    while (s[k] != ' ' && k > 0)
        --k ;
    if (k > 1)
        for (int i = 0; i <= k; ++i) {
            s1 += s[i] ;
        }
    for (int i = k + 1; i < s.length(); ++i) {
        s2 += s[i] ;
    }
    std::cout << "1-я строка:\n" << s1 << "\n2-я строка:\n" << s2 ;
}