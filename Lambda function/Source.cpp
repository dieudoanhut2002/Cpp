

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 5, 2, 9, 3 };

    // Sắp xếp mảng số nguyên theo thứ tự tăng dần
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
        });

    // In ra mảng số nguyên đã sắp xếp
    std::cout << "Sorted numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}




/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };

    // Lọc các số lẻ trong vector
    std::vector<int> odd_numbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(odd_numbers), [](int n)->bool {
        return n % 2 != 0;
        });

    // In ra các số lẻ đã được lọc
    std::cout << "Odd numbers: ";
    for (int n : odd_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

*/
