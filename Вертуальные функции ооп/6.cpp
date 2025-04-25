#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class bMoney {
private:
    long double amount;

    // ����������� ������ � ����� (������� $, , � �.�.)
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

    // ����
    void getMoney() {
        string str;
        cout << "������� ����� (��������, $1,234.56): ";
        getline(cin, str);
        amount = strToMoney(str);
    }

    // �����
    void show() const {
        cout << "$" << fixed << setprecision(2) << amount;
    }

    // ���������� ����� ���������
    bMoney operator+(const bMoney& m) const { return bMoney(amount + m.amount); }
    bMoney operator-(const bMoney& m) const { return bMoney(amount - m.amount); }
    bMoney operator*(const bMoney& m) const { return bMoney(amount * m.amount); }
    bMoney operator/(const bMoney& m) const {
        if (m.amount == 0.0L) throw runtime_error("������� �� ����!");
        return bMoney(amount / m.amount);
    }

    // ������ * �����, ������ / �����
    bMoney operator*(long double n) const { return bMoney(amount * n); }
    bMoney operator/(long double n) const {
        if (n == 0.0L) throw runtime_error("������� �� ����!");
        return bMoney(amount / n);
    }

    // ������������� �������: ����� * ������, ����� / ������
    friend bMoney operator*(long double n, const bMoney& m);
    friend bMoney operator/(long double n, const bMoney& m);
};

// ����������� ������������� �������
bMoney operator*(long double n, const bMoney& m) {
    return bMoney(n * m.amount);
}

bMoney operator/(long double n, const bMoney& m) {
    if (m.amount == 0.0L) throw runtime_error("������� �� ����!");
    return bMoney(n / m.amount);
}
int main() {
    setlocale(LC_ALL, "RU");
    bMoney m1, m2;
    long double num;

    cout << "������ �����:\n";
    m1.getMoney();

    cout << "������ �����:\n";
    m2.getMoney();

    cout << "������� �����: ";
    cin >> num;

    cout << "\n--- ���������� �������� ---\n";

    cout << "��������: ";
    (m1 + m2).show(); cout << endl;

    cout << "���������: ";
    (m1 - m2).show(); cout << endl;

    cout << "��������� ��������: ";
    (m1 * m2).show(); cout << endl;

    try {
        cout << "������� ��������: ";
        (m1 / m2).show(); cout << endl;
    }
    catch (runtime_error& e) {
        cout << "������: " << e.what() << endl;
    }

    cout << "m1 * �����: ";
    (m1 * num).show(); cout << endl;

    cout << "m1 / �����: ";
    try {
        (m1 / num).show(); cout << endl;
    }
    catch (runtime_error& e) {
        cout << "������: " << e.what() << endl;
    }

    cout << "����� * m2: ";
    (num * m2).show(); cout << endl;

    cout << "����� / m2: ";
    try {
        (num / m2).show(); cout << endl;
    }
    catch (runtime_error& e) {
        cout << "������: " << e.what() << endl;
    }

    return 0;
}
