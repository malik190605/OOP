#include "verylong.h"
#include <clocale>
#include <string>
#include <limits>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "��������� ��� ������ � �������� �������" << endl;

    string input1, input2;
    cout << "������� ������ ����� (��������, 123 ��� -1234567890): ";
    cin >> input1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������
    cout << "������� ������ ����� (��������, 5 ��� -9876543210): ";
    cin >> input2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������

    verylong a(input1.c_str());
    verylong b(input2.c_str());

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a / b = " << a / b << endl;

    return 0;
}