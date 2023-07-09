#include <iostream>
#include <string>
#include <bitset>


int main() {
    long long n ;
    std::cin >> n ;
    std::string s1 ;
    std::bitset<64ULL> s(n) ;
    s1 = s.to_string() ;
    while (s1[0] == '0')
        s1.erase(0, 1) ;
    std::cout << s1 ;
}