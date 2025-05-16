#include <iostream>
#include <stdexcept>
using namespace std;

class QueueOverflowException : public runtime_error {
public:
    QueueOverflowException() : runtime_error("Очередь переполнена") {}
};

class QueueUnderflowException : public runtime_error {
public:
    QueueUnderflowException() : runtime_error("Очередь пуста") {}
};

class Queue {
private:
    static const int MAX = 5;
    int arr[MAX];
    int front, rear, count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    void enqueue(int value) {
        if (count >= MAX) throw QueueOverflowException();
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (count <= 0) throw QueueUnderflowException();
        int val = arr[front];
        front = (front + 1) % MAX;
        count--;
        return val;
    }

    void display() {
        if (count == 0) {
            cout << "Очередь пуста\n";
            return;
        }
        cout << "Очередь: ";
        for (int i = 0; i < count; ++i)
            cout << arr[(front + i) % MAX] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n1. Добавить в очередь\n2. Удалить из очереди\n3. Показать очередь\n4. Выход\nВыбор: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Введите значение: ";
                    cin >> value;
                    q.enqueue(value);
                    cout << "Добавлено.\n";
                    break;
                case 2:
                    value = q.dequeue();
                    cout << "Удалено: " << value << endl;
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Неверный выбор.\n";
            }
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}
