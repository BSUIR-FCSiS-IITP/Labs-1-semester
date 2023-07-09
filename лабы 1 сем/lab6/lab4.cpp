#include <iostream>
#include <string>
#include <algorithm>
class str {
public:
    static void solve(std::string s) {
        for (int i = 0; i < s.length(); ++i) {
            std::string t ;
            if (s[i] == 'c' || s[i] == 'C') {
                if (i < s.length() - 1 && s[i] == 'c' && (s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'y')) {
                    t = 's' ;
                    s.replace(i, 1, t) ;
                }
                else if (s[i] == 'c'){
                    t = 'k' ;
                    s.replace(i, 1, t) ;
                }
                if (i < s.length() - 1 && s[i] == 'C' && (s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'y')) {
                    t = 'S' ;
                    s.replace(i, 1, t) ;
                }
                else if (s[i] == 'C'){
                    t = 'K' ;
                    s.replace(i, 1, t) ;
                }
            }
            if (s[i] == 'q' || s[i] == 'Q') {
                if (i < s.length() - 1 && s[i] == 'q' && s[i + 1] != 'u') {
                    t = 'k';
                    s.replace(i, 1, t);
                }
                else if (i < s.length() - 1 && s[i] == 'q' && s[i + 1] == 'u') {
                    t = "kv" ;
                    s.replace(i, 2, t) ;
                }
                if (i < s.length() - 1 && s[i] == 'Q' && s[i + 1] != 'u') {
                    t = 'K';
                    s.replace(i, 1, t);
                }
                else if (i < s.length() - 1 && s[i] == 'Q' && s[i + 1] == 'u') {
                    t = "Kv" ;
                    s.replace(i, 2, t) ;
                }
            }
            if (s[i] == 'x') {
                t = "ks" ;
                s.replace(i, 1, t) ;
            }
            if (s[i] == 'X') {
                t = "Ks" ;
                s.replace(i, 1, t) ;
            }
            if (s[i] == 'w') {
                t = 'v' ;
                s.replace(i, 1, t) ;
            }
            if (s[i] == 'W') {
                t = 'W' ;
                s.replace(i, 1, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'p' && s[i + 1] == 'h') || (s[i] == 'p' && s[i + 1] == 'H'))) {
                t = 'f' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'P' && s[i + 1] == 'h') || (s[i] == 'P' && s[i + 1] == 'h'))) {
                t = 'F' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 2 && s[i] == 'y' && s[i + 1] == 'o' && s[i + 2] == 'u') {
                t = 'u' ;
                s.replace(i, 3, t) ;
            }
            if (i < s.length() - 2 && s[i] == 'Y' && s[i + 1] == 'o' && s[i + 2] == 'u') {
                t = 'U' ;
                s.replace(i, 3, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'o' && s[i + 1] == 'o') || (s[i] == 'o' && s[i + 1] == 'O'))) {
                t = 'u' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'O' && s[i + 1] == 'o') || (s[i] == 'O' && s[i + 1] == 'o'))) {
                t = 'U' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'e' && s[i + 1] == 'e') || (s[i] == 'e' && s[i + 1] == 'E'))) {
                t = 'i' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'E' && s[i + 1] == 'e') || (s[i] == 'E' && s[i + 1] == 'E'))) {
                t = 'I' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 't' && s[i + 1] == 'h') || (s[i] == 't' && s[i + 1] == 'H'))) {
                t = 'z' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && ((s[i] == 'T' && s[i + 1] == 'h') || (s[i] == 'T' && s[i + 1] == 'H'))) {
                t = 'Z' ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                t = s[i] ;
                s.replace(i, 2, t) ;
            }
            if (i < s.length() - 1 && tolower(s[i]) == s[i + 1]) {
                t = s[i + 1] ;
                s.replace(i, 2, t) ;
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            while (i < s.length() - 1 && (s[i] == s[i + 1]) || (s[i] == toupper(s[i + 1])) || (s[i] == tolower(s[i + 1]))) {
                s.erase(i + 1, 1) ;
            }
        }
        std::cout << s ;
    }
};
int main() {
    std::string s, s1 ;
    while (s1[s1.length() - 1] != '.') {
        getline(std::cin,s1) ;
        s += s1 ;
        s += '\n' ;
    }
    str::solve(s) ;
}