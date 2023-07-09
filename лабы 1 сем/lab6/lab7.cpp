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
    std::string s;
    std::cin >> s;
    int len = (int)s.length();
    bool isreps = true;
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            std::cout << len << '\n';
            return 0;
        }
        if (isreps && s[i] != s[0])
            isreps = false;
    }
    isreps ? std::cout << "0" << '\n' : std::cout << len - 1<< '\n';
    return 0;
}

long long testing(std::string s) {
    int len = (int)s.length();
    bool isreps = true;
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return len;
        }
        if (isreps && s[i] != s[0])
            isreps = false;
    }
    return len - 1;
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
            assert(testing("aba") == 2) ;
            assert(testing("ababababababa") == 12) ;
            assert(testing("aaaaaaaaaab") == 11) ;
            assert(testing("123456789123456789") == 18) ;
            assert(testing("aabbcbbaa") == 8) ;
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