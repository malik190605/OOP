#include <iostream>
using namespace std;

// Класс одного элемента списка
class Link {
public:
    int data;
    Link* next;

    Link(int d) : data(d), next(nullptr) {}
};

// Класс списка
class LinkList {
private:
    Link* first;

public:
    LinkList() : first(nullptr) {}

    // Добавление в КОНЕЦ списка
    void addItem(int d) {
        Link* newLink = new Link(d);
        if (first == nullptr) {
            // Если список пуст — новый элемент становится первым
            first = newLink;
        }
        else {
            // Иначе — ищем последний элемент
            Link* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newLink; // присоединяем в конец
        }
    }

    // Отображение списка
    void display() const {
        Link* current = first;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Деструктор — удаление всех элементов
    ~LinkList() {
        Link* current = first;
        while (current != nullptr) {
            Link* temp = current;
            current = current->next;
            cout << "Удаляется элемент: " << temp->data << endl;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    LinkList list;

    list.addItem(25);
    list.addItem(36);
    list.addItem(49);
    list.addItem(64);

    cout << "Содержимое списка:\n";
    list.display();

    return 0;
}
