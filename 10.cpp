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

    // ��������������� ������� ��� ����������� ������
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

    // ����������� �����������
    LinkList(const LinkList& other) {
        copyFrom(other);
    }

    // �������� ������������
    LinkList& operator=(const LinkList& other) {
        if (this == &other) return *this;

        // ������� ������ ������
        while (head) {
            Link* temp = head;
            head = head->next;
            delete temp;
        }

        // �������� �����
        copyFrom(other);
        return *this;
    }

    // ����������
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

// ���� main()
int main() {
    LinkList* list1 = new LinkList();
    list1->addItem(10);
    list1->addItem(20);
    list1->addItem(30);

    cout << "List 1: ";
    list1->display();

    LinkList* list2 = new LinkList();
    *list2 = *list1; // �������� ������������

    delete list1; // ������� ������ ������

    cout << "List 2 ����� �������� list1: ";
    list2->display(); // ������ �������� ���������

    delete list2;
    return 0;
}
