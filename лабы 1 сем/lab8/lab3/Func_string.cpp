#include "Func_string.h"
bool equal_string(char s1[], char s2[]) {
    for (int i = 0; i < 100; i++) {
        if (s1[i] != s2[i])return false;
    }
    return true;
}
void input_string(char str[])
{
    std::string ans = "";

    while (1)
    {
        ans.clear();
        getline(std::cin, ans);
        if (ans.length() >= 100)std::cerr << "Попробуйте снова\n";
        else if (ans.empty())continue;
        else break;
    }
    for (int i = 0; i < ans.length(); i++)str[i] = ans[i];
    str[ans.length()] = '\0';

}