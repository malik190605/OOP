#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Очередь переполнена\n";
            return;
        }
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста\n";
            return -1;
        }
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    void display() {
        if (isEmpty()) {
            cout << "Очередь пуста\n";
            return;
        }
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Содержимое очереди: ";
    q.display();

    cout << "Удалено из очереди: " << q.dequeue() << endl;
    cout << "После удаления: ";
    q.display();

    return 0;
}
