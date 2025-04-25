#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath> // для modfl()

using namespace std;

class bMoney {
private:
    long double amount;

    // Преобразование строки в число (удаляет $, ,)
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

    // Метод для ввода строки
    void getMoney() {
        string str;
        cout << "Введите сумму (например, $1,234.56): ";
        getline(cin, str);
        amount = strToMoney(str);
    }

    // Метод для вывода
    void show() const {
        cout << "$" << fixed << setprecision(2) << amount;
    }

    // Метод округления до ближайшего доллара
    bMoney round() const {
        long double intPart, fracPart;
        fracPart = modfl(amount, &intPart); // разбиваем на целую и дробную части

        if (fracPart < 0.5L)
            return bMoney(intPart);
        else
            return bMoney(intPart + 1.0L);
    }
};

// MAIN: проверка округления
int main() {
    setlocale(LC_ALL, "RU");
    bMoney m;

    cout << "Проверка округления денежного значения:\n";
    m.getMoney();

    bMoney rounded = m.round();

    cout << "\nДо округления: ";
    m.show();

    cout << "\nПосле округления: ";
    rounded.show();

    cout << endl;
    return 0;
}
