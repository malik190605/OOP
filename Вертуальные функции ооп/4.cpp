
#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;  // указатель на массив
    int size;  // размер массива
public:
    //  онструктор
    Array(int s) : size(s) {
        ptr = new int[s];
    }

    // ƒеструктор
    ~Array() {
        delete[] ptr;
    }

    //  онструктор копировани€ (глубока€ копи€)
    Array(const Array& other) : size(other.size) {
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];
    }

    // ѕерегрузка оператора присваивани€ (глубока€ копи€)
    Array& operator=(const Array& other) {
        if (this == &other)  // защита от самоприсваивани€
            return *this;

        // ≈сли размеры разные Ч пересоздать массив
        if (size != other.size) {
            delete[] ptr;
            size = other.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];

        return *this;
    }

    // ѕерегрузка оператора [] дл€ доступа по индексу
    int& operator[](int j) {
        return *(ptr + j);
    }

    // ћетод дл€ получени€ размера (необ€зательно, но полезно)
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

    // ѕроверка конструктора копировани€
    Array arr2(arr1);
    cout << "arr2 (копи€ arr1): ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr2[j] << ' ';
    cout << endl;

    // ѕроверка оператора присваивани€
    Array arr3(ASIZE);
    arr3 = arr1;
    cout << "arr3 (присвоение arr1): ";
    for (int j = 0; j < ASIZE; j++)
        cout << arr3[j] << ' ';
    cout << endl;

    // ѕроверка присваивани€ массиву другого размера
    Array arr4(5); // меньше элементов
    arr4 = arr1;
    cout << "arr4 (размер был 5, теперь копи€ arr1): ";
    for (int j = 0; j < arr4.getSize(); j++)
        cout << arr4[j] << ' ';
    cout << endl;

    return 0;
}
