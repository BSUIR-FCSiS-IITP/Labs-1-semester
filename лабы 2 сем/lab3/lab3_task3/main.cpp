#include <iostream>
#include <regex>
#include "vector.h"

int main()
{
    int n;
    std::cout << "Введите количество элементов для добавления:\n";
    std::cin >> n;
    Vector<int> a;
    a.reserve(n);
    std::cout << "Введите элементы:\n";
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        a.push_back(t);
    }
    Vector<Vector<int>> res;
    Vector<int> buffer;
    int j = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (j < 3)
        {
            buffer.push_back(a[i]);
            ++j;
        }
        else
        {
            res.push_back(buffer);
            buffer.clear();
            j = 0;
            --i;
        }
    }
    if (!buffer.empty())
        res.push_back(buffer);
    for (int i = 0; i < res.size(); ++i) {
        for (int k = 1; k < res[i].size(); ++k) {
            for (int l = 0; l < res[i].size() - 1; ++l) {
                if (res[i][l] > res[i][l + 1]) {
                    int buff = res[i][l];
                    res[i][l] = res[i][l + 1];
                    res[i][l + 1] = buff;
                }
            }
        }
    }
    Vector<int> q;
    q.reserve(res.size());
    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i].size() == 3)
            q.push_back(res[i][1]);
        else if (res[i].size() == 2)
            q.push_back((res[i][0] + res[i][1]) / 2);
        else
            q.push_back(res[i][0]);
    }
    for (auto it: q) {
        std::cout << it << '\n';
    }
}