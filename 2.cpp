#include <iostream>
#include <string>
using namespace std;

// ������� �����
class publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "������� ��������: ";
        getline(cin, title);
        cout << "������� ����: ";
        cin >> price;
        cin.ignore(); // ������� ������
    }

    virtual void putdata() const {
        cout << "��������: " << title << endl;
        cout << "����: " << price << " ���." << endl;
    }

    virtual ~publication() {} // ����������� ����������
};

// ����������� ����� � �����
class book : public publication {
private:
    int pages;
public:
    void getdata() override {
        publication::getdata();
        cout << "������� ���������� �������: ";
        cin >> pages;
        cin.ignore(); // ������� ������
    }

    void putdata() const override {
        publication::putdata();
        cout << "�������: " << pages << endl;
    }
};

// ����������� ����� � �������
class tape : public publication {
private:
    float playing_time;
public:
    void getdata() override {
        publication::getdata();
        cout << "������� ����� ��������������� (� �������): ";
        cin >> playing_time;
        cin.ignore(); // ������� ������
    }

    void putdata() const override {
        publication::putdata();
        cout << "����� ���������������: " << playing_time << " �����" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    const int SIZE = 100;
    publication* pubarr[SIZE]; // ������ ���������� �� publication
    int n = 0; // ������� �������� �������
    char choice;

    do {
        cout << "\n������� ��� ���������� (����� = b, ������� = t): ";
        cin >> choice;
        cin.ignore(); // ������� '\n'

        if (choice == 'b') {
            pubarr[n] = new book;
        }
        else if (choice == 't') {
            pubarr[n] = new tape;
        }
        else {
            cout << "�������� �����. �������." << endl;
            continue;
        }

        pubarr[n]->getdata();
        n++;

        cout << "�������� ��� ����? (y/n): ";
        cin >> choice;
        cin.ignore(); // ������� '\n'
    } while (choice == 'y' && n < SIZE);

    cout << "\n�������� ����������:\n";
    for (int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        cout << "------------------------\n";
    }

    // ������� ������
    for (int j = 0; j < n; j++) {
        delete pubarr[j];
    }

    return 0;
}
