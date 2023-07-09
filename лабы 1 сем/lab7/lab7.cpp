#include<iostream>

bool check0(int* arr) {
    int size = 170 - arr[0];
    int a[170];
    for (int i = 1; i < 170; ++i)
        a[i] = arr[i];
    for (size; size > 0; --size) {
        for (int i = arr[0]; i < 170; ++i) {
            a[i + 1] += (a[i] % 2)*10;
            a[i] /= 2;
        }
    }
    if (a[169] % 2 == 0)
        return true;
    else
        return false;
}

void convert1(int **arr, int t, int k) {
    arr[t][k - 1] = 1;
    arr[t][k] = 0;
    arr[t][0]--;
}

void convert2(int **arr, int t, int k) {
    arr[t][k - 1] = 1;
    arr[t][0]--;
}

int main() {
    auto** arr = new int* [10100];
    int n;
    for (int i = 0; i < 10100; ++i)
        arr[i] = new int[170];
    std::cin >> n;
    if (n == 1) {
        std::cout << 1 ;
        exit(0) ;
    }
    arr[0][169] = 1;
    arr[0][0] = 169;
    int t = 1;
    int x = 0, y = 0;
    while (t <= n) {
        for (int i = x; i <= y; ++i) {
            for (int j = 0; j < 170; ++j)
                arr[t][j] = arr[i][j];
            int k = arr[t][0];
            convert1(arr, t, k) ;
            if (check0(arr[i]))
                ++t;
        }
        for (int i = x; i <= y; ++i) {
            for (int j = 0; j < 170; ++j)
                arr[t][j] = arr[i][j];
            int k = arr[t][0];
            convert2(arr, t, k) ;
            if (check0(arr[i]))
                ++t;
        }
        x = y + 1;
        y = t - 1;
    }
    std::string s ;
    for (int i =arr[n - 1][0]; i < 170; ++i)
        s.push_back(arr[n - 1][i] + '0');
    std::cout << s ;
    for (int i = 0; i < 10100; ++i) {
        delete arr[i] ;
    }
    delete [] arr ;
}