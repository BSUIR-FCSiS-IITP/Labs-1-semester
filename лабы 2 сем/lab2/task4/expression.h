#include <iostream>
#include <string>
#include <stack>

class expression
{
public:
    expression();
    static std::pair<long double, std::string> getResult(std::string s, long double a, long double b, long double c, long double d, long double e);
};
