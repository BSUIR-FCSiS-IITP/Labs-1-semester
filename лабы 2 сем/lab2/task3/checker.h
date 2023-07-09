#ifndef CHECKER_H
#define CHECKER_H
#include <string>
#include <stack>

class checker
{
public:
    checker();
    static std::pair<std::string, std::pair<int, int>> check(std::string s);
};

#endif // CHECKER_H
