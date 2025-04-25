#include <iostream>
using namespace std;

class Link {
public:
    int data;
    Link* next;
    Link(int d) : data(d), next(nullptr) {}
};

class LinkList {
private:
    Link* head;

    // вспомогательная функция для копирования списка
    void copyFrom(const LinkList& other) {
        if (!other.head) {
            head = nullptr;
            return;
        }

        head = new Link(other.head->data);
        Link* current = head;
        Link* otherCurrent = other.head->next;

        while (otherCurrent) {
            current->next = new Link(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

public:
    LinkList() : head(nullptr) {}

    // конструктор копирования
    LinkList(const LinkList& other) {
        copyFrom(other);
    }

    // оператор присваивания
    LinkList& operator=(const LinkList& other) {
        if (this == &other) return *this;

        // удаляем старый список
        while (head) {
            Link* temp = head;
            head = head->next;
            delete temp;
        }

        // копируем новый
        copyFrom(other);
        return *this;
    }

    // деструктор
    ~LinkList() {
        while (head) {
            Link* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addItem(int value) {
        Link* newLink = new Link(value);
        newLink->next = head;
        head = newLink;
    }

    void display() const {
        Link* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// тест main()
int main() {
    LinkList* list1 = new LinkList();
    list1->addItem(10);
    list1->addItem(20);
    list1->addItem(30);

    cout << "List 1: ";
    list1->display();

    LinkList* list2 = new LinkList();
    *list2 = *list1; // оператор присваивания

    delete list1; // удаляем первый список

    cout << "List 2 после удаления list1: ";
    list2->display(); // должно работать корректно

    delete list2;
    return 0;
}
