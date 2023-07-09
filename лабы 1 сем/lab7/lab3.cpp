#include <iostream>
#include <cstring>
#include <cmath>

long double vod();
long long vod_integer();



bool check(std::string s1, int osnov) {
    for (int i = 0; i < s1.length(); i++) {
        if (!(isdigit(s1[i]) || (s1[i] >= 65 && s1[i] <= 90))) {
            return false;
        }
        int temp;
        if (isalpha(s1[i]))temp = s1[i] - 'A' + 10;
        else temp = s1[i] - '0';
        if (temp >= osnov)
            return false;
    }
    return true;
}
void min_plus(std::string &s1) {
    if (s1[0] == '-')s1[0] = '1';
    else if (s1[0] == '+')s1[0] = '0';
    else s1 = '0' + s1;
}
long long toestes(std::string s, int osnov) {
    long long res = 0;
    long long len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        int temp;
        if (isalpha(s[i]))temp = s[i] - 'A' + 10;
        else temp = s[i] - '0';
        res += temp * powl(osnov, len - i - 1);
    }
    return res;
}

std::string diff_oneznak(std::string s1, std::string s2, int osnov) {
    if (toestes(s1, osnov) < toestes(s2, osnov)) {
        std::string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    s2.insert(0, s1.length() - s2.length(), '0');
    for (int i = s1.length() - 1; i >= 0; i--) {
        int s1_num, s2_num;
        if (isalpha(s1[i])) s1_num = s1[i] - 'A' + 10;
        else s1_num = s1[i] - '0';
        if (isalpha(s2[i])) s2_num = s2[i] - 'A' + 10;
        else s2_num = s2[i] - '0';
        int temp;
        if (s1_num < s2_num) {
            temp = s1_num - s2_num + osnov;
            if (temp > 9)s1[i] = temp + 'A' - 10;
            else s1[i] = temp + '0';
            s1[i - 1]--;
        }
        else {
            temp = s1_num - s2_num;
            if (temp > 9)s1[i] = temp + 'A' - 10;
            else s1[i] = temp + '0';
        }
    }
    return s1;
}
std::string sum_oneznak(std::string s1, std::string s2,int osnov) {
    s1 = '0' + s1;
    s2 = '0' + s2;
    if (s1.length() < s2.length()) {
        std::string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    for (int i = s1.length()-1; i > 0; i--) {
        int s1_num, s2_num;
        if (!isdigit(s1[i])) s1_num = s1[i] - 'A' + 10;
        else s1_num = s1[i] - '0';
        if (!isdigit(s2[i])) s2_num = s2[i] - 'A' + 10;
        else s2_num = s2[i] - '0';
        if (s1_num + s2_num >= osnov) {
            s1[i - 1] += (s1_num + s2_num) / osnov;
            int temp = (s1_num + s2_num) % osnov;
            if (temp > 9) {
                s1[i] = temp + 'A' - 10;
            }
            else s1[i] = temp + '0';
        }
        else {
            int temp = (s1_num + s2_num);
            if (temp > 9) {
                s1[i] = temp + 'A' - 10;
            }
            else s1[i] = temp + '0';
        }
    }
    return s1;
}
std::string sum_all(std::string s1, std::string s2, int osnov) {
    std::string res;
    if (s1[0] == '1' && s2[0] == '1') {
        s1.erase(0, 1);
        s2.erase(0, 1);
        res = '1' + sum_oneznak(s1, s2, osnov);
    }
    else if (s1[0] == '0' && s2[0] == '0') {
        s1.erase(0, 1);
        s2.erase(0, 1);
        res = '0' + sum_oneznak(s1, s2, osnov);
    }
    else if (s1[0] == '0' && s2[0] == '1') {
        char q = '0';
        s1.erase(0, 1);
        s2.erase(0, 1);
        if (toestes(s1, osnov) < toestes(s2, osnov)) {
            q = '1';
        }
        res = q + diff_oneznak(s1, s2, osnov);
        long k = 0;
    }
    else if (s1[0] == '1' && s2[0] == '0') {
        char q = '0';
        s1.erase(0, 1);
        s2.erase(0, 1);
        if (toestes(s1, osnov) > toestes(s2, osnov)) {
            q = '1';
        }
        res = q + diff_oneznak(s2, s1, osnov);
    }
    if (res[0] == '0')
        res.erase(0, 1);
    else if (res[0] == '1')
        res[0] = '-';

    while (res[0] == '0')
        res.erase(0, 1) ;

    return res;
}
char q[1000];

int main() {
    std::string s;
    do {
        int osnov;
        bool summ = true;
        std::string s1, s2, res, diff_sum;
        std::cout << "Введите основание системы счисления(от 2 до 36): \n";
        osnov = vod_integer();
        std::cout << "Введите первое число:\n";
        std::cin >> s1;
        for (int i = 0; i < s1.length(); ++i) {
            if (std::islower(s1[i]))
                s1[i] = toupper(s1[i]) ;
        }
        min_plus(s1);
        while (!check(s1, osnov)) {
            std::cout << "Неверный ввод (попробуйте снова) :\n";
            s1 = "";
            std::cin >> s1;
            min_plus(s1);
        }
        std::cout << "Введите второе число:\n";
        std::cin >> s2;
        for (int i = 0; i < s2.length(); ++i) {
            s2[i] = toupper(s2[i]) ;
        }
        min_plus(s2);
        while (!check(s2, osnov)) {
            std::cout << "Неверный ввод (попробуйте снова) :\n";
            s2 = "";
            std::cin >> s2;
            min_plus(s2);
        }

        std::cout << "Введите '+', если хотите сложить числа, или '-', если хотите вычесть:\n";
        std::cin >> diff_sum;
        while (diff_sum != "+" && diff_sum != "-") {
            std::cout << "Неверный ввод. Введите + или - ";
            diff_sum = "";
            std::cin >> diff_sum;
        }
        if (diff_sum == "+")res = sum_all(s1, s2, osnov);
        else if (diff_sum == "-") {
            if (s2[0] == '0')
                s2[0] = '1';
            else if (s2[0] == '1')
                s2[0] = '0';
            res = sum_all(s1, s2, osnov);
        }
        std::cout << "Результат:\n" << res;
        std::cout << "\nВведите next, чтобы снова ввести числа, или end, чтобы завершить программу:\n";
        std::cin.getline(q, 1000);
        while (strcmp(q, "next") != 0 && strcmp(q, "end") != 0) {
            std::cout << "Введите next или end: \n";
            std::cin.getline(q, 1000);
        }
        if (strcmp(q, "next") != 0)
            break;
    } while (1);
    return 0;
}

char vvod[1000];
long double vod() {
    bool check = true;
    long double res = 0, j = -1, vec10 = 0, zap = 0;
    bool flag = true, flag1 = true, flage = false, next = false;
    int i1;
    bool flagmins, flagmins1;
    while (check) {
        res = 0, j = -1, vec10 = 0, zap = 0, next = false;
        flag = true, flag1 = true, flagmins = false, flagmins1 = false, flage = false;
        i1 = 0;
        char s;
        int i = 0;
        for (long k = 0; k < 1000; k++)
            vvod[k] = '\0';
        vvod[i] = getchar();
        i++;
        while (vvod[i - 1] != '\n') {
            vvod[i] = getchar();
            i++;
        }
        if ((vvod[0] == '-' && vvod[1] == '\n') || (vvod[0] == '.' && vvod[1] == '\n')) {
            std::cout << "Неверный ввод (попробуйте снова) :\n";
            check = true;
            for (long i = 0; i < 1000; i++)vvod[i] = '\0';
            continue;
        }
        if (vvod[0] == '-') {
            i1 = 1;
            flagmins = true;
        }
        for (int i = strlen(vvod) - 2; i >= i1; i--) {
            if (vvod[i] == '\0' || vvod[i] == ' ' || vvod[i] == '\n' || (i == 0 && vvod[i] == '+' && vvod[i + 1] != '\n'))
                continue;
            if (vvod[i] == 'e' && flag) {
                if (i == 0 || vvod[i + 1] == '\n' || (i == 1 && vvod[i - 1] == '-') || !flag1 || vvod[i - 1] == '+')
                    flage = true;
                vec10 = res;
                res = 0;
                j = 0;
                flag = false;
                continue;
            }
            if (vvod[i] == '+' && vvod[i - 1] == 'e')
                continue;
            if (vvod[i] == '.' && flag1) {
                zap = res / powl(10, j);
                res = 0;
                j = 0;
                flag1 = false;
                continue;
            }
            if (vvod[i] == '-' && vvod[i - 1] == 'e') {
                flagmins1 = true;
                continue;
            }
            if (!isdigit(vvod[i])) {
                std::cout << "Неверный ввод (попробуйте снова) : \n";
                check = true;
                for (long i = 0; i < 1000; i++)vvod[i] = '\0';
                next = true;
                break;
            }
            if (j == -1) {
                j = 0;
            }
            res += (vvod[i] - '0') * powl(10, j);
            j++;
            check = false;
        }
        if (next)continue;
        if ((res + zap) * powl(10, vec10) == INFINITY || flage) {
            std::cout << "Неверный ввод (попробуйте снова) : \n";
            check = true;
            for (long i = 0; i < 1000; i++)vvod[i] = '\0';
            continue;
        }
    }	if (flagmins1)vec10 *= -1;
    if (flagmins) return  -((res + zap) * powl(10, vec10));
    return  ((res + zap) * powl(10, vec10));
}
long long vod_integer() {
    long double n = vod();
    while (n != (long long)n || n < 2 || n > 36) {
        std::cout << "Неверный ввод (попробуйте снова) : \n";
        for (long i = 0; i < 1000; i++)vvod[i] = '\0';
        n = vod();
    }
    return (long long)n;
}