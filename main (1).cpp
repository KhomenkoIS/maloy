#include <iostream>
#include <cmath>
using namespace std;
double getA(const double x, const double y, const double z);

/**
    * @breef  - функция подставляет значение const в уравнение.
    * @param x-аргумент функции 
    * @param y-аргумент функции
    * @param z-аргумент функции
*/

double getB(const double x, const double y, const double z);

/**
    * @breef  - точка входа в программу
    * @return возращает 0, если программа выполнена верно, иначе 1
*/

int main()
{
    const double x = 0.61, y = 3.4, z = 16.5;
    double a;
    cout << "x="<< x <<"  y="<< y <<"  z="<< z <<endl;
    cout << "a="<< getA(x, y, z) <<"  b="<< getB(x, y, z) << endl;
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (pow(x,3)*(tan(x+y)*tan(x+y)))+(z/sqrt(x+y));
}

double getB(const double x, const double y, const double z)
{
    return (y*pow(x,2)-z)/(exp(z*x)-1);
}