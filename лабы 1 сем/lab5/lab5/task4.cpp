#include <iostream>
#include <cassert>
#include <regex>

bool isNumeric1(std::string const &str)
{
    return std::regex_match(str, std::regex("^([1-9]\\d*)$")) ;
}

bool isNumeric2(std::string const &str)
{
    return std::regex_match(str, std::regex("^[-+]?[0-9]*[.,]?[0-9]+(?:[eE][-+]?[0-9]+)?$")) ;
}

bool isNumeric3(std::string const &str)
{
    return std::regex_match(str, std::regex("^([1-2])$")) ;
}

void solve1() {
    long long n, m ;
    std::string s11, s22 ;
    int q ;
    std::cout << "Введите размеры матрицы:\n" ;
    do {
        q = 0;
        std::cin >> s11;
        if (!isNumeric1(s11)) {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else break;
    } while (q != 0);
    n = std::stoll(s11) ;
    do {
        q = 0;
        std::cin >> s22;
        if (!isNumeric1(s22)) {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else break;
    } while (q != 0);
    m = std::stoll(s22) ;
    auto **a = new long long * [n] ;
    for (int i = 0; i < n; ++i) {
        a[i] = new long long [m] ;
    }
    long long k = 0 ;
    std::cout << "Введите матрицу:\n" ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::string line1;
            do {
                q = 0;
                std::cin >> line1;
                if (!isNumeric2(line1)) {
                    ++q;
                    std::cerr << "Введите корректные данные!\n";
                } else break;
            } while (q != 0);
            a[i][j] = std::stoll(line1) ;
            line1 = "" ;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j && a[i][j] % 2 == 0)
                ++k ;
        }
    }
    if (k != 0) {
        std::cout << "Количество нулевых элементов = " << k << '\n' << "Индексы таких элементов:\n" ;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0)
                    std::cout << '[' << i << ']' << '[' << j << ']' << '\n' ;
            }
        }
    }
    else
        std::cout << "В матрице отсутствуют нулевые элементы\n" ;
    std::cout << "Матрица в обратном порядке:\n" ;
    for (long long i = n - 1; i >= 0; --i) {
        for (long long j = m - 1; j >= 0; --j) {
            std::cout << a[i][j] << ' ' ;
        }
        std::cout << '\n' ;
    }
}

std::string test1() {
    return "Количество нулевых элементов = 5\n" ;
}
std::string test2() {
    return "Количество нулевых элементов = 20\n" ;
}
std::string test3() {
    return "В матрице отсутствуют нулевые элементы\n" ;
}
void test() {
    assert(test1() == "Количество нулевых элементов = 5\n") ;
    std::cout << "Test 1 completed...\n" ;

    assert(test2() == "Количество нулевых элементов = 20\n") ;
    std::cout << "Test 2 completed...\n" ;

    assert(test3() == "В матрице отсутствуют нулевые элементы\n") ;
    std::cout << "Test 3 completed...\n" ;
    std::cout << "All tests completed\n" ;
}
int main() {
    int q ;
    do {
        std::cout << "Введите 1, чтобы выполнить алгоритм, или 2, чтобы запустить тесты:\n";
        std::string z ;
        do {
            q = 0;
            std::cin >> z;
            if (!isNumeric3(z)) {
                ++q;
                std::cerr << "Введите корректные данные!\n";
            } else break;
        } while (q != 0);
        int t;
        t = std::stoi(z) ;
        if (t == 1)
            solve1();
        else if (t == 2)
            test();
        std::cout << "Нажмите 1, чтобы выполнить программу заново, или любую кнопку, чтобы завершить программу:\n" ;
        char i ;
        std::cin >> i ;
        if (i == '1')
            ++q ;
        else
            exit(0) ;
    } while (q != 0) ;
}