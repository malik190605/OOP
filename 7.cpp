#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath> // ��� modfl()

using namespace std;

class bMoney {
private:
    long double amount;

    // �������������� ������ � ����� (������� $, ,)
    long double strToMoney(const string& str) const {
        string clean;
        for (char c : str) {
            if ((c >= '0' && c <= '9') || c == '.')
                clean += c;
        }
        return stold(clean);
    }

public:
    // ������������
    bMoney() : amount(0.0) {}
    bMoney(long double a) : amount(a) {}
    bMoney(string str) { amount = strToMoney(str); }

    // ����� ��� ����� ������
    void getMoney() {
        string str;
        cout << "������� ����� (��������, $1,234.56): ";
        getline(cin, str);
        amount = strToMoney(str);
    }

    // ����� ��� ������
    void show() const {
        cout << "$" << fixed << setprecision(2) << amount;
    }

    // ����� ���������� �� ���������� �������
    bMoney round() const {
        long double intPart, fracPart;
        fracPart = modfl(amount, &intPart); // ��������� �� ����� � ������� �����

        if (fracPart < 0.5L)
            return bMoney(intPart);
        else
            return bMoney(intPart + 1.0L);
    }
};

// MAIN: �������� ����������
int main() {
    setlocale(LC_ALL, "RU");
    bMoney m;

    cout << "�������� ���������� ��������� ��������:\n";
    m.getMoney();

    bMoney rounded = m.round();

    cout << "\n�� ����������: ";
    m.show();

    cout << "\n����� ����������: ";
    rounded.show();

    cout << endl;
    return 0;
}
