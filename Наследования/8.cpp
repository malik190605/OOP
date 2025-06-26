#include <iostream>
#include <cstring> // ��� ������ �� ��������
#include <locale>

using namespace std;

// ������� ����� Pstring (������ � ���������� ��������)
class Pstring {
protected:
    static const int MAX = 100; // ������������ ����� ������
    char str[MAX]; // ����� ��� ������

public:
    // �����������
    Pstring(const char* s = "") {
        strncpy(str, s, MAX - 1);
        str[MAX - 1] = '\0'; // �������� ���������� ������
    }

    // ����� ������
    void show() const {
        cout << str << endl;
    }

    // ���������� ��������� �� ������
    const char* getStr() const {
        return str;
    }

    // �������� ������������
    Pstring& operator=(const char* s) {
        strncpy(str, s, MAX - 1);
        str[MAX - 1] = '\0';
        return *this;
    }
};

// ����������� ����� Pstring2 � �������� left(), mid() � right()
class Pstring2 : public Pstring {
public:
    // �����������
    Pstring2(const char* s = "") : Pstring(s) {}

    // �������� n ����� �������� �� s1 � ������� ������
    Pstring2& left(const Pstring& s1, int n) {
        strncpy(str, s1.getStr(), n);
        str[n] = '\0'; // ��������� ������
        return *this;
    }

    // �������� n �������� �� �������� ������, ������� � ������� s
    Pstring2& mid(const Pstring& s1, int s, int n) {
        int len = strlen(s1.getStr());
        if (s >= len) {
            str[0] = '\0'; // ���� ������� ��� ������, ������ ������ ������
        }
        else {
            strncpy(str, s1.getStr() + s, n);
            str[n] = '\0'; // ��������� ������
        }
        return *this;
    }

    // �������� n ������ �������� �� s1 � ������� ������
    Pstring2& right(const Pstring& s1, int n) {
        int len = strlen(s1.getStr());
        if (n > len) n = len; // ���� n ������ ����� ������, ����� ��� ������
        strncpy(str, s1.getStr() + (len - n), n);
        str[n] = '\0'; // ��������� ������
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Pstring2 s1("���������������� �� C++");
    Pstring2 s2;

    cout << "�������� ������:\n";
    s1.show();

    cout << "\n����� 12 ��������:\n";
    s2.left(s1, 12).show();

    cout << "\n������� 11 �������� (� 14-� �������):\n";
    s2.mid(s1, 14, 11).show();

    cout << "\n������ 5 ��������:\n";
    s2.right(s1, 5).show();

    return 0;
}
