#include <iostream>
#include <regex>

void solve1() ;

int main() {
    int q ;
    do {
        q = 0 ;
        std::cout << "Введите 1, чтобы выполнить алгоритм, или любую кнопку, чтобы завершить программу:\n";
        char v ;
        std::cin >> v ;
        if (v == '1')
            solve1();
        else
            exit(0) ;
        std::cout << "Нажмите 1, чтобы выполнить программу заново, или любую кнопку, чтобы завершить программу:\n" ;
        char i ;
        std::cin >> i ;
        if (i == '1')
            ++q ;
        else
            exit(0) ;
    } while (q != 0) ;
}