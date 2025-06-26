#include <iostream>
#include <locale>

using namespace std;

// ��������� ��� �������� ���� �����
struct Pair {
    int x, y;
};

// ������� �����: ���� ��� ����� �����
class Stack2 {
protected:
    static const int SIZE = 10;
    int stack[SIZE]; // ������ ��� �����
    int top;         // ������ �������

public:
    Stack2() : top(-1) {} // �����������

    // ���������� �������� � ����
    void push(int value) {
        if (top < SIZE - 1)
            stack[++top] = value;
        else
            cout << "���� ����������!" << endl;
    }

    // ���������� �������� �� �����
    int pop() {
        if (top >= 0)
            return stack[top--];
        else {
            cout << "���� ����!" << endl;
            return -1;
        }
    }
};

// ����������� �����: ���� ��� ��� �����
class PairStack : public Stack2 {
public:
    // ���������� ���� ����� � ����
    void push(Pair p) {
        push(p.x);
        push(p.y);
    }

    // ���������� ���� ����� �� �����
    Pair pop() {
        Pair p;
        p.y = pop(); // ������� ����������� y
        p.x = pop(); // ����� x
        return p;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    PairStack stack;

    // ���������� � ���� ��� ����
    stack.push({ 1, 2 });
    stack.push({ 3, 4 });
    stack.push({ 5, 6 });

    // ��������� ���� � �������
    Pair p1 = stack.pop();
    cout << "����������� ����: (" << p1.x << ", " << p1.y << ")" << endl;

    Pair p2 = stack.pop();
    cout << "����������� ����: (" << p2.x << ", " << p2.y << ")" << endl;

    Pair p3 = stack.pop();
    cout << "����������� ����: (" << p3.x << ", " << p3.y << ")" << endl;

    return 0;
}
