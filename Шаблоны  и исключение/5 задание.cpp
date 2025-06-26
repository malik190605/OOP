#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    // Массив на 5 чётных чисел
    std::array<int, 5> even = { 2, 4, 6, 8, 10 };

    // Множество из 5 нечётных чисел
    std::set<int> odd = { 1, 3, 5, 7, 9 };

    // Вектор для хранения результата слияния
    std::vector<int> result;
    result.resize(even.size() + odd.size());

    // Объединяем массив и множество в отсортированный вектор
    std::merge(even.begin(), even.end(),
        odd.begin(), odd.end(),
        result.begin());

    // Выводим результат
    std::cout << "Результат merge:\n";
    for (int n : result) {
        std::cout << n << " ";
    }

    return 0;
}
