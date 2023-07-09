#include "checker.h"

checker::checker() {}

std::pair<std::string, std::pair<int, int>> checker::check(std::string s)
{
    int count1 = 0, count2 = 0;
    std::stack<char> q;
    bool out = false;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != '\n')
        {
            ++count2;
        }
        else
        {
            ++count1;
            count2 = 0;
        }
        if (s[i] == '(')
            q.push('(');
        else if (s[i] == '{')
            q.push('{');
        else if (s[i] == '[')
            q.push('[');


        if (s[i] == ')')
        {
            if (q.empty() || q.top() != '(')
            {
                out = true;
                break;
            }
            else
            {
                q.pop();
            }
        }
        else if (s[i] == '}')
        {
            if (q.empty() || q.top() != '{')
            {
                out = true;
                break;
            }
            else
            {
                q.pop();
            }
        }
        else if (s[i] == ']')
        {
            if (q.empty() || q.top() != '[')
            {
                out = true;
                break;
            } else {
                q.pop();
            }
        }
    }
    if (out)
        return std::make_pair("Failed", std::make_pair(count1, count2));
    else if (q.empty())
        return std::make_pair("Success", std::make_pair(count1, count2));
    else
        return std::make_pair("Failed", std::make_pair(count1, count2));
}
