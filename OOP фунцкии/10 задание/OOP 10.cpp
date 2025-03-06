// OOP 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction; // 'N', 'S', 'E', 'W'

public:
    // Конструктор с параметрами
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}

    // Конструктор по умолчанию
    Angle() : degrees(0), minutes(0.0), direction('N') {}

    // Метод для ввода координаты
    void input() {
        cout << "Введите градусы: ";
        cin >> degrees;
        cout << "Введите минуты: ";
        cin >> minutes;
        cout << "Введите направление (N, S, E, W): ";
        cin >> direction;
    }

    // Метод для вывода координаты
    void display() const {
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

struct Time {
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time secs_to_time(long total_seconds) {
    Time t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    t.seconds = total_seconds % 60;
    return t;
}

void swap(Time& t1, Time& t2) {
    Time temp = t1;
    t1 = t2;
    t2 = temp;
}

double power(double base, int exponent) {
    return pow(base, exponent);
}

char power(char base, int exponent) {
    return static_cast<char>(pow(static_cast<int>(base), exponent));
}

int power(int base, int exponent) {
    return static_cast<int>(pow(base, exponent));
}

long power(long base, int exponent) {
    return static_cast<long>(pow(base, exponent));
}

float power(float base, int exponent) {
    return static_cast<float>(pow(base, exponent));
}

// Функция с глобальной переменной
int call_count_global = 0;
void count_calls_global() {
    call_count_global++;
    cout << "Функция вызвана " << call_count_global << " раз(а) (глобальная переменная)" << endl;
}

// Функция со статической локальной переменной
void count_calls_static() {
    static int call_count_static = 0;
    call_count_static++;
    cout << "Функция вызвана " << call_count_static << " раз(а) (статическая переменная)" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объекта с помощью конструктора
    Angle tahiti(149, 34.8, 'W');
    Angle point;

    cout << "Координаты бухты Папити: ";
    tahiti.display();

    // Цикл ввода координат от пользователя
    char choice;
    do {
        cout << "\nВведите координаты точки:" << endl;
        point.input();
        cout << "Вы ввели: ";
        point.display();

        cout << "Хотите ввести другую координату? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Тестирование перегруженных функций power()
    cout << "\nТестирование функции power():" << endl;
    cout << "power(2.0, 3) = " << power(2.0, 3) << endl;
    cout << "power('A', 2) = " << power('A', 2) << endl;
    cout << "power(3, 3) = " << power(3, 3) << endl;
    cout << "power(5L, 2) = " << power(5L, 2) << endl;
    cout << "power(1.5f, 2) = " << power(1.5f, 2) << endl;

    // Тестирование функции swap() для Time
    Time t1 = { 2, 30, 45 };
    Time t2 = { 5, 15, 20 };
    cout << "\nДо swap: t1 = " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << ", t2 = " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;
    swap(t1, t2);
    cout << "После swap: t1 = " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << ", t2 = " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;

    // Тестирование подсчёта вызовов функции
    cout << "\nТестирование подсчёта вызовов функции:" << endl;
    for (int i = 0; i < 10; i++) {
        count_calls_global();
    }
    for (int i = 0; i < 10; i++) {
        count_calls_static();
    }

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
