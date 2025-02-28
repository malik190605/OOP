// Объекты и классы. 2 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

class TollBooth {
private:
    unsigned int carCount;
    double revenue;
public:
    TollBooth() : carCount(0), revenue(0.0) {}

    void payingCar() {
        carCount++;
        revenue += 0.50;
    }

    void nopayCar() {
        carCount++;
    }

    void display() const {
        std::cout << "Total cars: " << carCount << "\nTotal revenue: $" << revenue << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    TollBooth tollBooth;
    char input;

    std::cout << "Press 'p' for paying car, 'n' for non-paying car, 'Esc' to exit.\n";
    while (true) {
        input = _getch(); // Используется для работы с клавишами без ожидания Enter

        if (input == 27) { // Esc key
            break;
        }
        else if (input == 'p' || input == 'P') {
            tollBooth.payingCar();
        }
        else if (input == 'n' || input == 'N') {
            tollBooth.nopayCar();
        }
    }

    tollBooth.display();
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
