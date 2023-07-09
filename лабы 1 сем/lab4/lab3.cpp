#include <iostream>
#include <limits>
#include <random>

void process() {
        int n ;
        std::cout << "Введите порядок квадратной матрицы:" << '\n' ;
        std::cin >> n ;
        int i, j ;
        std::cout << "Исходная матрица:" << '\n' ;
        int **a = new int* [n];
        for (int count = 0; count < n; count++)
            a[count] = new int [n];
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n ; ++j) {
                std::random_device dev;
                std::mt19937 rng(dev());
                std::uniform_int_distribution<std::mt19937::result_type> dist100(-100,100);
                a[i][j] = dist100(rng) ;
                printf("%5d", a[i][j]);
            }
            std::cout << '\n' ;
        }
        std::cout << "Полученная матрица:" << '\n' ;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (a[i][j] >= a[j][j]) a[i][j] = 1 ;
                else a[i][j] = 0 ;
                printf("%5d", a[i][j]);
            }
            std::cout << '\n' ;
        }
        for (i = 0; i < n; ++i) {
            delete [] a[i] ;
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