#include <iostream>
using namespace std;

// Класс одного элемента списка
class Link {
public:
    int data;       // данные
    Link* next;     // указатель на следующий элемент

    Link(int d) : data(d), next(nullptr) {}
};

// Класс списка
class LinkList {
private:
    Link* first;    // указатель на первый элемент
public:
    LinkList() : first(nullptr) {}

    // Добавление элемента в начало списка
    void addItem(int d) {
        Link* newLink = new Link(d);
        newLink->next = first;
        first = newLink;
    }

    // Отображение списка
    void display() const {
        Link* current = first;
        cout << "Список: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Деструктор — удаление всех элементов списка
    ~LinkList() {
        Link* current = first;
        while (current != nullptr) {
            cout << "Удаляется элемент со значением: " << current->data << endl;
            Link* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    LinkList list;

    list.addItem(10);
    list.addItem(20);
    list.addItem(30);

    list.display();

    // При завершении main() будет вызван деструктор
    return 0;
}
