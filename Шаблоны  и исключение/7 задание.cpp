#include <iostream>
#include <vector>
#include <numeric> // для accumulate

int main() {
    std::vector<int> nums = { 10, 20, 30, 40 };

    // Сумма всех чисел + начальное значение (100)
    int result = std::accumulate(nums.begin(), nums.end(), 100);

    std::cout << "Сумма элементов + 100 = " << result << std::endl;

    return 0;
}
