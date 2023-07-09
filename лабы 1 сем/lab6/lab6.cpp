#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

long long fact(long long n) {
    if (n == 0)
        return 0 ;
    long long s = 1 ;
    for (long long i = 1; i <= n; ++i) {
        s *= i ;
    }
    return s ;
}
int solve() {
    std::string s, s1 ;
    std::cin >> s ;
    long long k = 1 ;
    for (int i = 0; i < s.length(); ++i) {
        if (s1.find(s[i]) == std::string::npos) {
            k *= fact(std::count(s.begin(), s.end(), s[i]));
            s1 += s[i];
        }
    }
    std::cout << fact(s.length()) / k << '\n' ;
}

long long testing(std::string s) {
    std::string s1 ;
    long long k = 1 ;
    for (int i = 0; i < s.length(); ++i) {
        if (s1.find(s[i]) == std::string::npos) {
            k *= fact(std::count(s.begin(), s.end(), s[i]));
            s1 += s[i];
        }
    }
    return (fact(s.length()) / k) ;
}


int main() {
    int q ;
    do {
        std::cout << "Введите 1, чтобы выполнить алгоритм, или 2, чтобы запустить тесты:\n";
        int t ;
        std::cin >> t ;
        if (t == 1)
            solve();
        else if (t == 2) {
            assert(testing("SOLO") == 12) ;
            assert(testing("aaa") == 1) ;
            assert(testing("aaaaaaaaaaaaaaaaaaaaaaaaaab") == 3) ;
            assert(testing("weq") == 6) ;
            assert(testing("abcdefghijklmnoprst") == 121645100408832000) ;
            std::cout << "All tests successfully completed.\n" ;
        }
        std::cout << "Нажмите 1, чтобы выполнить программу заново, или любую кнопку, чтобы завершить программу:\n" ;
        char i ;
        std::cin >> i ;
        if (i == '1')
            ++q ;
        else
            exit(0) ;
    } while (q != 0) ;
}