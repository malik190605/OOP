#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = { 10, 20, 30, 40, 50, 60, 70, 80 };

    cout << "Исходный вектор: ";
    for (int v : vec) cout << v << " ";
    cout << "\n";

    int first, last, dest;
    cout << "Введите индексы: откуда копировать (first last) и куда (dest): ";
    cin >> first >> last >> dest;

    if (first < 0 || last > vec.size() || dest < 0 || dest + (last - first) > vec.size()) {
        cout << "Ошибка: выход за границы вектора.\n";
        return 1;
    }

    // Перекрытие вправо — используем copy_backward
    if (dest > first) {
        cout << "Сдвиг вправо: используем copy_backward\n";
        copy_backward(vec.begin() + first, vec.begin() + last, vec.begin() + dest + (last - first));
    }
    // Сдвиг влево — можно использовать обычный copy
    else {
        cout << "Сдвиг влево: используем copy\n";
        copy(vec.begin() + first, vec.begin() + last, vec.begin() + dest);
    }

    cout << "После сдвига: ";
    for (int v : vec) cout << v << " ";
    cout << "\n";

    return 0;
}
