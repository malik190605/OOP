#include <iostream>
#include <string>
#include <locale>

using namespace std;

// ����� ��� �������� ����
class Date {
private:
    int day, month, year;
public:
    // ����������� �� ���������
    Date() : day(1), month(1), year(2000) {}

    // ����������� � �����������
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // ���� ����
    void input() {
        cout << "������� ����: ";
        cin >> day;
        cout << "������� �����: ";
        cin >> month;
        cout << "������� ���: ";
        cin >> year;
    }

    // ����� ����
    void display() const {
        cout << day << "." << month << "." << year;
    }
};

// ������� ����� "����������"
class Publication {
protected:
    string title;
    float price;
public:
    // ����������� �� ���������
    Publication() : title(""), price(0.0) {}

    // ���� ������
    void getData() {
        cout << "������� ��������: ";
        cin.ignore();
        getline(cin, title);
        cout << "������� ����: ";
        cin >> price;
    }

    // ����� ������
    void putData() const {
        cout << "��������: " << title << "\n����: " << price << " ���\n";
    }
};

// ����� ����� "���������� 2" (��������� Publication, �������� ����)
class Publication2 : public Publication {
protected:
    Date releaseDate;
public:
    // ���� ������
    void getData() {
        Publication::getData();
        cout << "������� ���� ������ �����:\n";
        releaseDate.input();
    }

    // ����� ������
    void putData() const {
        Publication::putData();
        cout << "���� ������: ";
        releaseDate.display();
        cout << endl;
    }
};

// ����� "�����" (����������� �� Publication2)
class Book : public Publication2 {
private:
    int pages;
public:
    // ���� ������
    void getData() {
        Publication2::getData();
        cout << "������� ���������� �������: ";
        cin >> pages;
    }

    // ����� ������
    void putData() const {
        Publication2::putData();
        cout << "�������: " << pages << endl;
    }
};

// ����� "��� ����������" (��������, ����������, ������ � �. �.)
class Type : public Publication2 {
private:
    float duration; // ����������������� � �������
public:
    // ���� ������
    void getData() {
        Publication2::getData();
        cout << "������� ����������������� (� �������): ";
        cin >> duration;
    }

    // ����� ������
    void putData() const {
        Publication2::putData();
        cout << "�����������������: " << duration << " ���\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Book b;
    Type t;

    cout << "������� ������ ��� �����:\n";
    b.getData();

    cout << "\n������� ������ ��� ���� ���������� (��������, ����������):\n";
    t.getData();

    cout << "\n���������� � �����:\n";
    b.putData();

    cout << "\n���������� � ���� ����������:\n";
    t.putData();

    return 0;
}
