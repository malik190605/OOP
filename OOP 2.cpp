#include <iostream>
using namespace std;
#define PI 3.14159

// Функция для вычисления площади круга
float circarea(float radius) {
    return PI * radius * radius;
}

// Функция для возведения числа в степень
double power(double n, int p = 2) {
    double result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    float radius;

    // Запрос ввода от пользователя
    cout << "Введите радиус круга: ";
    cin >> radius;

    // Вычисление площади и вывод результата
    float area = circarea(radius);
    cout << "Площадь круга: " << area << endl;

    // Запрос ввода для возведения в степень
    double base;
    int exponent;
    cout << "Введите число для возведения в степень: ";
    cin >> base;
    cout << "Введите показатель степени (по умолчанию 2): ";
    cin >> exponent;

    // Вычисление и вывод результата
    cout << base << " в степени " << exponent << " равно " << power(base, exponent) << endl;

    return 0;
}