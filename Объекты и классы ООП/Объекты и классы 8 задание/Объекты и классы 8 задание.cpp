#include <iostream>
#include <locale>  // Добавляем заголовочный файл для setlocale

using namespace std;

class Object {
private:
    static int count;  // Статическая переменная для подсчета объектов
    int id;            // Индивидуальный порядковый номер объекта

public:
    // Конструктор
    Object() {
        count++;  // Увеличиваем количество объектов
        id = count;  // Присваиваем объекту индивидуальный номер
    }

    // Метод для вывода порядкового номера
    void showId() const {
        cout << "Мой порядковый номер: " << id << endl;
    }

    // Статический метод для получения общего количества объектов
    static int getCount() {
        return count;
    }
};

// Инициализация статической переменной
int Object::count = 0;

int main() {
    // Устанавливаем русскую локаль
    setlocale(LC_ALL, "Russian");

    // Создание трех объектов
    Object obj1;
    Object obj2;
    Object obj3;

    // Вывод порядковых номеров объектов
    obj1.showId();
    obj2.showId();
    obj3.showId();

    return 0;
}
