#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   // Числитель
    int denominator; // Знаменатель

public:
    // Конструктор
    Fraction() : numerator(0), denominator(1) {}

    // Метод для ввода дроби
    void inputData() {
        char slash;
        cout << "Введите дробь в формате a/b: ";
        cin >> numerator >> slash >> denominator;
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть нулем! Установлено значение 1." << endl;
            denominator = 1;
        }
    }

    // Метод для вывода дроби
    void displayData() const {
        cout << numerator << "/" << denominator;
    }

    // Метод для сложения двух дробей
    Fraction add(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    char choice;
    do {
        Fraction frac1, frac2, result;

        cout << "Введите первую дробь:\n";
        frac1.inputData();

        cout << "Введите вторую дробь:\n";
        frac2.inputData();

        result = frac1.add(frac2);

        cout << "Сумма дробей: ";
        result.displayData();
        cout << endl;

        cout << "Хотите выполнить еще одно сложение? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
