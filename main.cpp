﻿#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Расчитывает сумму N членов
 * @param n Число членов последовательности
 * @return Возвращает значение суммы
 */
double SumN(const int n);

/**
 * @brief Вычисляет сумму членов последовательности, по модулю не меньших заданного числа e
 * @param e Число, которое должно быть меньше модуля члена последовательности
 * @return Возвращает значение суммы
 */
double SumE(const double e);

/**
 * @brief Вычисляет рекурентное выражение
 * @param i Переменная i
 * @return 0,5 / (i + 1) / (i + 2)
 */
double Recur(const int i);

/**
 * @brief Функция для проверки ввода n
 * @return Возвращает n, если введено правильно, в противном случае -1
 */
int getValidN();

/**
 * @brief Функция для проверки ввода e
 * @return Возвращает e, если введено правильно, в противном случае -1
 */
double getValidE();

/**
*@brief Точка входа для программы
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = getValidN();
    if (n == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма первых " << n << " членов последовательности: " << SumN(n) << endl;

    double e = getValidE();
    if (e == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма всех членов последовательности, модуль которых не меньше " << e << ": " << SumE(e) << endl;

    return 0;
}

int getValidN()
{
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    if (cin.fail() || n <= 0)
    {
        cout << "Ошибка: n должно быть положительным числом." << endl;
        return -1; // Возвращаем -1 для обработки ошибки
    }

    return n;
}

double getValidE()
{
    double e;
    cout << "Введите значение e: ";
    cin >> e;

    if (e < numeric_limits<double>::epsilon() && e < 1
    {
        cout << "Ошибка: e должно быть положительным числом." << endl;
        return -1; // Возвращаем -1 для обработки ошибки
    }

    return e;
}

double SumN(const int n)
{
    const double a0 = 1;
    double current = a0;
    double sum = current;

    for (int i = 0; i <= n - 1; ++i)
    {
        current *= Recur(i);
        sum += current;
    }

    return sum;
}

double SumE(const double e)
{
    double sum = 0;
    double current = 1;
    int i = 0;

    while (abs(current) >= e)
    {
        sum += current;
        current *= Recur(i++);
    }

    return sum;
}

double Recur(const int i)
{
    return -1/k+1;
}
