#include <iostream>
using namespace std;

template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "До обмена (int): x = " << x << ", y = " << y << endl;
    swaps(x, y);
    cout << "После обмена (int): x = " << x << ", y = " << y << endl;

    char c1 = 'A', c2 = 'Z';
    cout << "\nДо обмена (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    swaps(c1, c2);
    cout << "После обмена (char): c1 = " << c1 << ", c2 = " << c2 << endl;

    float f1 = 1.23f, f2 = 4.56f;
    cout << "\nДо обмена (float): f1 = " << f1 << ", f2 = " << f2 << endl;
    swaps(f1, f2);
    cout << "После обмена (float): f1 = " << f1 << ", f2 = " << f2 << endl;

    return 0;
}
