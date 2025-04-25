
#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;  // ��������� �� ������
    int size;  // ������ �������
public:
    // �����������
    Array(int s) : size(s) {
        ptr = new int[s];
    }

    // ����������
    ~Array() {
        delete[] ptr;
    }

    // ����������� ����������� (�������� �����)
    Array(const Array& other) : size(other.size) {
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];
    }

    // ���������� ��������� ������������ (�������� �����)
    Array& operator=(const Array& other) {
        if (this == &other)  // ������ �� ����������������
            return *this;

        // ���� ������� ������ � ����������� ������
        if (size != other.size) {
            delete[] ptr;
            size = other.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];

        return *this;
    }

    // ���������� ��������� [] ��� ������� �� �������
    int& operator[](int j) {
        return *(ptr + j);
    }

    // ����� ��� ��������� ������� (�������������, �� �������)
    int getSize() const { return size; }
};

int main() {

    setlocale(LC_ALL, "RU"); 

    const int ASIZE = 10;

    Array arr1(ASIZE);
    for (int j = 0; j < ASIZE; j++)
        arr1[j] = j * j;

    cout << "arr1: ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr1[j] << ' ';
    cout << endl;

    // �������� ������������ �����������
    Array arr2(arr1);
    cout << "arr2 (����� arr1): ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr2[j] << ' ';
    cout << endl;

    // �������� ��������� ������������
    Array arr3(ASIZE);
    arr3 = arr1;
    cout << "arr3 (���������� arr1): ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr3[j] << ' ';
    cout << endl;

    // �������� ������������ ������� ������� �������
    Array arr4(5); // ������ ���������
    arr4 = arr1;
    cout << "arr4 (������ ��� 5, ������ ����� arr1): ";
    for (int j = 0; j < arr4.getSize(); j++)
        cout << arr4[j] << ' ';
    cout << endl;

    return 0;
}
