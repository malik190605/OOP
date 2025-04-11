#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int SIZE = 10;

    // Объявляем 10 массивов по 10 элементов
    int a0[SIZE], a1[SIZE], a2[SIZE], a3[SIZE], a4[SIZE];
    int a5[SIZE], a6[SIZE], a7[SIZE], a8[SIZE], a9[SIZE];

    // Массив указателей на массивы
    int* ap[SIZE] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };

    // Заполнение данными
    for (int i = 0; i < SIZE; i++) {           // по "строкам"
        for (int j = 0; j < SIZE; j++) {       // по элементам в каждой строке
            ap[i][j] = i * 10 + j;             // например: 0,1,...,99
        }
    }

    // Вывод содержимого
    cout << "Содержимое 'расщепленного' массива:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << ap[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
