#pragma once
#include "Func_string.h"
union ball {
    bool a;
    long double num;
};
class student {
public:
    char surname[100];
    char name[100];
    long long group;
    ball ball;
    long long income;
    static long long find_student(long long n, char surname[]) {
        FILE* file;
        fopen_s(&file, "test.bin", "rb+");
        fseek(file, 0, 0);
        student temp;
        for (long long i = 0; i < n; i++) {
            fread((char*)(&temp), sizeof(student), 1, file);
            if (equal_string(surname, temp.surname)) {
                fclose(file);
                return i;
            }
        }
        fclose(file);
    }
    static void initialization(long long& n) {
        FILE* file;
        fopen_s(&file, "test.bin", "wb+");
        fseek(file, 0, 0);
        student s1, s2;
        std::cout << "Введите количество: ";
        std::cin >> n ;
        student temp;
        for (long long i = 0; i < n; i++) {
            std::cout << "Введите:\n" ;
            std::cout << "Фамилию " << i + 1 << " студента:\n";
            input_string(temp.surname);
            std::cout << "Имя " << i + 1 << " студента:\n";
            input_string(temp.name);
            std::cout << "Номер группы " << i + 1 << " студента:\n";
            std::cin >> temp.group ;
            std::cout << "Средний балл " << i + 1 << " студента:\n";
            std::cin >> temp.ball.num ;
            std::cout << "Доход на члена семьи " << i + 1 << " студента:\n";
            std::cin >> temp.income ;
            fwrite((char*)(&temp), sizeof(student), 1, file);
        }
        fclose(file);
    }
    static void output_file(long long n) {
        FILE* file;
        fopen_s(&file, "test.bin", "rb+");
        fseek(file, 0, 0);
        student temp;
        for (long long i = 0; i < n; i++) {
            fread((char*)(&temp), sizeof(student), 1, file);
            std::cout << "Фамилия " << i + 1 << " студента: " << temp.surname << '\n';
            std::cout << "Имя " << i + 1 << " студента: " << temp.name << '\n';
            std::cout << "Номер группы " << i + 1 << " студента:\n" << temp.group << '\n';
            std::cout << "Средний балл " << i + 1 << " студента:\n" << temp.ball.num << '\n';
            std::cout << "Доход на члена семьи " << i + 1 << " студента:\n" << temp.income << "\n\n";
        }
        fclose(file);

    }
    static void adding(long long& n) {
        FILE* file;
        fopen_s(&file, "test.bin", "rb+");
        fseek(file, sizeof(student) * n, 0);
        long long m;
        std::cout << "Введите количество студентов, которое нужно добавить:\n";
        std::cin >> m ;
        student temp;
        for (long long i = 0; i < m; i++) {
            std::cout << "Фамилию " << i + 1 << " студента:\n";
            input_string(temp.surname);
            std::cout << "Имя " << i + 1 << " студента:\n";
            input_string(temp.name);
            std::cout << "Номер группы " << i + 1 << " студента:\n";
            std::cin >> temp.group ;
            std::cout << "Средний балл " << i + 1 << " студента:\n";
            std::cin >> temp.ball.num ;
            std::cout << "Доход на члена семьи " << i + 1 << " студента: \n";
            std::cin >> temp.income ;
            fwrite((char*)(&temp), sizeof(student), 1, file);
        }
        fclose(file);
        n += m;

    }
    static void erasing(long long& n) {
        std::cout << "Введите фамилию студента, которого нужно удалить: ";
        char surname[100];
        input_string(surname);
        long long index = find_student(n, surname);
        if (index == -1) {
            std::cerr << "Не найдено совпадений\n";
            return;
        }
        FILE* file;
        fopen_s(&file, "test.bin", "rb+");
        student temp;
        for (long long i = index + 1; i < n; i++) {
            fseek(file, i * sizeof(student), 0);
            fread((char*)(&temp), sizeof(student), 1, file);
            fseek(file, sizeof(student) * (i - 1), 0);
            fwrite((char*)(&temp), sizeof(student), 1, file);
        }
        n--;
        fclose(file);
    }
    static void change(long long n) {
        FILE* file;
        long long a;
        std::cout << "Введите параметр, который нужно изменить ( введите 1 (фамилия), 2 (имя), 3 (номер группы), 4 (средний балл), 5 (доход) :\n";
        std::cin >> a ;
        while (!(a == 1 || a == 2 || a == 3 || a == 4 || a == 5)) {
            std::cerr << "Введите корректные данные!\n";
            std::cin >> a ;
        }
        char temp[100];
        std::cout << "Введите фамилию студента, чьи параметры нужно изменить: ";
        input_string(temp);
        long long index = find_student(n, temp);
        if (index == -1) {
            std::cerr << "Не найдено совпадений\n";
            return;
        }
        student temp1;
        fopen_s(&file, "test.bin", "rb+");
        fseek(file, sizeof(student) * index, 0);
        fread((char*)(&temp1), sizeof(student), 1, file);
        if (a == 1) {//изменение фамилли
            char name[100];
            std::cout << "Фамилия:\n";
            input_string(name);
            for (int i = 0; i < 100; i++)temp1.surname[i] = name[i];
        }
        else if (a == 2) {//изменение имени
            char name[100];
            std::cout << "Имя:\n";
            input_string(name);
            for (int i = 0; i < 100; i++)temp1.name[i] = name[i];
        }
        else if (a == 3) {//изменение группы
            long long group;
            std::cout << "Группа:\n";
            std::cin >> group ;
            temp1.group = group;
        }
        else if (a == 4) {//изменение среднего балла
            long double ball;
            std::cout << "Средний балл:\n";
            std::cin >> ball ;
            temp1.ball.num = ball;
        }
        else if (a == 5) {//изменение дохода на одного члена семьи
            long long incore;
            std::cout << "Доход: \n";
            std::cin >> incore ;
            temp1.income = incore;
        }
        fseek(file, sizeof(student) * index, 0);
        fwrite((char*)(&temp1), sizeof(student), 1, file);
        fclose(file);

    }
    static void special_task(long long n) {
        FILE* file;
        long long min_income = 400;
        fopen_s(&file, "test.bin", "rb+");
        fseek(file, 0, 0);
        student* first = new student [n];
        student* second = new student[n];
        student temp;
        long long l = 0, l1 = 0;
        for (long long i = 0; i < n; i++) {
            fread((char*)(&temp), sizeof(student), 1, file);
            if (temp.income < min_income)first[l++] = temp;
            else second[l1++] = temp;
        }
        for (long long s = l1 / 2; s > 0; s /= 2) {
            for (long long i = s; i < l1; i++) {
                for (long long j = i - s; j >= 0 && second[j].ball.num < second[j + 1].ball.num; j -= s) {
                    std::swap(second[j].ball.num, second[j + 1].ball.num);
                }
            }
        }
        for (long long i = 0; i < l; i++) {
            std::cout << "Фамилия " << i + 1 << " студента:\n" << first[i].surname << '\n';
            std::cout << "Имя " << i + 1 << " студента:\n" << first[i].name << '\n';
            std::cout << "Группа " << i + 1 << " студента:\n" << first[i].group << '\n';
            std::cout << "Средний балл " << i + 1 << " студента:\n" << first[i].ball.num << '\n';
            std::cout << "Доход " << i + 1 << " студента:\n" << first[i].income << "\n\n";
        }
        for (long long i = 0; i < l1; i++) {
            std::cout << "Фамилия " << i + 1 + l << " студента:\n" << second[i].surname << '\n';
            std::cout << "Имя " << i + 1 + l << " студента:\n" << second[i].name << '\n';
            std::cout << "Группа " << i + 1 + l << " студента:\n" << second[i].group << '\n';
            std::cout << "Средний балл " << i + 1 + l << " студента:\n" << second[i].ball.num << '\n';
            std::cout << "Доход " << i + 1 + l << " студента:\n" << second[i].income << "\n\n";
        }
        fclose(file);
        delete[] first;
        delete[] second;
    }
};