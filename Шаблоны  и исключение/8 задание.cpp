#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 10, 20, 30, 40, 50, 60, 70, 80 };

    int first1, last1, first2;
    std::cout << "Массив: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\nВведите индексы: first1, last1, first2: ";
    std::cin >> first1 >> last1 >> first2;

    if (first1 < 0 || last1 > vec.size() || first2 < 0 || first2 + (last1 - first1) > vec.size()) {
        std::cout << "Ошибка: выход за границы вектора.\n";
        return 1;
    }

    // Проверка перекрытия
    if (first2 > first1) {
        std::cout << "Ошибка: нельзя копировать вправо — произойдёт перекрытие.\n";
        return 1;
    }

    std::copy(vec.begin() + first1, vec.begin() + last1, vec.begin() + first2);

    std::cout << "Результат: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
