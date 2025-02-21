// OOP 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

// Структура для хранения суммы в старой британской системе
struct sterling {
    int pounds;
    int shillings;
    int pence;
};

// Функция ввода суммы от пользователя
sterling inputSterling() {
    sterling s;
    cout << "Введите сумму в старых фунтах (фунты шиллинги пенсы): ";
    cin >> s.pounds >> s.shillings >> s.pence;
    return s;
}

// Функция сложения двух сумм
sterling addSterling(sterling s1, sterling s2) {
    sterling result;

    // Складываем пенсы
    result.pence = s1.pence + s2.pence;
    if (result.pence >= 12) { // 12 пенсов = 1 шиллинг
        result.pence -= 12;
        s1.shillings += 1;
    }

    // Складываем шиллинги
    result.shillings = s1.shillings + s2.shillings;
    if (result.shillings >= 20) { // 20 шиллингов = 1 фунт
        result.shillings -= 20;
        s1.pounds += 1;
    }

    // Складываем фунты
    result.pounds = s1.pounds + s2.pounds;

    return result;
}

// Функция вывода суммы
void displaySterling(sterling s) {
    cout << "Сумма: " << s.pounds << " фунтов " << s.shillings << " шиллингов " << s.pence << " пенсов" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    // Получаем две суммы от пользователя
    sterling amount1 = inputSterling();
    sterling amount2 = inputSterling();

    // Складываем суммы
    sterling sum = addSterling(amount1, amount2);

    // Выводим результат
    displaySterling(sum);

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
