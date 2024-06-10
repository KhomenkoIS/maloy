#include <iostream>
#include <cmath>
using namespace std;
/**
* @brief функция для вычисления значения переменной a по заданным константам.
* @param x значение переменной x.
* @param y значение переменной y.
* @param z значение переменной z.
* @return результат вычисления переменной a.
*/
double calculatea(double x, double y, double z);
/**
* @brief функция для вычисления значения переменной b по заданным константам.
* @param x значение переменной x.
* @param y значение переменной y.
* @param z значение переменной z.
* @return результат вычисления переменной b.
*/
double calculateb(double x, double y, double z);
/**
* @brief Точка входа в программу.
* @return выводит значение 0 при корректном выполнении программы.
*/
int main()
{
    const double x = 1.426;
    const double y = -1.22;
    const double z = 3.5;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "a = " << calculatea(x, y, z) << endl;
    cout << "b = " << calculateb(x, y, z) << endl;
    return 0;
}
double calculatea(double x, double y, double z)
{
    return (2 * cos(x - (M_PI/6))) / (1/2 + sin(2 * (y)));
}
double calculateb(double x, double y, double z)
{
    return (1 + (pow(z,2)/3 + (pow(z,2)/5)));
}
