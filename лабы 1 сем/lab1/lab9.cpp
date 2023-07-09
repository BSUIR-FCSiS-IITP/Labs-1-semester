#include <iostream>
#include <iomanip>
#include <math.h>
int main()
{
    long long int a, b;
    std::cin >> a;
    std::cin >> b;
    a = a ^ b;
    b = b ^ a;
    std::cout << "b = " << b << "\n";
    a = a ^ b;
    std::cout << "a = " << a << "\n";
    return 0;
}