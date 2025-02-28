// Объукты и классы 12 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <cmath>
#include <vector>
using namespace std;


class Fraction {
private:
    int numerator;
    int denominator;

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
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        lowterms();
    }

    void displayData() const {
        cout << numerator << "/" << denominator;
    }

    Fraction multiply(const Fraction& other) const {
        Fraction result(numerator * other.numerator, denominator * other.denominator);
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int denom;
    cout << "Введите знаменатель: ";
    cin >> denom;

    vector<Fraction> fractions;
    for (int i = 1; i < denom; i++) {
        fractions.push_back(Fraction(i, denom));
    }

    cout << "\t";
    for (const auto& frac : fractions) {
        frac.displayData();
        cout << "\t";
    }
    cout << "\n-----------------------------------------\n";

    for (const auto& frac1 : fractions) {
        frac1.displayData();
        cout << "|\t";
        for (const auto& frac2 : fractions) {
            Fraction result = frac1.multiply(frac2);
            result.displayData();
            cout << "\t";
        }
        cout << endl;
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
