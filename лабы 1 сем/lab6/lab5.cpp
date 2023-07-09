#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

long long mypowl(long long k, long long n, long long t) {
    if (n < 0) return 0;
    if (n == 2) return ((k % t) * (k % t)) % t;
    if (n == 1) return k % t;
    if (n == 0) return 1;
    if (n % 2 == 0) return ((mypowl(k, n / 2, t) % t) * (mypowl(k, n / 2, t) % t)) % t;
    if (n % 2 == 1) return ((mypowl(k, n / 2, t) % t) * (mypowl(k, n / 2 + 1, t) % t)) % t;
}

void TwoStringMaxSubstring(std::string str1, std::string str2, long long &max, long long &pos) {
    long long len ;

    if (str1.empty() || str2.empty())
        return;

    long long len1 = str1.length();
    long long len2 = str2.length();

    if (len1 >= len2)
        len = len1;
    else
        len = len2;

    long long topline[len];
    long long currentline[len];

    for (long long i = 0; i < len; i++) {
        topline[i] = 0;
        currentline[i] = 0;
    }

    char temp_ch ;


    for (long long i = 0; i < len2; i++) {
        temp_ch = str2[i];

        for (long long j = 0; j < len1; j++)
            if (temp_ch == str1[j]) {
                if (j == 0) {
                    currentline [j] = 1;
                }
                else {
                    currentline [j] = topline [j-1] + 1;
                }

                if (currentline[j] > max) {
                    max = currentline[j];
                    pos = j;
                }
            }

        for (long long k = 0; k < len; k++) {
            topline[k] = currentline[k];
            currentline[k] = 0;
        }
    }
}

long long a = 0 ;
int solve() {
    long long o ;
    std::cin >> o ;
    long long j = 0 ;
    while (j < o) {
        long long l, m ;
        std::string s1, s2 ;
        std::cin >> l >> m >> s1 >> s2 ;
        long long max = 0, pos = 0 ;
        TwoStringMaxSubstring(s1, s2, max, pos);
        long long k = s1.substr(pos - max + 1, max).length() ;
        long long res = 0, res1 = 0, res2 = 0;
        if ((s1.length() + s2.length() > l) && k != 0 && ((s1.find(s1.substr(pos - max + 1, max)) + k == s1.length() &&
        s2.find(s1.substr(pos - max + 1, max)) == 0) || (s2.find(s1.substr(pos - max + 1, max)) + k == s2.length() &&
        s1.find(s1.substr(pos - max + 1, max)) == 0)) && (s1.length() + s2.length() - k == l)) {
            if (s1[0] == s2[s2.length() - 1] && s1[s1.length() - 1] == s2[0])
                res1 = 2 ;
            else
                res1 = 1 ;
        }
        if (l - (long long)s1.length() - (long long)s2.length() + k >= 0) {
            if (l - (long long)s1.length() - (long long)s2.length() >= 0) {
                res1 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length(), m));
            }
            else {
                res1 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length() + (s2.length() - k - 1), m));
            }
        }
        if (l - (long long)s1.length() - (long long)s2.length() + k  >= 0) {
            if (l - (long long)s1.length() - (long long)s2.length() >= 0) {
                res2 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length(), m));
            }
            else {
                res2 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length() + k, m));
            }
        }
        if (s1 == s2) res = res2 % m;
        else res = (res2 + res1) % m;
        std::cout << res % m << '\n';
        ++j ;
    }
}

long long testing(long long l, long long m, std::string s1, std::string s2) {
    long long max = 0, pos = 0 ;
    TwoStringMaxSubstring(s1, s2, max, pos);
    long long k = s1.substr(pos - max + 1, max).length() ;
    long long res = 0, res1 = 0, res2 = 0;
    if ((s1.length() + s2.length() > l) && k != 0 && ((s1.find(s1.substr(pos - max + 1, max)) + k == s1.length() &&
                                                       s2.find(s1.substr(pos - max + 1, max)) == 0) || (s2.find(s1.substr(pos - max + 1, max)) + k == s2.length() &&
                                                                                                        s1.find(s1.substr(pos - max + 1, max)) == 0)) && (s1.length() + s2.length() - k == l)) {
        if (s1[0] == s2[s2.length() - 1] && s1[s1.length() - 1] == s2[0])
            res1 = 2 ;
        else
            res1 = 1 ;
    }
    if (l - (long long)s1.length() - (long long)s2.length() + k >= 0) {
        if (l - (long long)s1.length() - (long long)s2.length() >= 0) {
            res1 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length(), m));
        }
        else {
            res1 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length() + (s2.length() - k - 1), m));
        }
    }
    if (l - (long long)s1.length() - (long long)s2.length() + k  >= 0) {
        if (l - (long long)s1.length() - (long long)s2.length() >= 0) {
            res2 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length(), m));
        }
        else {
            res2 = (mypowl(26, l - (long long)s1.length() - (long long)s2.length() + k, m));
        }
    }
    if (s1 == s2) res = res2 % m;
    else res = (res2 + res1) % m;
    return  (res % m) ;
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
            assert(testing(4, 1000, "qwe", "weq") == 1) ;
            assert(testing(7, 1000, "russian", "cup") == 0) ;
            assert(testing(1000000, 10000, "a", "a") == 576) ;
            assert(testing(5, 1000, "qwe", "weq") == 26) ;
            assert(testing(5, 1000, "a", "aaaaaaaaaa") == 0) ;
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