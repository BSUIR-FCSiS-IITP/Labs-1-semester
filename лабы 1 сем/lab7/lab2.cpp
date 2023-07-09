#include <iostream>
#include <bitset>

std::string sum (const std::bitset<128>& b1, const std::bitset<128>& b2) {
    std::bitset<128> result;
    bool carry = false;
    std::string s ;
    for (size_t i = 0 ; i < 128; ++i) {
        unsigned value = b1[i] + b2[i] + (carry ? 1 : 0);
        carry = value > 1;
        result[i] = value % 2;
        s.push_back(result[i]);
    }
    return s;
}

int main() {
    std::cout << "Введите 2 числа:\n" ;
    long long n, m ;
    std::cin >> n >> m ;
    std::bitset<128> a(n) ;
    std::bitset<128> b(m) ;
    std::cout << "Сумма = \n" << sum(a,b) ;
}
