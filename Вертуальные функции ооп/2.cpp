#include <iostream>
#include <string>
using namespace std;

// Базовый класс
class publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Введите название: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore(); // Очистка буфера
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " сом." << endl;
    }

    virtual ~publication() {} // Виртуальный деструктор
};

// Производный класс — книга
class book : public publication {
private:
    int pages;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(); // Очистка буфера
    }

    void putdata() const override {
        publication::putdata();
        cout << "Страниц: " << pages << endl;
    }
};

// Производный класс — кассета
class tape : public publication {
private:
    float playing_time;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите время воспроизведения (в минутах): ";
        cin >> playing_time;
        cin.ignore(); // Очистка буфера
    }

    void putdata() const override {
        publication::putdata();
        cout << "Время воспроизведения: " << playing_time << " минут" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    const int SIZE = 100;
    publication* pubarr[SIZE]; // массив указателей на publication
    int n = 0; // сколько объектов создано
    char choice;

    do {
        cout << "\nВведите тип публикации (книга = b, кассета = t): ";
        cin >> choice;
        cin.ignore(); // очистка '\n'

        if (choice == 'b') {
            pubarr[n] = new book;
        }
        else if (choice == 't') {
            pubarr[n] = new tape;
        }
        else {
            cout << "Неверный выбор. Пропуск." << endl;
            continue;
        }

        pubarr[n]->getdata();
        n++;

        cout << "Добавить ещё одну? (y/n): ";
        cin >> choice;
        cin.ignore(); // очистка '\n'
    } while (choice == 'y' && n < SIZE);

    cout << "\nВведённые публикации:\n";
    for (int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        cout << "------------------------\n";
    }

    // Очистка памяти
    for (int j = 0; j < n; j++) {
        delete pubarr[j];
    }

    return 0;
}
