#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> names = { "Анна", "Иван", "Петр", "Анна", "Мария" };

    std::string SearchName;
    std::cout << "Введите имя для поиска: ";
    std::cin >> SearchName;

    auto it = std::find_if(names.begin(), names.end(),
        [SearchName](const std::string& name) {
            return name == SearchName;
        });

    if (it != names.end()) {
        std::cout << "Найдено на позиции: " << std::distance(names.begin(), it) << std::endl;
    }
    else {
        std::cout << "Имя не найдено.\n";
    }

    return 0;
}
