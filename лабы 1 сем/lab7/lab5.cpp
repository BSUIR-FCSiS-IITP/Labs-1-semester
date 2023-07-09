#include <iostream>

int main() {
    long long n, q, i = 0;
    std::cin >> q ;
    while (i < q) {
        std::cin >> n;
        if (n < 9) {
            std::cout << 0 << '\n';
        }
        else {
            std::cout << (n - 9) / 10 + 1 << '\n';
        }
        ++i ;
    }
}