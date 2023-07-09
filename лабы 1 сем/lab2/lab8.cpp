#include <iostream>
#include <cmath>
using namespace std ;

int main() {
    long double a, b, c, x1, x2, x3, x4, d, D, t, t1, t2, p, q, tr, y1, y2, y3, f, alpha, beta;
    bool log=false;
    int num ;
    cout << "Введите номер варианта(от 1 до 3): " << '\n' ;
    cin >> num ;
    switch (num) {
        case 1:
            cout << "ax^4 + bx^2 + c = 0" << '\n' ;
            cout << "Введите a, b, c: " ;
            cin >> a >> b >> c ;
            if (a == 0 && b == 0 && c == 0) {
                std::cout << "Верно всегда" ;
                exit(0) ;
            }
            else if (a == 0 && b == 0 && c != 0) {
                std::cout << "Не верно" ;
                exit(0) ;
            }
            if ((c == 0 && a > 0 && b < 0 && b == fabs(a)) || (c == 0 && b > 0 && a < 0 && a == fabs(b))) {
                std::cout << "x=0 x=-1 x=1" ;
                exit(0) ;
            }
            else if (a > 0 && b == 0 && c > 0) {
                std::cout << "Не верно" ;
                exit(0) ;
            }
            else if ((a != 0 && b == 0 && c == 0) || (a == 0 && b != 0 && c == 0)) {
                std::cout << "x=0" ;
                exit(0) ;
            }

            if (a==0) {
                if (b!=0) {
                    if (c==0) {cout<<"x=0";}
                    else {
                        if (c/b<0){
                            x1=sqrt(-(c/b));
                            x2=-sqrt(-(c/b));
                            cout<<"x1="<<x1<<"; x2="<<x2;
                        }
                        else {cout<<"Нет решений";}
                    }
                }
                else {
                    if (c!=0) {cout<<"Нет решений";}
                    else {cout<<"x любое";}

                }
            }
            else{
                D = (b * b - 4 * a * c);
                if (D<0) {cout<<"Нет решений";}
                else {
                    d=sqrt(D);
                    t1=( - b + d )/2.0 / a;
                    t2=( - b - d )/2.0 / a;
                    if (t1>0){
                        x1=sqrtl(t1);
                        x2=-sqrtl(t1);
                        cout<<"x1="<<x1<<"; x2="<<x2<<"; ";
                        log = true;
                    }
                    if (t2>0){
                        x3=sqrt(t2);
                        x4=-sqrtl(t2);
                        if (log == true){cout<<"x3="<<x3<<"; x4="<<x4<<";";}
                        if (log == false){cout<<"x1="<<x3<<"; x2="<<x4<<";";}
                    }
                }
            }
            break ;
        case 2:
            cout << "ax^4 + bx^3 + cx^2 + bx + a = 0" <<endl;
            cout << "Введите a, b, c: " ;
            cin >> a >> b >> c ;
            if (std::cin.fail()) {
                std::cout << "Incorrect input" << "\n";
                return 0;
            }
            if (a == 0) {
                if (c == 0 && b == 0) {
                    std::cout << "x любое";
                    return 0;
                }
                else if (b == 0) {
                    std::cout << "x=0" ;
                    return 0;
                }
                else if (c * c - 4 * b * b > 0) {
                    std::cout << "x=0" << ' ' << "x=" << (-c - sqrt(c * c - 4 * b * b)) / (2 * b) << ' ' << "x=" << (-c + sqrt(c * c - 4 * b * b)) / (2 * b);
                    return 0;
                }
                else if (c * c - 4 * b * b == 0) {
                    std::cout << "x=0" << ' ' << "x=" << -c / 2;
                    return 0;
                }
                else {
                    std::cout << 0;
                    return 0;
                }
            }

            if (b * b - 4 * a * (c - 2 * a) > 0) {
                t1 = (-b + sqrt(b * b - 4 * a * (c - 2 * a))) / (2 * a);
                t2 = (-b - sqrt(b * b - 4 * a * (c - 2 * a))) / (2 * a);
                if (t1 * t1 - 4 < 0 && t2 * t2 - 4 < 0) {
                    std::cout << "Нет решений";
                }
                if (t1 * t1 - 4 == 0) {
                    std::cout << "x=" << t1 / 2 << ' ';
                }
                else if (t1 * t1 - 4 > 0) {
                    std::cout << "x=" << (t1 + sqrt(t1 * t1 - 4)) / 2 << ' ' << "x=" << (t1 - sqrt(t1 * t1 - 4)) / 2 << ' ';
                }
                if (t2 * t2 - 4 == 0) {
                    std::cout << "x=" << t2 / 2 << ' ';
                }
                else if (t2 * t2 - 4 > 0) {
                    std::cout << "x=" << (t2 + sqrt(t2 * t2 - 4)) / 2 << ' ' << "x=" << (t2 - sqrt(t2 * t2 - 4)) / 2 << ' ';
                }


            }
            else if (b * b - 4 * a * (c - 2 * a) == 0) {
                t1 = -b / (2 * a);
                if (t1 * t1 - 4 < 0) {
                    std::cout << "Нет решений";
                }
                else if (t1 * t1 - 4 == 0) {
                    std::cout << "x=" << t1 / 2;
                }
                else {
                    std::cout << "x=" << (t1 + sqrt(t1 * t1 - 4)) / 2 << ' ' << "x=" << (t1 - sqrt(t1 * t1 - 4)) / 2;
                }

            }
            else {
                std::cout << "Нет решений";
            }
            break;
        case 3:
            cout << "x^3 + px + q = 0" << '\n' ;
            cout << "Введитe p, q: " ;
            cin >> p >> q ;
            if (p == 0 && q == 0 ) {
                cout << 0 ;
                exit(0) ;
            }
            tr = pow(q / 2, 2) + pow(p / 3, 3) ;
            if (tr <= 0) {
                if (q < 0) {
                    f = atan(sqrt(-tr) / (-q / 2)) ;
                }
                else if (q > 0) {
                    f = atan(sqrt(-tr) / (-q / 2)) + acos(-1) ;
                }
                else if (q == 0) f = acos(-1) / 2 ;

                y1 = 2 * sqrt(-p / 3) * cos(f/3) ;
                y2 = 2 * sqrt(-p / 3) * cos(f/3 + 2 * acos(-1) / 3) ;
                y3 = 2 * sqrt(-p / 3) * cos(f/3 + 4 * acos(-1) / 3) ;
                if (q == 0) y3 = 0 ;
                cout << y1 << '\n' << y2 << '\n' << y3 ;
            }
            else {
                alpha = cbrt(-q / 2 + sqrt(tr)) ;
                beta = cbrt(-q / 2 - sqrt(tr)) ;
                y1 = alpha + beta ;
                cout << y1 ;
            }
    }
}