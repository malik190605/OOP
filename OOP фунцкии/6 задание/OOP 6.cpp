// OOP 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
using namespace std;
#define PI 3.14159

// Структура для хранения расстояния
struct Distance {
    int feet;
    float inches;
};

// Структура для хранения времени
struct Time {
    int hours;
    int minutes;
    int seconds;
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

// Функция преобразования времени в секунды
long time_to_secs(Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

// Функция преобразования секунд в структуру Time
Time secs_to_time(long total_seconds) {
    Time t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    t.seconds = total_seconds % 60;
    return t;
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

    // Циклический ввод времени
    Time t;
    char choice;
    do {
        cout << "Введите часы, минуты и секунды: ";
        cin >> t.hours >> t.minutes >> t.seconds;
        long total_seconds = time_to_secs(t);
        cout << "Общее количество секунд: " << total_seconds << endl;
        Time converted_time = secs_to_time(total_seconds);
        cout << "Обратное преобразование: " << converted_time.hours << " часов, "
            << converted_time.minutes << " минут, " << converted_time.seconds << " секунд" << endl;
        cout << "Хотите ввести еще одно время? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
