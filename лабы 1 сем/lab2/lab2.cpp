#include <iostream>

int main() {
    double x, y, z ;
    std::cin >> x >> y >> z ;
    if (x + y > z && y + z > x && x + z > y)  std::cout << "YES" ;
    else std::cout << "NO" ;
}
