#include <iostream>
#include <locale>
using namespace std;
#define PI 3.14159

// Структура для хранения расстояния
struct Distance {
    int feet;
    float inches;
};

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

// Функция, обнуляющая меньшее из двух чисел
void zeroSmaller(int& a, int& b) {
    if (a < b) {
        a = 0;
    }
    else {
        b = 0;
    }
}

// Функция, возвращающая наибольшее из двух значений Distance
Distance maxDistance(Distance d1, Distance d2) {
    float len1 = d1.feet + d1.inches / 12.0;
    float len2 = d2.feet + d2.inches / 12.0;
    return (len1 > len2) ? d1 : d2;
}

// Функция преобразования часов, минут и секунд в секунды
long hms_to_secs(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    setlocale(LC_ALL, "Russian");

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

    // Проверка функции zeroSmaller
    int num1, num2;
    cout << "Введите два целых числа: ";
    cin >> num1 >> num2;
    zeroSmaller(num1, num2);
    cout << "После применения zeroSmaller: " << num1 << " " << num2 << endl;

    // Проверка функции maxDistance
    Distance d1, d2;
    cout << "Введите первое расстояние (футы и дюймы): ";
    cin >> d1.feet >> d1.inches;
    cout << "Введите второе расстояние (футы и дюймы): ";
    cin >> d2.feet >> d2.inches;
    Distance maxD = maxDistance(d1, d2);
    cout << "Наибольшее расстояние: " << maxD.feet << " футов " << maxD.inches << " дюймов" << endl;

    // Циклический ввод часов, минут и секунд
    int hours, minutes, seconds;
    char choice;
    do {
        cout << "Введите часы, минуты и секунды: ";
        cin >> hours >> minutes >> seconds;
        cout << "Общее количество секунд: " << hms_to_secs(hours, minutes, seconds) << endl;
        cout << "Хотите ввести еще одно время? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}