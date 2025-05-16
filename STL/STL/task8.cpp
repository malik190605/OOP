#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie", "Diana", "Eve"};

    string SearchName;
    cout << "Введите имя для поиска: ";
    cin >> SearchName;

    auto it = find_if(names.begin(), names.end(),
                      bind2nd(equal_to<string>(), SearchName));

    if (it != names.end()) {
        cout << "Имя найдено на позиции: " << distance(names.begin(), it) << endl;
    } else {
        cout << "Имя не найдено.\n";
    }

    return 0;
}
