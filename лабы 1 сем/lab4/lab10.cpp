#include <iostream>
#include <limits>
#include <string>



void process() {
    int n ;
    std::cout << "Введите количество удлинителей:\n" ;
    std::cin >> n ;
    if (std::cin.fail() || n <= 0) {
        while (std::cin.fail() || n <= 0) {}
        std::cin.clear() ;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
        std::cerr << "Введите корректные данные!\n" ;
        std::cin >> n ;
    }
    int i = 1 ;
    int a = 0 ;
    int s = 0 ;
    std::cout << "Введите количество розеток в каждом удлинителе:\n" ;
    while (i <= n) {
        std::cin >> a ;
        if (std::cin.fail())
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Введите корректные данные!\n";
                std::cin >> a;
            }
        s += a ;
        ++i ;
    }
    s = s - (i - 2) ;
    std::cout << "Количество розеток в удлинителях = " << s << '\n' ;
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