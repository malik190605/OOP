// Объекты и классы 7 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cmath>

double convertToDecimal(int degrees, double minutes, char direction) {
    double decimal = degrees + minutes / 60.0;

    // Для западной долготы и южной широты нужно сделать координаты отрицательными
    if (direction == 'W' || direction == 'S') {
        decimal = -decimal;
    }

    return decimal;
}

int main() {
    setlocale(LC_ALL, "russian");
    // Пример для бухты Папити
    int lon_degrees = 149, lat_degrees = 17;
    double lon_minutes = 34.8, lat_minutes = 31.5;
    char lon_direction = 'W', lat_direction = 'S';

    // Преобразуем координаты в десятичные значения
    double decimalLongitude = convertToDecimal(lon_degrees, lon_minutes, lon_direction);
    double decimalLatitude = convertToDecimal(lat_degrees, lat_minutes, lat_direction);

    // Выводим результат
    std::cout << "Долгота: " << decimalLongitude << "°" << std::endl;
    std::cout << "Широта: " << decimalLatitude << "°" << std::endl;

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
