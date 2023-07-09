#include <iostream>

int main() {
    long long n, q, l, k, znak;
    std::cout << "Введите число:";
    std::cin >> k ;
    if (k < 0) {
        k *= -1;
        znak = 1;
    }
    bool flag7 = false, flag79 = false, flag107 = false;
    n = k;
    if (n == 7)
        flag7 = true;
    while (n >= 2 * 7 - 1) {
        l = n >> 1;
        if (n & 1) {
            q = 4;
        }
        else {
            q = 0;
        }
        if (l + q == 7) {
            flag7 = true;
        }
        n = n >> 1;
        n += q;
    }
    n = k;
    if (n == 79)
        flag79 = true;
    while (n >= 2 * 79 - 1) {
        l = n >> 1;
        if (n & 1) {
            q = 40;
        }
        else {
            q = 0;
        }
        if (l + q == 79) {
            flag79 = true;
        }
        n = n >> 1;
        n += q;
    }
    n = k;
    if (n == 107)
        flag107 = true;
    while (n >= 2 * 107 - 1) {
        l = n >> 1;
        if (n & 1) {
            q = 54;
        }
        else {
            q = 0;
        }
        if (l + q == 107) {
            flag107 = true;
        }
        n = n >> 1;
        n += q;
    }
    if (znak == 1)
        k *= -1 ;
    if (flag7)
        std::cout << "Число " << k << " делится на 7\n";
    else
        std::cout << "Число " << k << " не делится на 7\n";
    if (flag79)
        std::cout << "Число " << k << " делится на 79\n";
    else
        std::cout << "Число " << k << " не делится на 79\n";
    if (flag107)
        std::cout << "Число " << k << " делится на 107\n";
    else
        std::cout << "Число " << k << " не делится на 107\n";
}