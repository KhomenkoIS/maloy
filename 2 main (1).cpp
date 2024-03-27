#include <iostream>
#include <cmath>

using namespace std;

/**
    * @breef  - функция вычисление расстояния между точками с помощью функции calculateDistance
    * @param x1-аргумент функции 
    * @param y1-аргумент функции
    * @param x2-аргумент функции
    * @param y2-аргумент функции
*/
double calculateDistance(double x1, double y1, double x2, double y2);

/**
    * @breef  - точка входа в программу
    * @return возращает 0, если программа выполнена верно, иначе 1
*/

int main() {
    try {
        // Ввод координат точек от пользователя
        double x1, y1, x2, y2;
        cout << "Введите координату x первой точки: ";
        cin >> x1;
        cout << "Введите координату y первой точки: ";
        cin >> y1;
        cout << "Введите координату x второй точки: ";
        cin >> x2;
        cout << "Введите координату y второй точки: ";
        cin >> y2;

        double distance = calculateDistance(x1, y1, x2, y2);

        // Вывод результата
        cout << "Расстояние между точками (" << x1 << ", " << y1 << ") и (" << x2 << ", " << y2 << ") равно " << distance << " единиц." << endl;
    } catch (invalid_argument&) {
        cout << "Ошибка: введите числовые значения координат." << endl;
    }

    return 0;
}

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
