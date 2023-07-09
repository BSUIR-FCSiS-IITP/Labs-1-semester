#include <iostream>
#include <limits>

void process() {
    int sum = 0;
    int rows, columns;
    std::cout << "Введите размеры матрицы:\n" ;
    std::cin >> rows >> columns;
    if (std::cin.fail() || rows <= 0 || columns <= 0)
        while (std::cin.fail() || rows <= 0 || columns <= 0) {
            std::cerr << "Введите корректные данные!\n" ;
            std::cin.clear() ;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max()) ;
            std::cin >> rows >> columns ;
        }
    int numbers[rows][columns];

    std::cout << "Введите матрицу:\n" ;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            std::cin >> numbers[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            if (i == 0 && j ==0)
            {
                if (numbers[i][j] < numbers[i][j+1] && numbers [i][j] < numbers[i+1][j]
                    && numbers[i][j] < numbers [i+1][j+1])
                {
                    sum++;
                }
            }
            else if (i == 0 && j == columns){
                if (numbers[i][j] < numbers[i][j-1] && numbers [i][j] < numbers[i+1][j]
                    && numbers[i][j] < numbers [i+1][j-1])
                {
                    sum++;
                }
            }
            else if (i == rows && j == 0){
                if (numbers[i][j] < numbers[i-1][j] && numbers [i][j] < numbers[i-1][j+1]
                    && numbers [i][j] < numbers[i][j+1])
                {
                    sum++;
                }
            }
            else if (i == rows && j == columns){
                if (numbers[i][j] < numbers[i][j-1] && numbers [i][j] < numbers[i-1][j]
                    && numbers [i][j] < numbers[i-1][j-1])
                {
                    sum++;
                }
            }
            else if (i == 0 && j != 0 ){
                if (numbers[i][j] < numbers[i][j-1] && numbers [i][j] < numbers[i][j+1]
                    && numbers [i][j] < numbers[i+1][j - 1]
                    && numbers [i][j] < numbers[i+1][j+1] && numbers [i][j] < numbers[i+1][j])
                {
                    sum++;
                }
            }
            else if (i!= 0 && j == 0)
            {
                if (numbers[i][j] < numbers[i-1][j] && numbers [i][j] < numbers[i-1][j+1]
                    && numbers[i][j] < numbers[i][j+1]
                    && numbers [i][j] < numbers[i+1][j+1] && numbers [i][j] < numbers[i+1][j])
                {
                    sum++;
                }
            }
            else if (i!= 0 && j == columns){
                if (numbers[i][j] < numbers [i][j-1] && numbers[i][j] < numbers [i+1][j-1]
                    && numbers[i][j] < numbers [i + 1][j] && numbers[i][j] < numbers [i - 1][j - 1] &&
                    numbers[i][j] < numbers [i - 1][j]){
                    sum++;
                }
            }
            else if (i == rows && j != 0)
            {
                if (numbers[i][j] < numbers[i][j+1] && numbers[i][j] < numbers[i][j-1] &&
                    numbers[i][j] < numbers[i-1][j] && numbers[i][j] < numbers[i - 1][j-1] &&
                    numbers[i][j] < numbers[i - 1][j+1]){
                    sum++;
                }
            }
            else if (numbers[i][j] < numbers[i][j-1] && numbers [i][j] < numbers[i][j+1]
                     && numbers [i][j] < numbers[i-1][j] && numbers [i][j] < numbers[i-1][j-1]
                     && numbers [i][j] < numbers[i-1][j+1] && numbers [i][j] < numbers[i+1][j - 1]
                     && numbers [i][j] < numbers[i+1][j+1] && numbers [i][j] < numbers[i+1][j])
            {
                sum++;
            }
        }
    }
    std::cout << "Количество локальных минимумов = " << sum << '\n';
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