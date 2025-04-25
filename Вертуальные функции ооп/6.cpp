#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class bMoney {
private:
    long double amount;

    // Конвертация строки в число (удаляет $, , и т.п.)
    long double strToMoney(const string& str) const {
        string clean;
        for (char c : str) {
            if ((c >= '0' && c <= '9') || c == '.')
                clean += c;
        }
        return stold(clean);
    }

public:
    // Конструкторы
    bMoney() : amount(0.0) {}
    bMoney(long double a) : amount(a) {}
    bMoney(string str) { amount = strToMoney(str); }

    // Ввод
    void getMoney() {
        string str;
        cout << "Введите сумму (например, $1,234.56): ";
        getline(cin, str);
        amount = strToMoney(str);
    }

    // Вывод
    void show() const {
        cout << "$" << fixed << setprecision(2) << amount;
    }

    // Арифметика между объектами
    bMoney operator+(const bMoney& m) const { return bMoney(amount + m.amount); }
    bMoney operator-(const bMoney& m) const { return bMoney(amount - m.amount); }
    bMoney operator*(const bMoney& m) const { return bMoney(amount * m.amount); }
    bMoney operator/(const bMoney& m) const {
        if (m.amount == 0.0L) throw runtime_error("Деление на ноль!");
        return bMoney(amount / m.amount);
    }

    // Объект * число, объект / число
    bMoney operator*(long double n) const { return bMoney(amount * n); }
    bMoney operator/(long double n) const {
        if (n == 0.0L) throw runtime_error("Деление на ноль!");
        return bMoney(amount / n);
    }

    // Дружественные функции: число * объект, число / объект
    friend bMoney operator*(long double n, const bMoney& m);
    friend bMoney operator/(long double n, const bMoney& m);
};

// Определения дружественных функций
bMoney operator*(long double n, const bMoney& m) {
    return bMoney(n * m.amount);
}

bMoney operator/(long double n, const bMoney& m) {
    if (m.amount == 0.0L) throw runtime_error("Деление на ноль!");
    return bMoney(n / m.amount);
}
int main() {
    setlocale(LC_ALL, "RU");
    bMoney m1, m2;
    long double num;

    cout << "Первая сумма:\n";
    m1.getMoney();

    cout << "Вторая сумма:\n";
    m2.getMoney();

    cout << "Введите число: ";
    cin >> num;

    cout << "\n--- Результаты операций ---\n";

    cout << "Сложение: ";
    (m1 + m2).show(); cout << endl;

    cout << "Вычитание: ";
    (m1 - m2).show(); cout << endl;

    cout << "Умножение объектов: ";
    (m1 * m2).show(); cout << endl;

    try {
        cout << "Деление объектов: ";
        (m1 / m2).show(); cout << endl;
    }
    catch (runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    cout << "m1 * число: ";
    (m1 * num).show(); cout << endl;

    cout << "m1 / число: ";
    try {
        (m1 / num).show(); cout << endl;
    }
    catch (runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    cout << "Число * m2: ";
    (num * m2).show(); cout << endl;

    cout << "Число / m2: ";
    try {
        (num / m2).show(); cout << endl;
    }
    catch (runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
