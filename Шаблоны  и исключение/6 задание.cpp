#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    std::cout << "До переворота: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << "\n";

    // Используем один прямой итератор (начало) и один обратный (конец)
    auto front = vec.begin();
    auto back = vec.rbegin();

    for (size_t i = 0; i < vec.size() / 2; ++i) {
        std::swap(*front, *back);
        ++front;
        ++back;
    }

    std::cout << "После переворота: ";
    for (int val : vec) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
