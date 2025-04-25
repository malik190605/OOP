#include <iostream>
#include <string>
using namespace std;

// Базовый абстрактный класс
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
        cin.ignore(); // очистка буфера после ввода
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }

    virtual bool isOversize() const = 0; // Чисто виртуальная функция

    virtual ~publication() {}
};

// Подкласс book
class book : public publication {
private:
    int pages;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }

    bool isOversize() const override {
        return pages > 800;
    }
};

// Подкласс tape
class tape : public publication {
private:
    float playing_time; // в минутах
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите время воспроизведения (в минутах): ";
        cin >> playing_time;
        cin.ignore();
    }

    void putdata() const override {
        publication::putdata();
        cout << "Время воспроизведения: " << playing_time << " мин." << endl;
    }

    bool isOversize() const override {
        return playing_time > 90.0;
    }
};

// Главная функция
int main() {

    setlocale(LC_ALL, "RU");

    const int SIZE = 100;
    publication* pubarr[SIZE]; // массив указателей на публикации
    int n = 0; // текущее количество объектов
    char choice;

    do {
        cout << "\nВведите тип публикации (книга = b, кассета = t): ";
        cin >> choice;
        cin.ignore(); // очистка буфера

        if (choice == 'b') {
            pubarr[n] = new book;
        }
        else if (choice == 't') {
            pubarr[n] = new tape;
        }
        else {
            cout << "Неверный выбор!\n";
            continue;
        }

        pubarr[n]->getdata();
        n++;

        cout << "Добавить ещё одну? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' && n < SIZE);

    // Вывод данных
    cout << "\nВведённые публикации:\n";
    for (int i = 0; i < n; i++) {
        pubarr[i]->putdata();
        if (pubarr[i]->isOversize())
            cout << "⚠️ Превышение размера!" << endl;
        cout << "-------------------------\n";
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++)
        delete pubarr[i];

    return 0;
}
