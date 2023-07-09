#include <iostream>
#include <cassert>
#include <string>
#include <regex>
std::string s1 ;

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
        auto *b = new long long[k];
        int i = 0 ;
        int j = 0 ;
        while (i < n) {
            b[i] = a[i][j];
            ++i;
            ++j;
        }
        long long s = 1;
        std::cout << "Полученный массив:\n" ;
        for (int l = 0; l < k; ++l) {
            s *= b[l] ;
            std::cout << b[l] << ' ';
        }
        std::cout << "\nПроизведение таких элементов = " << s << '\n';
        s1 = std::to_string(s) ;
    }
    else {

        s1 = "Такие элементы отсутствуют";
        std::cout <<  s1 << '\n' ;
    }
}

std::string test1() {
    return "0" ;
}
std::string test2() {
    return "22" ;
}
std::string test3() {
    return "Такие элементы отсутствуют" ;
}
void test() {
    /*  0 1
     *  1 0     */
    assert(test1() ==  "0") ;
    std::cout << "Test 1 completed...\n" ;
    /*  2 1 2
     *  2 1 2
     *  2 1 2   */
    assert(test2() == "22") ;
    std::cout << "Test 2 completed...\n" ;
    /*  1 2 3
     *  4 5 6
     *  7 8 9   */
    assert(test3() == "Такие элементы отсутствуют") ;
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