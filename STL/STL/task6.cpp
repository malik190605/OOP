#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> data = {100, 200, 300, 400, 500};

    int sum = accumulate(data.begin(), data.end(), 0);

    cout << "Сумма элементов: " << sum << endl;

    return 0;
}
