#include<cmath>
#include <iostream>
#define MAX 1000

long double rows_input()
{
    long double c;
    bool inin ;
    std::cout << "Введите количество строк:\n";
    do
    {
        std::cin >> c;
        inin = false;
        if ( c < 1 || c - floorl(c) != 0 || std::cin.peek() != ' ' && std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            inin = true;
            std::cout << "\nНекорректный ввод!\nПопробуйте ещё раз: \n";
        }
        if (c > MAX)
        {
            inin = true;
            std::cout << "\nВы ввели слишком большое число\nВведите другое значение\n";
        }
    } while (inin);
    return c;
}

long double columns_input()
{
    long double c;
    bool inin ;
    std::cout << "Введите количество столбцов:\n";
    do
    {
        std::cin >> c;
        inin = false;
        if (c < 1 || c - floorl(c) != 0 || std::cin.peek() != ' ' && std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            inin = true;
            std::cout << "\nНекорректный ввод!\nПопробуйте ещё раз: \n";

        }
        if (c > MAX)
        {
            inin = true;
            std::cout << "\nВы ввели слишком большое число\nВведите другое значение\n";
        }
    } while (inin);
    return c;
}

char bimbi(short b)
{
    char s ;
    if (b == 0)
    {
        s = '0';
    }
    if (b == 1)
    {
        s = '1';
    }
    if (b == 2)
    {
        s = '2';
    }
    if (b == 3)
    {
        s = '3';
    }
    if (b == 4)
    {
        s = '4';
    }
    if (b == 5)
    {
        s = '5';
    }
    if (b == 6)
    {
        s = '6';
    }
    if (b == 7)
    {
        s = '7';
    }
    if (b == 8)
    {
        s = '8';
    }
    return s ;
}


int main()

