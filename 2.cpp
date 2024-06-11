#include <iostream>
#include <stdlib.h>
using namespace std;
/**
*@breef Считывает значение с клавиатуры с проверкой ввода
*@return Введённое значение
*/
double getValue();
/**
 *@breef Проверяет число на то, чтобы оно не было равно нулю или меньше нуля
 *@return Введённое значение
*/
void checkValue(const double value);
/**
 * @breef Считает площадь поверхности куба
 * @param a - длина ребра куба
 * @return Площаль поверхности куба
*/
double cubeSurface(const double a);
/**
 * @breef Считает объём куба
 * @param a - длина ребра куба
 * @return Объём куба
*/
double cubeVolume(const double a);
/**
 * @breef Главная функция программы
 * @return Возвращает 0, если функция выполнена верно, иначе 1
*/
int main()
{
    cout <<"Enter the cube edge length =" << endl;
    double a = getValue();
    checkValue(a);
    cout <<"Area of a cube face =" << a * a << endl;
    cout <<"Surace area of a cube =" << cubeSurface(a) << endl;
    cout <<"Volume  of a cube =" << cubeVolume(a) << endl;
}
double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout <<"incorrect value" << endl;
        abort();
    }
    return value;
}
void checkValue(double value)
{
    if (value <=0)
    {
        abort();
    }
}
double cubeSurface(double a)
{
    return 6 * a * a;
}
double cubeVolume(double a)
{
    return a * a *a;
}