#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <locale>

using namespace std;

// ������� ����� ����������
class employee {
protected:
    string name;   // ��� ����������
    int number;    // ��������� �����

public:
    void getData() {
        cout << "������� ���: ";
        getline(cin, name);
        cout << "������� ��������� �����: ";
        cin >> number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� �����
    }

    void putData() const {
        cout << "���: " << name << "\n��������� �����: " << number << endl;
    }
};

// ����� ��� ����������� (������)
class compensation {
protected:
    enum PayPeriod { HOURLY, WEEKLY, MONTHLY }; // ������ ������
    double compensationAmount; // ������ ������
    PayPeriod period;          // ������ ������

public:
    void getCompensation() {
        cout << "������� ������ ������: ";
        cin >> compensationAmount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� �����

        char choice;
        cout << "�������� ������ ������ (h - ���������, w - �����������, m - ����������): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 'h': case 'H': period = HOURLY; break;
        case 'w': case 'W': period = WEEKLY; break;
        case 'm': case 'M': period = MONTHLY; break;
        default:
            cout << "������������ ����! �� ��������� ������� ��������� ������.\n";
            period = HOURLY;
        }
    }

    void putCompensation() const {
        cout << "������ ������: " << fixed << setprecision(2) << compensationAmount << " ���.\n"
            << "������ ������: " << (period == HOURLY ? "���������" : (period == WEEKLY ? "�����������" : "����������")) << "\n";
    }
};

// ����� ����� employee2, ������� ���������� employee � compensation
class employee2 : public employee, public compensation {
public:
    void getData() {
        employee::getData();
        getCompensation();
    }

    void putData() const {
        employee::putData();
        putCompensation();
    }
};

// ������ ����������� (��������, ������, �������)
class manager : public employee {
protected:
    string title; // ���������

public:
    void getData() {
        employee::getData();
        cout << "������� ���������: ";
        getline(cin, title);
    }

    void putData() const {
        employee::putData();
        cout << "���������: " << title << endl;
    }
};

class scientist : public employee {
protected:
    int publications; // ���������� ����������

public:
    void getData() {
        employee::getData();
        cout << "������� ���������� ����������: ";
        cin >> publications;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void putData() const {
        employee::putData();
        cout << "����������: " << publications << endl;
    }
};

class laborer : public employee {}; // ������� ��� ���. �����

// ������ � ������������, ��������� ������������� ������������
class manager2 : public manager, public compensation {
public:
    void getData() {
        manager::getData();
        getCompensation();
    }

    void putData() const {
        manager::putData();
        putCompensation();
    }
};

class scientist2 : public scientist, public compensation {
public:
    void getData() {
        scientist::getData();
        getCompensation();
    }

    void putData() const {
        scientist::putData();
        putCompensation();
    }
};

class laborer2 : public laborer, public compensation {
public:
    void getData() {
        laborer::getData();
        getCompensation();
    }

    void putData() const {
        laborer::putData();
        putCompensation();
    }
};

// ������� �������
int main() {
    setlocale(LC_ALL, "ru");

    manager2 m;
    scientist2 s;
    laborer2 l;

    cout << "\n���� ������ ��� ���������:\n";
    m.getData();

    cout << "\n���� ������ ��� �������:\n";
    s.getData();

    cout << "\n���� ������ ��� ��������:\n";
    l.getData();

    cout << "\n����� ������:\n";
    cout << "\n��������:\n"; m.putData();
    cout << "\n������:\n"; s.putData();
    cout << "\n�������:\n"; l.putData();

    return 0;
}
