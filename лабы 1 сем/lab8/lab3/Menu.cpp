#include "Menu.h"

void menu() {
    long long n, whatdo;
    std::cout << "Введите первое значение\n";
    student::initialization(n);
    while (1) {
        std::cout << "Введите\n 1 для просмотра бинарного файла\n2 для добавления новых студентов\n3 для удаления некоторых записей\n4 для изменения параметров определённых рейсов\n5 для просмотра содержимого в заданном в задании порядке\n";
        std::cin >> whatdo ;
        while (!(whatdo == 1 || whatdo == 2 || whatdo == 3 || whatdo == 4 || whatdo == 5)) {
            std::cerr << "Некорректный ввод!\n";
            std::cin >> whatdo ;
        }
        if (whatdo == 1)student::output_file(n);
        else if (whatdo == 2)student::adding(n);
        else if (whatdo == 3)student::erasing(n);
        else if (whatdo == 4)student::change(n);
        else if (whatdo == 5)student::special_task(n);
        long long a;
        std::cout << "Введите 1 для завершения программы, 0 для продолжения:\n";
        std::cin >> a ;
        while (!(a == 1 || a == 0)) {
            std::cerr << "Некорректный ввод!\n";
            std::cout << "Введите 1 или 0\n";
            std::cin >> a ;
        }
        if (a == 1)
            break;
    }
}