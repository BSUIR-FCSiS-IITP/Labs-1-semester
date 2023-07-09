#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double myabs(long double d)
{
    if (d < 0) d *= (-1);
    return d;
}

long double fact (int N)
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


long double Pow(long double a, long double b)
{
    long double r = 1;
    if (b == 0) return 1;
    else if (b > 0)
    {
        for (int c = 0; c < b; c ++)
        {
            r *= a;
        }
    }
    else if (b < 0)
    {
        for (int c = 0; c > b; c --)
        {
            r *= a;
        }
        r = 1/r;
    }
    return r;
}

long double Sin(long double x)
{
    int n = 20;
    long double sum = 0;
    for (int i = 0; i <= n; i ++)
    {
        long double f = Pow(-1, i) * Pow(x, 2*i + 1)/fact(2*i + 1);
        sum += f;
    }
    return sum;
}

long double Cos(long double x)
{
    int n = 20;
    long double sum = 0;
    for (int i = 0; i <= n; i++){
        long double f = Pow(-1, i)*Pow(x, 2*i)/fact(2*i);
        sum += f;
    }
    return sum;
}

long double ln(long double x)
{
    long double LN2 = 0.693147180559945309417232121458176568;
    const long double e = 1e-9;
    const long double lnln = LN2; //ln2
    int k = 0;
    while (x>2.0)
    {
        x /= 2.0;
        k++;
    }
    x -= 1.;
    long double s = 0;
    int n = 1;
    long double an = x;
    while (myabs(an) > e) {
        s += an;
        ++n;
        an *= -x * (n - 1) / n;
    }
    s += k * lnln;
    return s;
}


int main()
{
    long double a;
    cout << "Введите угол в радианах " << endl;
    cin >> a;
    if (cin.fail())
    {
        cout << "Incorrect input" << endl;
        return 0;
    }

    while (a >= 1e16 || a < -1e10) {
        cout << "слишком большое число, пожалуйста, введите число меньше" << endl;
        cout << "введите угол в радианах в пределах  [-1e10; 1e15]" << endl;
        cin >> a;
    }

    long double z = a;
    long double w = 1e-16;
    const long double Pi = 3.14159265358979323846264338327950288;
    while (a > 1e16){
        a -= 2 * Pi - 1e12;

    }
    if (a >= 1e15 )
    {
        a = (a * 180) / Pi;
        while (a > 180 * 1e8)
        {
            a = a - 360 * 1e7;
        }
        a = a * Pi / 180;
    }

    if (a > 1e5 && a < 1e15)
    {
        a = (a * 180) / Pi;
        while (a > 180)
        {
            a = a - 360 * 1e4;
        }
        a = a * Pi / 180;
    }

    a = (a * 180) / Pi;
    if (a > 180) {
        while (a > 180) {
            a = a - 360;
        }
    }
    if (a < -180)
    {
        while (a < -180) {
            a = a + 360;
        }
    }
    a = a * Pi / 180;
    z = (long double) myabs(z);
    cout << fixed << setprecision(10);
    cout << "Cmath functions:" << '\n' ;
    cout << sin(a) << '\n' ;
    cout << cos(a) << '\n' ;
    if (a == 0) {
        cout << 0 << endl ;
    }
    else cout << log(z) << '\n' ;
    cout << "My functions:" << '\n' ;
    if (a == 0) {
        cout << 0 << '\n' << 1 << '\n' << 0 << '\n' ;
        return 0 ;
    }
    cout << Sin(a) << '\n' ;
    cout << Cos(a) << '\n' ;
    cout << ln(z) << '\n' ;
    long double sin1 = Sin(a);
    long double cos1 = Cos(a);
    long double ln1 = ln(z);
    if (sin1 <= cos1 && sin1 <= ln1) cout << "Min:" << " sin = " << sin1 << endl;
    else if (cos1 <= sin1 && cos1 <= ln1) cout << "Min:" << " cos = " << cos1 << endl;
    else if (ln1 <= cos1 && ln1 <= sin1) cout << "Min:" << " ln = " << ln1 << endl;
}
//14567289