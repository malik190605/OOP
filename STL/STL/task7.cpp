#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int first1, last1, first2;
    cout << "Исходный контейнер: ";
    for (int val : data) cout << val << " ";
    cout << "\nВведите first1, last1, first2 (через пробел): ";
    cin >> first1 >> last1 >> first2;

    if (first1 < 0 || last1 > data.size() || first1 >= last1 || first2 < 0 || first2 + (last1 - first1) > data.size()) {
        cout << "Неверный ввод.\n";
        return 1;
    }

    if (first2 < first1) {
        copy(data.begin() + first1, data.begin() + last1, data.begin() + first2);
    } else {
        copy_backward(data.begin() + first1, data.begin() + last1, data.begin() + first2 + (last1 - first1));
    }

    cout << "Результат: ";
    for (int val : data) cout << val << " ";
    cout << endl;

    return 0;
}
