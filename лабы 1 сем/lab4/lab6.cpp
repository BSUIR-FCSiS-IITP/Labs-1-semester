#include <iostream>
#include <limits>
#include <string>

void process() {
    long long x ;
    std::cout << "Введите число:\n" ;
    std::cin >> x ;
    if (std::cin.fail() || x <= 0 )
        while (std::cin.fail() || x <= 0) {
            std::cin.clear() ;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n') ;
            std::cerr << "Введите корректные данные!\n" ;
            std::cin >> x ;
        }
    long long c = 1 ;
    long long t = x ;
    while (t / 10 != 0) {
        ++c ;
        t /= 10 ;
    }
    std::cout << "Количество цифр в числе = " << c << '\n';
    std::cout << "Введите разряд числа:\n" ;
    long long n ;
    std::cin >> n ;
    if (std::cin.fail() || n < 0 || n >= c)
        while (std::cin.fail() || n < 0 || n >=c) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Введите корректные данные!\n";
            std::cin >> n ;
        }
    auto* a = new long long [c] ;
    long long q = x ;
    if (c == 1) a[0] = x ;
    for (int i = 0; i < c; ++i) {
        long long p ;
        p = q % 10 ;
        a[i] = p ;
        q /= 10 ;
    }
    std::cout << "Цифра с данным разрядом = " << a[n] << '\n' ;
    delete [] a ;
}
void context() {
    std::cout << "Суть задания:\nНайти кол-во инверсий в массиве\n\n"
                 "Выполнил задание:\nРешетнёв Арсений(253504)\n\nНомер варианта:\n12\n\n" ;
}

int main(){
    std::string t ;
    int w ;
    do {
        w = 0 ;
        std::cout << "Введите 1 для запуска алгоритма ,2 для вывода контекстного меню или 3 для завершения программы:"
                  << '\n';
        getline(std::cin, t) ;
        if (std::cin.fail() || (t != "1" && t != "2" && t != "3")) {
            while (std::cin.fail() || (t != "1" && t != "2" && t != "3")) {
                std::cerr << "Введите корректные данные!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> t;
            }
        }
        if (t == "3") exit(0) ;
        if (t == "1") {
            int q ;
            do {
                q = 0 ;
                process();
                std::cout << "Хотите заново выполнить алгоритм?(y/n)" << '\n';
                char s ;
                std::cin >>  s ;
                while ((s != 'y' && s != 'n') || std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Введите y или n!\n" ;
                    std::cin >> s ;
                }
                if (s == 'y') ++q;
                else if (s == 'n') exit(0);
            } while (q == 1);
        }
        else if (t == "2") {
            context();
            ++w;
        }
    } while (w == 1) ;
}