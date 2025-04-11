#include <iostream>
using namespace std;

// Функция сложения массивов через указатели
void addarrays(const float* a, const float* b, float* result, int size) {
    for (int i = 0; i < size; i++) {
        *(result + i) = *(a + i) + *(b + i);  // сложение через указатели
    }
}

int main() {
    const int SIZE = 5;
    float arr1[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    float arr2[SIZE] = { 5.5, 4.4, 3.3, 2.2, 1.1 };
    float result[SIZE];  // сюда будет записан результат

    addarrays(arr1, arr2, result, SIZE);

    cout << "Результат сложения массивов:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
