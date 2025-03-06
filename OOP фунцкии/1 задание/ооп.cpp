#include <iostream>
using namespace std;


// Функция для вычисления площади круга
float circarea(float radius) {
    return PI * radius * radius;
}

int main() {
    float radius;

    // Запрос ввода от пользователя
    cout << "Введите радиус круга: ";
    cin >> radius;

    // Вычисление площади и вывод результата
    float area = circarea(radius);
    cout << "Площадь круга: " << area << endl;

    return 0;
}