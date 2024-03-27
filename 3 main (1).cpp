#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

/**
    * @breef  - функция подставляет значение const в уравнение.
    * @param p1-аргумент функции 
    * @param p2-аргумент функции
*/
double distance(const Point& p1, const Point& p2);

/**
    * @breef  - функция подставляет значение const в уравнение.
    * @param C-аргумент функции 
    * @param B-аргумент функции
    * @param A-аргумент функции
*/
double computeAngle(const Point& A, const Point& B, const Point& C);

/**
    * @breef  - точка входа в программу
    * @return возращает 0, если программа выполнена верно, иначе 1
*/

int main() {
    Point A, B, C;

    std::cout << "Введите координаты точки A (x1 y1): ";
    std::cin >> A.x >> A.y;

    std::cout << "Введите координаты точки B (x2 y2): ";
    std::cin >> B.x >> B.y;

    std::cout << "Введите координаты точки C (x3 y3): ";
    std::cin >> C.x >> C.y;

    // Вычисляем угол B
    double angleB = computeAngle(A, B, C);

    // Проверяем, лежат ли точки на одной прямой
    if (angleB == 180.0) {
        std::cout << "Точки A, B и C лежат на одной прямой." << std::endl;
    } else {
        std::cout << "Точки A, B и C не лежат на одной прямой." << std::endl;
        std::cout << "Угол B: " << angleB << " градусов." << std::endl;
    }

    return 0;
}

double distance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

double computeAngle(const Point& A, const Point& B, const Point& C) {
    double a = distance(B, C);
    double b = distance(A, C);
    double c = distance(A, B);
    
    double cosB = (a * a + c * c - b * b) / (2 * a * c);
    return std::acos(cosB) * 180.0 / M_PI; // Переводим радианы в градусы
}
