#include<iostream>
#include <cstring>
#define max 5000
long long m[max][max];

void m1(long long n)
{
    memset(m, 0, sizeof(m));
    long long x = 0, y = n / 2;
    for (long long i = 1; i <= n * n; i++)
    {
        m[x][y] = i;
        x--;                                 // По очереди заполняем правый верхний угол
        y++;
        if (x < 0 && y > n - 1) {
            x = x + 2;
            y = y - 1;
        }     // Превышение по диагонали
        else if (x < 0)
            x = x + n;                  // Превышение по верхней границе
        else if (y > n - 1)
            y = y - n;                // Превышение по правой границе
        else if (m[x][y] != 0) {
            x = x + 2; y = y - 1;
        }  // Правый верхний угол заполнен
    }
}

void m2(long long n)                  // Магический квадрат двойного четного порядка
{
    memset(m, 0, sizeof(m));
    for (long long i = 1, x = 0, y = 0; i <= n * n; i++)
    {
        m[x][y] = i;
        y++;
        if (y > n - 1) { x++; y -= n; }
    }
    for (long long i = 0; i < n; i++)                   // Разложите магический квадрат на m * m магических квадратов 4-го порядка и замените диагональные элементы каждого магического квадрата 4-го порядка его дополнением
        for (long long j = 0; j < n; j++)
            if (i % 4 == 0 && j % 4 == 0)             // Левая диагональ
                for (long long k = 0; k < 4; k++)
                    m[i + k][j + k] = (n * n + 1) - m[i + k][j + k];
            else if (i % 4 == 3 && j % 4 == 0)         // Правая диагональ
                for (long long k = 0; k < 4; k++)
                    m[i - k][j + k] = (n * n + 1) - m[i - k][j + k];
}
void m3(long long n)
{
    memset(m, 0, sizeof(m));
    long long n0 = n / 2;
    m1(n0);                            // Разложить магический квадрат на 2 * 2 магических квадрата нечетного порядка, вызвать функцию магического квадрата нечетного порядка для заполнения магического квадрата нечетного порядка в верхнем левом углу
    for (long long i = 0; i < n0; i++)
        for (long long j = 0; j < n0; j++)
        {
            m[i + n0][j + n0] = m[i][j] + n0 * n0;       // Заполняем нечетный магический квадрат в правом нижнем углу
            m[i][j + n0] = m[i + n0][j + n0] + n0 * n0;     // Заполняем нечетный магический квадрат в правом верхнем углу
            m[i + n0][j] = m[i][j + n0] + n0 * n0;       // Заполняем нечетный магический квадрат в левом нижнем углу
        }
    long long k = (n - 2) / 4;                             // Удовлетворение формуле n = 4 * k + 2
    for (long long i = 0; i < n0; i++)
        for (long long j = 0; j < k; j++)
            if (i == n0 / 2) std::swap(m[i][i + j], m[i + n0][i + j]);   // Меняем местами k элементов слева направо в середине магического квадрата в верхнем левом углу с соответствующими элементами в магическом квадрате в нижнем левом углу
            else std::swap(m[i][j], m[i + n0][j]);              // Поменять местами первые k элементов каждой строки верхнего левого магического квадрата, кроме средней строки, с соответствующими элементами в нижнем левом магическом квадрате
    for (long long i = 0; i < n0; i++)
        for (long long j = n0 + n0 / 2; j > n0 + n0 / 2 - (k - 1); j--)
            std::swap(m[i][j], m[i + n0][j]);                   // Меняем местами элементы в столбце k-1 справа налево в среднем столбце магического квадрата в верхнем правом углу с соответствующими элементами в магическом квадрате в правом нижнем углу
}

bool Check(long long n)
{
    long long cnt = n * (n * n + 1) / 2;                                // Сумма каждой строки, столбца и диагонали
    for (long long i = 0; i < n; i++)
    {
        long long sum_row = 0, sum_line = 0;
        for (long long j = 0; j < n; j++)
        {
            sum_row += m[i][j];                       // Проверяем строки
            sum_line += m[j][i];                      // Проверяем столбцы
        }
        if (sum_row != cnt || sum_line != cnt) return false;
    }
    long long sum_left = 0, sum_right = 0;
    for (long long i = 0; i < n; i++)
    {
        sum_left += m[i][i];                              // Проверяем левую диагональ
        sum_right += m[n - i - 1][i];                         // Проверяем правильную диагональ
    }
    if (sum_left != cnt || sum_right != cnt) return false;
    return true;
}

void print (long long n)                                       // Вывод квадрата
{
    for (long long i = 0; i < n; i++) {
        std::cout << std::endl;
        for (long long j = 0; j < n; j++) {
            printf("%8d", m[i][j]) ;
        }
    }
    std::cout << std::endl ;
}

int main() {
    std::cout << "Введите размер магического квадрата(для завершения программы введите 0)" << std::endl;
    long long n;
    while (std::cin >> n && n != 0) {
        if (std::cin.fail() || n < 0) {
            std::cin.clear() ;
            std::cerr << "Введите корректное значение!\n" ;
            continue ;
        }
        if (n == 1) {
            std::cout << 1;
        }
        if (n == 2) {
            std::cerr << "Невозможно создать магический квадрат 2 на 2" << std::endl;
        } else if (n & 1) {
            m1(n);
            if (Check(n)) {
                print(n);
            }
        }
        else if (!(n % 4)) {
            m2(n);
            if (Check(n)) {
                print(n);
            }
        }     // Выводим магический квадрат двойного четного порядка
        else {
            m3(n);
            if (Check(n)) {
                print(n);
            }
        }
    }
}