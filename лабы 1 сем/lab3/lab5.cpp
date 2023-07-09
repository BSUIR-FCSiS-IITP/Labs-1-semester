#include <iostream>

long double Pow (long double x, long double n) ;
long double factorial (int N) ;
long double Cos(long double x) ;

long double factorial (int N)
{
    if (N == 0) return 1;
    else if (N < 0) return 0;
    else
    {
        long double S = 1;
        for (int a = 1; a <= N; ++a){
            S *= a;
        }
        return S;
    }
}

long double Pow (long double x, long double n)
{
    long double r = 1;
    if (n == 0) return 1;
    else if (n > 0)
        for (int c = 0; c < n; c ++)
            r *= x;
    else if (n < 0)
    {
        for (int c = 0; c > n; c --)
        {
            r *= x;
        }
        r = 1 / r;
    }
    return r ;
}
long double Cos(long double x)
{
    int n = 200;
    long double sum = 0;
    for (int i = 0; i <= n; i++){
        long double f = Pow(-1, i)*Pow(x, 2*i)/factorial(2*i);
        sum += f;
    }
    return sum;
}



int main() {
    long double x ;
    long int i, q ;
    std::cout << "Введите количество чисел, от которых хотите посчитать функцию:" << '\n' ;
    std::cin >> q ;
    for (int j = 1; j <= q; ++j) {
        std::cout << "Введите x:" <<'\n' ;
        std::cin >> x ;
        std::cout << "2 * cos^2(x) - 1 = " << 2 * Pow(Cos(x),2) - 1 << '\n' ;
    }
}