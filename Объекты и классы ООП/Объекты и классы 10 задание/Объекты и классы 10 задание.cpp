// Объекты и классы 10 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <locale>
using namespace std;

class Angle {
public:
    double degrees;
    double minutes;
    char direction; // N, S, E, W

    void inputAngle() {
        cout << "Введите угол (градусы, минуты, направление N/S/E/W): ";
        cin >> degrees >> minutes >> direction;
    }

    void displayAngle() const {
        cout << degrees << "°" << minutes << "' " << direction;
    }
};

class Ship {
   
private:
    static int count;  // Статическая переменная для подсчета объектов
    int id;            // Учетный номер корабля
    Angle latitude;    // Широта
    Angle longitude;   // Долгота

public:
    // Конструктор
    Ship() {
        count++;
        id = count;
    }

    // Метод для ввода данных о корабле
    void inputData() {
        cout << "Введите координаты корабля (широта): " << endl;
        latitude.inputAngle();
        cout << "Введите координаты корабля (долгота): " << endl;
        longitude.inputAngle();
    }

    // Метод для вывода данных о корабле
    void displayData() const {
        cout << "Корабль №" << id << " | Широта: ";
        latitude.displayAngle();
        cout << " | Долгота: ";
        longitude.displayAngle();
        cout << endl;
    }
};

// Инициализация статической переменной
int Ship::count = 0;

int main() {
    setlocale(LC_ALL, "Russian");

    Ship ships[3];

    for (int i = 0; i < 3; i++) {
        cout << "Ввод данных для корабля " << (i + 1) << endl;
        ships[i].inputData();
    }

    cout << "\nИнформация о кораблях:\n";
    for (int i = 0; i < 3; i++) {
        ships[i].displayData();
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
