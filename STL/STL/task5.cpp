#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    const int N = 5;
    int evenArr[N] = {2, 4, 6, 8, 10};
    set<int> oddSet = {1, 3, 5, 7, 9};

    vector<int> result;
    result.resize(N + oddSet.size());

    merge(evenArr, evenArr + N, oddSet.begin(), oddSet.end(), result.begin());

    cout << "Результат слияния: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
