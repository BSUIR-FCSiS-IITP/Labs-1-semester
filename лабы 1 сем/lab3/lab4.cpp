#include <iostream>

int main() {
    int n, s, number, a1, an ;
    std::cout << "Введите 1, чтобы решить с помощью цикла, или 2, чтобы решить без цикла: " << '\n' ;
    std::cin >> number ;
    std::cout << "Введите n: " << '\n' ;
    std::cin >> n ;
    s = 0 ;
    a1 = 2 ;
    switch (number) {
        case 1:
            if (n > 0) {
                for (int i = 1; i <= n; ++i)
                    if (i % 2 == 0) s += i;
            }
            else if (n <= 0) {
                for (int i = 1; i >= n; --i)
                    if (i % 2 == 0) s += i;
            }
            std::cout << s ;
            break ;
        case 2:
            if (n % 2 == 0 ) an = n ;
            else an = n - 1;
            s = (a1 + an) / 2 * (an  / 2) ;
            std::cout << s ;
            break ;
        default:
            std::cout << "Incorrect input" ;
            exit(0) ;
    }
}