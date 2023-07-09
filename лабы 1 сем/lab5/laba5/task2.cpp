#include <iostream>
#include <windows.h>
#include <regex>

bool isNumeric1(std::string const &str)
{
    return std::regex_match(str, std::regex("^([1-9]\\d*)$")) ;
}

bool isNumeric2(std::string const &str)
{
    return std::regex_match(str, std::regex(R"(^-?(0|[1-9]\d*)(\.\d+)?$)")) ;
}

int main(){
    HINSTANCE load ;
    load = LoadLibrary("libuntitled22.dll") ;
    typedef long double (*sum) (long double *, long long, long long) ;
    sum Sum ;
    Sum = (sum)GetProcAddress(load, "sum") ;
    std::cout << "Введите количество элементов массива:\n" ;
    long long n ;
    std::string s11 ;
    int q ;
    do {
        q = 0;
        std::cin >> s11;
        if (!isNumeric1(s11)) {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else break;
    } while (q != 0);
    n = std::stoll(s11) ;
    std::cout << "Введите массив:\n" ;
    long double a[n] ;
    for(int i = 0; i < n; ++i) {
        std::string line1;
        do {
            q = 0;
            std::cin >> line1;
            if (!isNumeric2(line1)) {
                ++q;
                std::cerr << "Введите корректные данные!\n";
            } else break;
        } while (q != 0);
        a[i] = std::stoll(line1) ;
        line1 = "" ;
    }
    std::cout << "Сумма квадратов:\n" << Sum(a, 0, n - 1) ;
    FreeLibrary(load) ;
}