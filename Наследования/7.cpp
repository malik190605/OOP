#include <iostream>
#include <locale>

using namespace std;

// ������� ����� �������� (COUNTEN2)
class Counter {
protected:
    int count; // �������� ��������
public:
    // �����������
    Counter(int c = 0) : count(c) {}

    // ���������� ��������� (++counter)
    Counter& operator++() {
        ++count;
        return *this;
    }

    // ���������� ��������� (--counter)
    Counter& operator--() {
        --count;
        return *this;
    }

    // ����� ��������
    void show() const {
        cout << "�������� ��������: " << count << endl;
    }
};

// ����������� ����� � ������������ ����������
class CounterPostfix : public Counter {
public:
    // ���������� ����������� �������� ������
    CounterPostfix(int c = 0) : Counter(c) {}

    // ����������� ��������� (counter++)
    CounterPostfix operator++(int) {
        CounterPostfix temp = *this; // ��������� ������ ��������
        count++; // ����������� ��������
        return temp; // ���������� ������ ������
    }

    // ����������� ��������� (counter--)
    CounterPostfix operator--(int) {
        CounterPostfix temp = *this; // ��������� ������ ��������
        count--; // ��������� ��������
        return temp; // ���������� ������ ������
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    CounterPostfix c(5);
    cout << "�������� ��������:\n";
    c.show();

    cout << "\n���������� ��������� (++c):\n";
    ++c;
    c.show();

    cout << "\n����������� ��������� (c++):\n";
    c++;
    c.show();

    cout << "\n���������� ��������� (--c):\n";
    --c;
    c.show();

    cout << "\n����������� ��������� (c--):\n";
    c--;
    c.show();

    return 0;
}
