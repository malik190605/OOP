// OOP 12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

// Структура для хранения дроби
struct fraction {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

// Функция для нахождения наибольшего общего делителя (НОД)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для сокращения дроби
fraction simplify(fraction f) {
    int divisor = gcd(f.numerator, f.denominator);
    f.numerator /= divisor;
    f.denominator /= divisor;
    if (f.denominator < 0) { // Переносим знак в числитель
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    return f;
}

// Функция сложения дробей
fraction fadd(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return simplify(result);
}

// Функция вычитания дробей
fraction fsub(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return simplify(result);
}

// Функция умножения дробей
fraction fmul(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return simplify(result);
}

// Функция деления дробей
fraction fdiv(fraction f1, fraction f2) {
    fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return simplify(result);
}

// Функция ввода дроби
fraction inputFraction() {
    fraction f;
    cout << "Введите дробь (числитель / знаменатель): ";
    char slash; // Переменная для хранения символа '/'
    cin >> f.numerator >> slash >> f.denominator;
    return f;
}

// Функция вывода дроби
void displayFraction(fraction f) {
    cout << "Результат: " << f.numerator << "/" << f.denominator << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char operation;
    fraction f1, f2, result;

    // Ввод первой дроби
    f1 = inputFraction();

    // Ввод операции
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;

    // Ввод второй дроби
    f2 = inputFraction();

    // Выбор операции
    switch (operation) {
    case '+':
        result = fadd(f1, f2);
        break;
    case '-':
        result = fsub(f1, f2);
        break;
    case '*':
        result = fmul(f1, f2);
        break;
    case '/':
        if (f2.numerator == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return 1;
        }
        result = fdiv(f1, f2);
        break;
    default:
        cout << "Ошибка: неверная операция!" << endl;
        return 1;
    }

    // Вывод результата
    displayFraction(result);

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
