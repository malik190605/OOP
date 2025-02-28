#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Метод для сокращения дроби
    void lowterms() {
        long tnum = labs(numerator);
        long tden = labs(denominator);
        long temp, gcd;

        if (tden == 0) {
            cout << "Недопустимый знаменатель!";
            exit(1);
        }
        else if (tnum == 0) {
            numerator = 0;
            denominator = 1;
            return;
        }

        while (tnum != 0) {
            if (tnum < tden) {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    // Конструктор
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        lowterms();
    }

    // Метод для ввода дроби
    void inputData() {
        char slash;
        cout << "Введите дробь в формате a/b: ";
        cin >> numerator >> slash >> denominator;
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть нулем! Установлено значение 1." << endl;
            denominator = 1;
        }
        lowterms();
    }

    // Метод для вывода дроби
    void displayData() const {
        cout << numerator << "/" << denominator;
    }

    // Арифметические операции
    Fraction add(const Fraction& other) const {
        Fraction result(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
        return result;
    }

    Fraction subtract(const Fraction& other) const {
        Fraction result(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
        return result;
    }

    Fraction multiply(const Fraction& other) const {
        Fraction result(numerator * other.numerator, denominator * other.denominator);
        return result;
    }

    Fraction divide(const Fraction& other) const {
        Fraction result(numerator * other.denominator, denominator * other.numerator);
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    char choice;
    do {
        Fraction frac1, frac2, result;
        char operation;

        cout << "Введите первую дробь:\n";
        frac1.inputData();

        cout << "Введите вторую дробь:\n";
        frac2.inputData();

        cout << "Выберите операцию (+, -, *, /): ";
        cin >> operation;

        switch (operation) {
        case '+': result = frac1.add(frac2); break;
        case '-': result = frac1.subtract(frac2); break;
        case '*': result = frac1.multiply(frac2); break;
        case '/': result = frac1.divide(frac2); break;
        default: cout << "Некорректная операция!" << endl; continue;
        }

        cout << "Результат: ";
        result.displayData();
        cout << endl;

        cout << "Хотите выполнить еще одну операцию? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}