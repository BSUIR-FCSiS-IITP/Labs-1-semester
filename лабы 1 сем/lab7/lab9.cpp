#include <iostream>

void check(std::string a[240],int n,int i) {
    for (int i_n = 0; i_n < 5; i_n++) {
        if (a[n][i_n] == '1' && a[i][i_n] != '1') {
            a[i] = "ok";
        }
        if ((a[n][i_n] == '0' || a[n][i_n] == '2') && a[i][i_n] == '1') {
            a[i] = "ok";
        }
    }
}
void check1(std::string a[240], int n, int i) {
    for (int i_n = 0; i_n < 5; i_n++) {
        if (a[n][i_n] == '2' && a[i][i_n] != '2') {
            a[i] = "ok";
        }
        if ((a[n][i_n] == '0' || a[n][i_n] == '1') && a[i][i_n] == '2') {
            a[i] = "ok";
        }
    }
}
std::string triple(int a) {
    std::string res;
    while (a != 0) {
        res = std::to_string(a % 3) + res;
        a /= 3;
    }
    while (res.length() != 5) {
        res = '0' + res;
    }
    return res;
}

int main() {
    int n;
    std::string a[240];
    for (int i = 0; i < 240; i++) {
        a[i] = triple(i);
    }
    std::cout << "Введите номер отравленной бочки:\n" ;
    std::cin >> n ;
    n--;
    for (int i = 0; i < 240; i++) {
        check(a, n, i);
    }
    for (int i = 0; i < 240; i++) {
        if (a[i] == "ok")continue;
        check1(a, n, i);
    }

    for (int i = 0; i < 240; i++) {
        if (a[i] != "ok")
            std::cout << "Отравленная бочка:\n" << i + 1;
    }
}