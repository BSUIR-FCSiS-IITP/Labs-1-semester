#include <iostream>
#include <limits>

void process() {
    int n, m ;
    std::cout << "Введите размеры матрицы:" << '\n' ;
    std::cin >> n >> m ;
    if (std::cin.fail() || n <= 0 || m <= 0) {
        while (std::cin.fail() || n <= 0 || m <= 0) {
            std::cin.clear() ;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n') ;
            std::cerr << "Введите корректные данные!\n" ;
            std::cin >> n >> m ;
        }
    }
    std::cout << "Введите исходную матрицу:\n" ;
    int **a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int [m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++j) {
            std::cin >> a[i][j] ;
            for (int k = 0; k <= i; ++k) {
                for (int l = 0; l <= j; ++l) {
                    if (std::cin.fail()){
                        std::cin.clear() ;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n') ;
                        std::cerr << "Некорректный ввод! Введите матрицу заново:\n" ;
                        i = 0 ;
                        j = 0 ;
                    }
                }
            }
        }
    }
    std::cout << "Минимальные элементы каждого столбца:" << '\n' ;
    for (int j = 0; j < n; ++j) {
        int min = a[0][j] ;
        for (int i = 0; i < m; ++i) {
            if (a[i][j] <= min) min = a[i][j] ;
        }
        std::cout << min << ' ' ;

    }
    std::cout << '\n' ;
    for (int i = 0; i < n; ++i) {
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