#include <iostream>
using namespace std;

template <typename T>
double average(T* arr, int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Среднее (int): " << average(arr1, size1) << endl;

    long arr2[] = {100000L, 200000L, 300000L};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Среднее (long): " << average(arr2, size2) << endl;

    double arr3[] = {1.1, 2.2, 3.3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Среднее (double): " << average(arr3, size3) << endl;

    char arr4[] = {'A', 'B', 'C'}; // A=65, B=66, C=67
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Среднее (char): " << average(arr4, size4) << endl;

    return 0;
}
