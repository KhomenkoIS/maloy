#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;
/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};
/**
 * @brief считывает значение типа int
 * @return считанное значение
 */
int getValue();
/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int** arr, int const rows, int const cols, int const min, int const max);
/**
 * @brief Выводит массив на экран
 * @param arr - массив
 * @param n - кол-во строк
 * @param m - кол-во столбцов
 */
void printArray(int** arr, int const n, int const m);
/**
 * @brief заменяет минимальные абсолютные значения на нули.
 * @param arr - массив
 * @param n - размер массива
 * @param m - кол-во столбцов
 */
void replaceMinAbsolute(int** arr, int const n, int const m);
/**
 * @brief заменяет минимальные абсолютные значения на нули.
 * @param arr - массив
 * @param arr3 - массив, полученный в ходе работы функции
 * @param n - размер массива
 * @param m - кол-во столбцов
 */
void deleteColumns(int** arr, int** arr3, int const rows, int const cols);
/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max);
/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(int const min, int const max);
/**
 * @brief проверяет правильность введенного размера массива.
 * @param n - размер массива
 */
void checkN(int const n);
/**
 * @brief проверяет диапазон
 * @param arr - массив
 * @param rows - кол-во строк
 */
void delArray(int** arr, int const rows);
/**
 * @brief возвращает количество столбцов удовлетворяющих условию.
 * @param arr - массив
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - кол-во столбцов удовлетворяющих условию
 */
int getNumberOfCols(int** arr, int const rows, int const cols);
/**
 * @brief копирует массив.
 * @param arr - массив
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - скопированный массив
 */
int** copyArray(int** arr, int const rows, int const cols);
/**
 * @brief создает новый массив.
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - новый массив
 */
int** getNewArray(int const rows, int const cols);
/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    cout << "Enter number of rows in array: ";
    int rows = getValue();
    checkN(rows);
    cout << "Enter number of columns in array: ";
    int cols = getValue();
    checkN(cols);
    int** arr = getNewArray(rows, cols);
    cout << "Enter min and max values of range: " << endl;
    int minValue = getValue();
    int maxValue = getValue();
    checkRange(minValue, maxValue);
    cout << "Enter your choice to fill array: " << endl
        << RANDOM << " to fill randomly" << endl
        << MANUALLY << " to fill manually" << endl;
    int choice = getValue();
    switch ((enum SELECT)choice)
    {
    case RANDOM:
        fillArrayRandom(arr, rows, cols, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, rows, cols, minValue, maxValue);
        break;
    default:
        cout << "Your choice is wrong" << endl;
        return 1;
    }

    cout << "Original array:" << endl;
    printArray(arr, rows, cols);
    int** arr2 = copyArray(arr, rows, cols);
    replaceMinAbsolute(arr2, rows, cols);

    cout << "Array after replacing min absolute elements with zeros:" << endl;
    printArray(arr2, rows, cols);
    delArray(arr2, rows);

    int newcols = cols - getNumberOfCols(arr, rows, cols);
    int** arr3 = getNewArray(rows, newcols);
    deleteColumns(arr, arr3, rows, cols);//Копируем в arr3 если удовлетворяет условию 

    cout << "Array after deleting columns where first element is greater than last element:" << endl;
    printArray(arr3, rows, newcols);
    delArray(arr3, rows);


    delArray(arr, rows);
    return 0;
}
int getValue()
{
    int value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Incorrect input";
        abort();
    }
    return value;
}
void fillArray(int** arr, int const rows, int const cols, int const min, int const max)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "Enter value for element [" << i << "][" << j << "]: ";
            arr[i][j] = getValue();
        }
    }
}
void printArray(int** arr, int const n, int const m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << setw(4);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void replaceMinAbsolute(int** arr, int const n, int const m) {
    for (size_t j = 0; j < m; j++) {
        int minIndex = 0;
        for (size_t i = 1; i < n; i++) {
            if (abs(arr[i][j]) < abs(arr[minIndex][j])) {
                minIndex = i;
            }
        }
        arr[minIndex][j] = 0;
    }
}

void deleteColumns(int** arr, int** arr3, int const rows, int const cols) {
    int newCols = 0;
    for (size_t j = 0; j < cols; j++) {
        if (arr[0][j] <= arr[rows - 1][j]) {
            for (size_t i = 0; i < rows; i++) {
                arr3[i][newCols] = arr[i][j];
            }
            newCols++;
        }
    }
}
void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max)
{
    srand(time(0));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % (max - min) + min;
        }
    }
}
void checkRange(int const min, int const max)
{
    if (min >= max)
    {
        cout << "Wrong range entered: " << endl;
        abort();
    }
}
void checkN(int n)
{
    if (n <= 0)
    {
        cout << "Wrong size of array" << endl;
        abort();
    }
}

int** getNewArray(int const rows, int const cols)
{
    int** arr = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    return arr;
}

int** copyArray(int** arr, int const rows, int const cols)
{
    int** newArr = getNewArray(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            newArr[i][j] = arr[i][j];
        }
    }
    return newArr;
}

void delArray(int** arr, int const rows)
{
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
int getNumberOfCols(int** arr, int const rows, int const cols)
{
    int count = 0;
    for (size_t j = 0; j < cols; j++)
    {
        if (arr[0][j] > arr[rows - 1][j])
        {
            count++;
        }
    }
    return count;
}