#include <iostream>
#include <cstring>      // для strcmp
#include <locale>       // для setlocale

using namespace std;

// Функция для определения порядка двух строк
bool order(const char* s1, const char* s2) {
    return strcmp(s1, s2) < 0;
}

// Функция сортировки (пузырьком) указателей на строки
void bsort(const char** arr, int n) {
    const char* temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!order(arr[i], arr[j])) {
                // Меняем указатели местами
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Для вывода русских символов в консоли

    // Массив указателей на строки
    const char* days[] = {
        "Вторник",
        "Понедельник",
        "Четверг",
        "Среда",
        "Суббота",
        "Пятница",
        "Воскресенье"
    };

    int n = sizeof(days) / sizeof(days[0]);

    cout << "До сортировки:\n";
    for (int i = 0; i < n; i++)
        cout << days[i] << endl;

    // Сортировка
    bsort(days, n);

    cout << "\nПосле сортировки:\n";
    for (int i = 0; i < n; i++)
        cout << days[i] << endl;

    return 0;
}
