﻿// Объекты и классы. 4 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Employee {
private:
    int empNumber;
    float salary;
public:
    void setData() {
        std::cout << "Enter employee number: ";
        std::cin >> empNumber;
        std::cout << "Enter salary: ";
        std::cin >> salary;
    }

    void displayData() const {
        std::cout << "Employee Number: " << empNumber << "\nSalary: $" << salary << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    Employee employees[3];

    for (int i = 0; i < 3; i++) {
        std::cout << "Enter details for employee " << i + 1 << ":\n";
        employees[i].setData();
    }

    std::cout << "\nEmployee details:\n";
    for (int i = 0; i < 3; i++) {
        employees[i].displayData();
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
