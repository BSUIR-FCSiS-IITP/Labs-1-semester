#include <iostream>
#include <limits>
#include <mm_malloc.h>
void process() {
        int p = 1;
        int n, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
        std::cout << "Введите размер массива:\n";
        std::cin >> n;
        if (std::cin.fail() || n <= 0)
        while (std::cin.fail() || n <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Введите корректные данные!\n";
            std::cin >> n ;
        }
        int ***array = (int ***) malloc(n * n * n * sizeof(int));
        for (int i = 0; i < n; i++) {
            array[i] = (int **) malloc(n * n * sizeof(int));
            for (int j = 0; j < n; j++) {
                array[i][j] = (int *) malloc(n * sizeof(int));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    array[i][j][k] = 1 + p;
                    std::cout  << array[i][j][k] << ' ';
                    p++;
                }
                std::cout << '\n' ;
            }
            std::cout << '\n' ;
        }
        for (int i = 0; i < n; i++) {
            d1 += array[i][i][i];
            d2 += array[n - i - 1][i][i];
            d3 += array[i][n - i - 1][i];
            d4 += array[n - i - 1][n - i - 1][i];
        }
        std::cout << '\n' << "Наибольшая сумма элементов диагонали: " << std::max(std::max(d1, d2), std::max(d3, d4))
                  << "\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                free(array[i][j]);
            free(array[i]);
        }
        free(array);
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