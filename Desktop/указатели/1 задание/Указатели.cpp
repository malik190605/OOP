#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите количество чисел: ";
    cin >> size;

    // Выделяем память под массив float
    float* numbers = new float[size];

    // Вводим числа
    cout << "Введите " << size << " чисел:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Число " << i + 1 << ": ";
        cin >> *(numbers + i);  // Используем указатель для ввода
    }

    // Вычисляем сумму
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(numbers + i);  // Используем указатель для доступа
    }

    // Считаем среднее арифметическое
    float average = sum / size;
    cout << "Среднее арифметическое: " << average << endl;

    // Освобождаем память
    delete[] numbers;

    return 0;
}
