#include <iostream>
#include <string>
#include <locale>

using namespace std;

// ������� ����� "��������"
class Employee {
protected:
    string name;
    long id;
public:
    // ����������� �� ���������
    Employee() : name(""), id(0) {}

    // ���� ������
    void getData() {
        cout << "������� ���: ";
        cin.ignore();
        getline(cin, name);
        cout << "������� ID: ";
        cin >> id;
    }

    // ����� ������
    void putData() const {
        cout << "���: " << name << "\nID: " << id << endl;
    }
};

// ����������� ����� "��������"
class Manager : public Employee {
protected:
    string department;
public:
    // ���� ������
    void getData() {
        Employee::getData();
        cout << "������� �����: ";
        cin.ignore();
        getline(cin, department);
    }

    // ����� ������
    void putData() const {
        Employee::putData();
        cout << "�����: " << department << endl;
    }
};

// ����������� ����� "�����������" (������� ��������)
class Executive : public Manager {
private:
    double bonus;  // ������� ������
    int shares;    // ���������� �����
public:
    // ���� ������
    void getData() {
        Manager::getData();
        cout << "������� ������� ������ ($): ";
        cin >> bonus;
        cout << "������� ���������� �����: ";
        cin >> shares;
    }

    // ����� ������
    void putData() const {
        Manager::putData();
        cout << "������� ������: $" << bonus << "\n�����: " << shares << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Executive exec;

    cout << "������� ������ ��� ������������:\n";
    exec.getData();

    cout << "\n���������� �� �����������:\n";
    exec.putData();

    return 0;
}