{
    std::setlocale(LC_ALL, "rus");
    std::cout << "На вход подаётся поле для игры в сапёр размером n*m символов, где символ '.' означает пустое место, а символ '*' - бомбу.\nТребуется дополнить это поле числами, как в оригинальной игре.\n\n\n";
    long double g ;
    do
    {
        long long rows = rows_input(), columns = columns_input();
        char** arr = new char* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new char[columns];
        }
        std::cout << "Заполнение массива:\n";
        //создание поля

            for (long i = 0; i < rows; i++)
            {
                for (long j = 0; j < columns; j++)
                {
                    do {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Введите элемент [" << i << "][" << j << "]: " << std::endl;
                        std::cin >> *(*(arr + i) + j);
                        if (std::cin.fail() || std::cin.peek() != '\n' || (*(*(arr + i) + j) != '.' && *(*(arr + i) + j) != '*'))
                        {
                            std::cout << "Неверный ввод, пожалуйста повторите" << std::endl;
                        }
                    } while (std::cin.fail() || std::cin.peek() != '\n' || (*(*(arr + i) + j) != '.' && *(*(arr + i) + j) != '*'));

                }
            }


            if (rows == 1 && columns > 1)
            {
                if (arr[0][1] == '*' && arr[0][0] == '.')
                {
                    arr[0][0] = '1';
                }
                if (arr[0][columns - 2] == '*' && arr[0][columns - 1] == '.')
                {
                    (arr[0][columns - 1] = '1');
                }

                for (long long i = 1; i < columns - 1; i++)
                {
                    if (arr[0][i] == '.')
                    {

                        short b = 0;
                        if (arr[0][i - 1] == '*')
                        {
                            b++;
                        }
                        if (arr[0][i + 1] == '*')
                        {
                            b++;
                        }
                        arr[0][i] = bimbi(b);



                    }

                }
                for (long long i = 0; i < columns; i++)
                {
                    std::cout << arr[0][i] << " ";
                }
                return 0;
            }


            ///один столбец
            if (rows > 1 && columns == 1)
            {
                if (arr[1][0] == '*' && arr[0][0] == '.')
                {
                    arr[0][0] = '1';
                }
                if (arr[rows - 2][0] == '*' && arr[rows - 1][0] == '.')
                {
                    (arr[rows - 1][0] = '1');
                }

                for (long long i = 1; i < rows - 1; i++)
                {
                    if (arr[i][0] == '.')
                    {

                        short b = 0;
                        if (arr[i - 1][0] == '*')
                        {
                            b++;
                        }
                        if (arr[i + 1][0] == '*')
                        {
                            b++;
                        }
                        arr[i][0] = bimbi(b);



                    }

                }
                for (long long i = 0; i < rows; i++)
                {
                    std::cout << arr[i][0] << "\n";
                }
                return 0;
            }

            ///полноценное
            if (rows > 1 && columns > 1)
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        if (arr[i][j] == '.')
                        {
                            ///левый верхний
                            if (i == 0 && j == 0)
                            {
                                short b = 0;
                                if (arr[1][0] == '*')
                                    b++;
                                if (arr[1][1] == '*')
                                    b++;
                                if (arr[0][1] == '*')
                                    b++;
                                arr[0][0] = bimbi(b);
                            }
                            ///правый верхний
                            if (i == 0 && j == columns - 1)
                            {
                                short b = 0;
                                if (arr[0][columns - 2] == '*')
                                    b++;
                                if (arr[1][columns - 2] == '*')
                                    b++;
                                if (arr[1][columns - 1] == '*')
                                    b++;
                                arr[0][columns - 1] = bimbi(b);
                            }
                            ///правый нижний
                            if (i == rows - 1 && j == columns - 1)
                            {
                                short b = 0;
                                if (arr[rows - 1][columns - 2] == '*')
                                    b++;
                                if (arr[rows - 2][columns - 2] == '*')
                                    b++;
                                if (arr[rows - 2][columns - 1] == '*')
                                    b++;
                                arr[rows - 1][columns - 1] = bimbi(b);
                            }
                            ///левый нижний
                            if (i == rows - 1 && j == 0)
                            {
                                short b = 0;
                                if (arr[rows - 1][1] == '*')
                                    b++;
                                if (arr[rows - 2][1] == '*')
                                    b++;
                                if (arr[rows - 2][0] == '*')
                                    b++;
                                arr[rows - 1][0] = bimbi(b);
                            }
                            ///левая вертикаль
                            if (i > 0 && i < rows - 1 && j == 0)
                            {
                                short b = 0;
                                if (arr[i - 1][0] == '*')
                                    b++;
                                if (arr[i - 1][1] == '*')
                                    b++;
                                if (arr[i][1] == '*')
                                    b++;
                                if (arr[i + 1][1] == '*')
                                    b++;
                                if (arr[i + 1][0] == '*')
                                    b++;
                                arr[i][j] = bimbi(b);
                            }
                            ///правая вертикаль
                            if (i > 0 && i < rows - 1 && j == columns - 1)
                            {
                                short b = 0;
                                if (arr[i - 1][columns - 1] == '*')
                                    b++;
                                if (arr[i - 1][columns - 2] == '*')
                                    b++;
                                if (arr[i][columns - 2] == '*')
                                    b++;
                                if (arr[i + 1][columns - 2] == '*')
                                    b++;
                                if (arr[i + 1][columns - 1] == '*')
                                    b++;
                                arr[i][j] = bimbi(b);
                            }
                            ///верхняя горизонталь
                            if (i == 0 && j > 0 && j < columns - 1)
                            {
                                short b = 0;
                                if (arr[i][j - 1] == '*')
                                    b++;
                                if (arr[i + 1][j - 1] == '*')
                                    b++;
                                if (arr[i + 1][j] == '*')
                                    b++;
                                if (arr[i + 1][j + 1] == '*')
                                    b++;
                                if (arr[i][j + 1] == '*')
                                    b++;
                                arr[i][j] = bimbi(b);
                            }
                            ///нижняя горизонталь
                            if (i == rows - 1 && j > 0 && j < columns - 1)
                            {
                                short b = 0;
                                if (arr[i][j - 1] == '*')
                                    b++;
                                if (arr[i - 1][j - 1] == '*')
                                    b++;
                                if (arr[i - 1][j] == '*')
                                    b++;
                                if (arr[i - 1][j + 1] == '*')
                                    b++;
                                if (arr[i][j + 1] == '*')
                                    b++;
                                arr[i][j] = bimbi(b);
                            }
                            ///центр
                            if (i > 0 && i < rows - 1 && j > 0 && j < columns)
                            {
                                short b = 0;
                                if (arr[i][j - 1] == '*')
                                    b++;
                                if (arr[i - 1][j - 1] == '*')
                                    b++;
                                if (arr[i - 1][j] == '*')
                                    b++;
                                if (arr[i - 1][j + 1] == '*')
                                    b++;
                                if (arr[i][j + 1] == '*')
                                    b++;
                                if (arr[i + 1][j - 1] == '*')
                                    b++;
                                if (arr[i + 1][j] == '*')
                                    b++;
                                if (arr[i + 1][j + 1] == '*')
                                    b++;

                                arr[i][j] = bimbi(b);
                            }

                        }
                    }
                }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
        bool ininin ;
        do {
            ininin = false;
            std::cout << "\n\n\nВведите 1 чтобы продолжить\nВведите отличное значение чтобы завершить выполнение программы\n";
            std::cin >> g;
            if (g > 2000000000)
            {
                ininin = true;
                std::cout << "\nВы ввели слишком большое число\nВведите другое значение\n";
            }
        } while (ininin);
        for (int i = 0; i < rows; i++)
            free(arr[i]);
        free(arr);
    } while (g == 1);
}