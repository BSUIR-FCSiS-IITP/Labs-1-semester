#include  <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c, x1, y1, x2, y2, x3, y3;

    cout<<"Координаты точки A:" << endl ;
    cin>>x1;
    cin>>y1;

    cout<<"Координаты точки B:" << endl ;
    cin>>x2;
    cin>>y2;

    cout<<"Координаты точки C:" << endl ;
    cin>>x3;
    cin>>y3;

    a = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    b = sqrt(pow((x3-x2),2) + pow((y3-y2),2));
    c = sqrt(pow((x3-x1),2) + pow((y3-y1),2));

    cout << endl << "AB = " << a << endl;
    cout << "BC = " << b << endl;
    cout << "AC = " << c << endl;

    double h1,h2,h3;

    h1 = (fabs((y2-y3)*x1 + (x3-x2)*y1 + (x2*y3 - x3*y2)))/(sqrt(pow((y2 - y3),2) + pow((x3-x2),2)));
    h2 = (fabs((y1-y3)*x2 + (x3-x1)*y2 + (x1*y3 - x3*y1)))/(sqrt(pow((y1 - y3),2) + pow((x3-x1),2)));
    h3 = (fabs((y1-y2)*x3 + (x2-x1)*y3 + (x1*y2 - x2*y1)))/(sqrt(pow((y1 - y2),2) + pow((x2-x1),2)));
    cout<< endl <<"Высота на BC = "<<h1<<endl;
    cout<<"Высота на AC = "<<h2<<endl;
    cout<<"Высота на AB = "<<h3<<endl;

    double m1x,m1y,m2x,m2y,m3x,m3y;
    m1x = (x2+x3)/2;
    m1y = (y2+y3)/2;
    m2x = (x1+x3)/2;
    m2y = (y1+y3)/2;
    m3x = (x1+x2)/2;
    m3y = (y1+y2)/2;

    double med1,med2,med3;

    med1 =fabs(sqrt(pow((m1x - x1),2) + pow((m1y-y1),2))) ;
    med2 = fabs(sqrt(pow((m2x - x2),2) + pow((m2y-y2),2))) ;
    med3 = fabs(sqrt(pow((m3x - x3),2) + pow((m3y-y3),2))) ;
    cout<< endl <<"Медиана AA1 = "<< med1 <<endl;
    cout<<"Медиана BB1 = "<< med2 <<endl;
    cout<<"Медиана CC1 = "<< med3 <<endl;

    double l1, l2, l3;

    l1=(sqrt(a*b*(a+b+c)*(a+b-c))/(a+b));
    l2=(sqrt(c*b*(c+b+a)*(c+b-a))/(c+b));
    l3=(sqrt(a*c*(a+c+b)*(a+c-b))/(a+c));
    cout<<"\n"<<"Биссектриса на BC = "<<l1<<endl;
    cout<<"Биссектриса на AC = "<<l2<<endl;
    cout<<"Биссектриса на AB = "<<l3<<endl;

    double cos1, cos2, cos3, i1, i2, i3, i1_radian, i2_radian, i3_radian;
    const double P = 3.14 ;

    cos1 = (pow(b,2)+pow(c,2) - pow(a,2))/(2*b*c);
    i1_radian=acos(cos1);
    i1 = (i1_radian*180)/P;

    cos2 = (pow(b,2)+pow(a,2) - pow(c,2))/(2*b*a);
    i2_radian=acos(cos2);
    i2 = (i2_radian*180)/P;

    cos3 = (pow(a,2)+pow(c,2) - pow(b,2))/(2*a*c);
    i3_radian=acos(cos3);
    i3 = (i3_radian*180)/P;


    cout<<"\n"<<"Угол 1 в радианах = "  << i1_radian<<" радиан"<<endl;
    cout<<"Угол 2 в радианах = "<<i2_radian<<" радиан"<<endl;
    cout<<"Угол 3 в радианах = "<<i3_radian<<" радиан"<<endl;

	cout<<"\n""Градусная мера угла 1 = "<<int (i1) <<" градусов"<<endl;
	cout<<"Градусная мера угла 2 = "<<int (i2) <<" градусов"<<endl;
    cout<<"Градусная мера угла 3 = "<<int (i3)<<" градусов"<<endl;

    double r_vp, r_op, p_p;
    p_p = (a+b+c)/2;
    r_vp =sqrt(((p_p - a)*(p_p-b)*(p_p-c))/p_p);
    r_op = (a*b*c)/(4*sqrt(p_p*(p_p-a)*(p_p-b)*(p_p-c)));
    cout<<"\n"<<"Радиус вписанной окружности = "<<r_vp<<endl;
    cout<<"\n"<<"Радиус описанной окружности = "<<r_op<<endl;

    double q1,q2;
    q1 = P * pow(r_vp,2);
    q2 = P * pow(r_op,2);
    cout<<"\n"<<"Площадь вписанной окружности = "<<q1<<endl;
    cout<<"\n"<<"Площадь описанной окружности = "<<q2<<endl;

    double per;
    per = 2* p_p;
    cout<< endl <<"Периметр треугольника = "<< per <<endl;

    double s1, s2, s3;

    s1 = p_p * r_vp;
    s2 = (a*b*c)/(4*r_op);
    s3 = 0.5*h3*a;

    cout<< endl <<"Площадь треугольника способом 1 = "<<s1<<endl;
    cout<< endl <<"Площадь треугольника способом 2 = "<<s2<<endl;
    cout<< endl <<"Площадь треугольника способом 3 = "<<s3<<endl;

    return 0;
}