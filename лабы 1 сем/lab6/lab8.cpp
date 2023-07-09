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
    int o ;
    std::cin >> o ;
    int i = 1 ;
    while (i <= o) {
        std::string s1, s2 ;
        std::cin >> s1 >> s2;
        int r = 0 ;
        int j = 0 ;
        for (j ; j < s1.length(); ++j) {
            if (s1[j] == s2[0]) {
                int q = j ;
                size_t y = 1 ;
                while (q < s1.length() - 1 && s1[q + 1] == s2[y]) {
                    ++q;
                    ++y ;
                }
                while (q > 0 && s1[q - 1] == s2[y]) {
                    --q;
                    ++y ;
                }
                if (y == s2.length()) {
                    std::cout << "YES\n";
                    break ;
                }
                else
                    ++r ;
            }
            if (r != 0 && j == s1.length() - 1 || (s1.length() == 1 && s2.length() == 1 && s1[0] != s2[0])) {
                std::cout << "NO\n";
                r = 0;
            }
        }
        ++i ;
    }
}

std::string testing(std::string s1, std::string s2) {
    int r = 0;
    int j = 0;
    for (j; j < s1.length(); ++j) {
        if (s1[j] == s2[0]) {
            int q = j;
            size_t y = 1;
            while (q < s1.length() - 1 && s1[q + 1] == s2[y]) {
                ++q;
                ++y;
            }
            while (q > 0 && s1[q - 1] == s2[y]) {
                --q;
                ++y;
            }
            if (y == s2.length()) {
                return "YES";

            } else
                ++r;
        }
        if (r != 0 && j == s1.length() - 1 || (s1.length() == 1 && s2.length() == 1 && s1[0] != s2[0])) {
            return "NO";
        }
    }
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
            assert(testing("abcdef", "cdedcb") == "YES") ;
            assert(testing("aaa", "aaaaa") == "YES") ;
            assert(testing("ba", "baa") == "NO") ;
            assert(testing("aab", "baaa") == "NO") ;
            assert(testing("qwerty", "ewqwer") == "NO") ;
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