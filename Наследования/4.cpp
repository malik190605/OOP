#include <iostream>
#include <string>
#include <iomanip>  // ��� ���������������� ������
#include <limits>   // ��� ������� �����
#include <locale>   // ��� �����������

using namespace std;

class publication {
protected:
    string title;  // �������� ����������
    float price;   // ���� ����������

public:
    void getData() {
        cout << "������� �������� ����������: ";
        getline(cin, title);
        cout << "������� ����: ";
        cin >> price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� �����
    }

    void putData() const {
        cout << "��������: " << title << "\n����: " << fixed << setprecision(2) << price << " ���.\n";
    }
};

// ����� ����������� �����
class disk : public publication {
private:
    enum DiskType { CD, DVD };  // ������������ ��� ���� �����
    DiskType diskType;          // ���� ��� �������� ����

public:
    void getData() {
        publication::getData();  // ����� ������ �������� ������

        char choice;
        cout << "�������� ��� ����� (c - CD, d - DVD): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� �����

        if (choice == 'c' || choice == 'C')
            diskType = CD;
        else if (choice == 'd' || choice == 'D')
            diskType = DVD;
        else {
            cout << "������������ ����! �� ��������� ������ CD.\n";
            diskType = CD;
        }
    }

    void putData() const {
        publication::putData();  // ����� ������ �������� ������

        cout << "��� �����: " << (diskType == CD ? "CD" : "DVD") << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    disk myDisk;
    myDisk.getData();
    cout << "\n������ � �����:\n";
    myDisk.putData();

    return 0;
}
