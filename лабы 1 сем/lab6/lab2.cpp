#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, s1 ;
    long long max = 0 ;
    getline(std::cin, s) ;
    char q ;
    for (int i = 0; i < s.length(); ++i) {
        if (s1.find(s[i] == std::string::npos)) {
            s1 += s[i] ;
            long long a = std::count(s.begin(), s.end(), s[i]) ;
            if (a > max) {
                max = a;
                q = s[i] ;
            }
        }
    }
    if (q == ' ')
        std::cout << "Символ:\nПробел" << "\nКоличество вхождений:\n" << max ;
    else
        std::cout << "Символ:\n" << q << "\nКоличество вхождений:\n" << max ;
}