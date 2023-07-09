#include <iostream>

int main() {
	double x, y ;
	std::cin >> x >> y ;
	bool m = x >= y ;
	if (m) std::cout << x ;
	else std::cout << y ;
}