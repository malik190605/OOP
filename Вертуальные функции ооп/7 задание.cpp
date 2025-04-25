#include <iostream>
#include <cstring>    
#include <iomanip>    
using namespace std;

class person {
private:
    char name[40];
    float salary;
public:
    void setData() {
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите зарплату: ";
        cin >> salary;
    }

    void printData() const {
        cout << left << setw(15) << name << " | Зарплата: " << fixed << setprecision(2) << salary << endl;
    }

    float getSalary() const {
        return salary;
    }
};

// Сортировка указателей на person по зарплате
void salsort(person** pp, int n) {
    person* temp;
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                // меняем указатели местами
                temp = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int SIZE = 5;
    person* persPtr[SIZE]; // массив указателей на person

    // Ввод данных
    for (int i = 0; i < SIZE; i++) {
        persPtr[i] = new person;      // создаём объект
        cout << "\nДанные человека #" << i + 1 << ":\n";
        persPtr[i]->setData();        // ввод через указатель
    }

    // Сортировка по зарплате
    salsort(persPtr, SIZE);

    // Вывод отсортированных данных
    cout << "\nОтсортировано по зарплате:\n";
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    // Очистка памяти
    for (int i = 0; i < SIZE; i++) {
        delete persPtr[i];
    }

    return 0;
}
