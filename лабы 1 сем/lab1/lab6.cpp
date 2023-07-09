#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a;
    cout<<"Введите номер варианта:";
    cin>>a;

    if (a==1)
    {
        double s, d, x, a, b;

        cout << "Введите x = ";
        cin >> x;

        cout << "Введите d = ";
        cin >> d;

        b = x + d;
        a = (d * x) / b;
        s = (pow(a, 2) + b * cos(x)) / (pow(d, 3) + (a + d - b));
        cout << s << endl;

    }

    if (a==2)
    {
        double A,D,C,E,K,x,p,B,Y;
        cout<<"K = ";
        cin>>K;
        cout<<"x = ";
        cin>>x;
        cout<<"p = ";
        cin>>p;
        cout<<"D = ";
        cin>>D;
        cout<<"C = ";
        cin>>C;
        B = exp(K);
        A =  x+ sin(p);
        Y = 1+ (pow(K,2))/2*A*B - B + D*C;
        cout<<"Y = "<<Y<<endl;


    }
    if (a==3)
    {
        double p,n, C, B, x,Q, K, D;
        cout<<"p=";
        cin>>p;
        cout<<"n=";
        cin>>n;
        cout<<"x=";
        cin>>x;
        cout<<"K=";
        cin>>K;
        cout<<"D=";
        cin>>D;
        C = p - n;
        B = cos(x);
        Q = pow(B,2)/(K*D) + B*pow(C,3);
        cout<< "Q="<< Q<<endl;

    }
    if (a==4)
    {
        double x,y,z, K, C, D, B,A, T;
        cout<<"x=";
        cin>>x;
        cout<<"y=";
        cin>>y;
        cout<<"z=";
        cin>>z;
        cout<<"K=";
        cin>>K;
        cout<<"D=";
        cin>>D;
        cout<<"C=";
        cin>>C;
        B = sqrt(z);
        A = x-y;
        T = cos(x) + pow(A,2)/(K-C*D) - B;
        cout<<"T = "<<T<<endl;

    }
    if (a==5)
    {
        double x,n,m, K, D, A, Y;
        cout<<"x=";
        cin>>x;
        cout<<"n=";
        cin>>n;
        cout<<"m=";
        cin>>m;
        cout<<"K=";
        cin>>K;
        D = tan(x);
        A = fabs(n+m);
        Y = 1.29 + K/A + pow(D,2);
        cout<< "Y = "<<Y<<endl;
    }
    if (a==6)
    {
        double C, A, x, y, K, S, D;
        cout<<"C = ";
        cin>>C;
        cout<<"A = ";
        cin>>A;
        cout<<"K = ";
        cin>>K;
        cout<<"x = ";
        cin>>x;
        cout<<"y = ";
        cin>>y;
        D = fabs(C-A);
        A = x+y;
        S = 10.1 + A/C + D/pow(A,2);
        cout<<"C = "<<C<<endl;

    }
    if (a==7)
    {
        double A, x, p, B, h, Y, K, C, D;
        cout<<"h = ";
        cin>>h;
        cout<<"x = ";
        cin>>x;
        cout<<"p = ";
        cin>>p;
        cout<<"C = ";
        cin>>C;
        cout<<"K = ";
        cin>>K;
        cout<<"D = ";
        cin>>D;
        B = log(h);
        A = x-p;
        Y = 0.78*B + pow(A,3)/(K*C*D);
        cout<<"Y = "<<Y<<endl;

    }
    if (a==8)
    {
        double A, x, B, d, Y, C, K;
        cout<<"x = ";
        cin>>x;
        cout<<"d = ";
        cin>>d;
        cout<<"C = ";
        cin>>C;
        cout<<"K = ";
        cin>>K;
        B = x + exp(d);
        A = log10(x);
        Y = (A+B) - pow(C,2)/K;
        cout<<"Y = "<<Y<<endl;


    }
    if (a==9)
    {
        double A, B, x, p, Y, K, C, D,z;
        cout<<"x = ";
        cin>>x;
        cout<<"p = ";
        cin>>p;
        cout<<"z = ";
        cin>>z;
        cout<<"K = ";
        cin>>K;
        cout<<"C = ";
        cin>>C;
        cout<<"D = ";
        cin>>D;
        B = fabs(p-x);
        A = sin(x)-z;
        Y = pow(A+B,2) - K/(C*D);
        cout<<"Y = "<<Y<<endl;

    }
    if (a==10)
    {
        double x, z, k, A, B, C, D, Y;
        cout<<"x = ";
        cin>>x;
        cout<<"z = ";
        cin>>z;
        cout<<"k = ";
        cin>>k;
        cout<<"D = ";
        cin>>D;
        cout<<"C = ";
        cin>>C;
        B = sqrt(z);
        A = log(x) - k;
        Y = pow(D,2)+ pow(C,2)/(0.75*A) + B;
        cout<<"Y = "<<Y<<endl;

    }
    return 0;
}