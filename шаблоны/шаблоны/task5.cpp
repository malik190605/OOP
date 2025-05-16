#include <iostream>
using namespace std;

template <typename T>
T amax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr1[] = {1, 5, 3, 9, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Максимум (int): " << amax(arr1, size1) << endl;

    float arr2[] = {2.3f, 5.1f, 1.9f, 4.4f};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Максимум (float): " << amax(arr2, size2) << endl;

    double arr3[] = {0.1, 0.5, 0.3, 0.9};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Максимум (double): " << amax(arr3, size3) << endl;

    char arr4[] = {'a', 'z', 'm', 'b'};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Максимум (char): " << amax(arr4, size4) << endl;

    return 0;
}
