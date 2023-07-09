#include <iostream>
#include <limits>
#include <random>

void process() {
    long long k, t;
    std::cout << "Введите количество элементов массива:" << '\n';
    std::cin >> k;
    if (std::cin.fail() || k >= 1e20) {
        while (std::cin.fail() || k >= 1e20) {
            std::cerr << "Введите корректные данные!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> k;
            long double a[k];
            t = 0;
            std::cout << "Введите массив чисел:" << '\n';
            for (long long i = 0; i < k; ++i) {
                std::cin >> a[i];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Некорректный ввод! Введите массив заново:\n";
                    i = 0;
                }
            }
            for (long long i = 0; i < k; ++i) {
                for (long long j = i + 1; j < k; ++j) {
                    if (a[j] < a[i]) ++t;
                }
            }
            std::cout << "Количество инверсий в массиве = " << t << '\n';
        }
    }
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
                            std::cerr << "Введите y или n!\n" ;
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