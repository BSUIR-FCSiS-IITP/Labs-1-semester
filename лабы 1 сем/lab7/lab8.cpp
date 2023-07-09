#include <iostream>
#include <string>

int main() {
    long long n;
    std::cin >> n;
    if (n < 4) {
        std::cout << n;
        exit(0);
    }
    std::string s ;
    while (n >= 3) {
        s = std::to_string(n % 3) + s ;
        n /= 3 ;
    }
    s = std::to_string(n % 3) + s ;
    long long q1 = s.find("10") ;
    while(q1 != std::string::npos) {
        s.replace(q1, 2,"03");
        q1 = s.find("10");
    }
    int q2 = s.find("20");
    while(q2 != std::string::npos) {
        s.replace(q2,2,"13");
        q2 = s.find("20");
    }
    int q3 = s.find("30");
    while(q3 != std::string::npos) {
        s.replace(q3 ,2,"23");
        q3 = s.find("30");
    }
    while(s[0] == '0')
        s.erase(0,1);
    std::cout << s;
}