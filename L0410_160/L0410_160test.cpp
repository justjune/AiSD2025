#include <iostream>
#include <vector>
#include "L0410_160.hpp"

int main() {
    std::vector<int> data = {
        38, 27, 43, 3, 9, 82, 10
    };

    std::cout << "Original array:\n";
    for (const auto& x : data) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    merge_sort(data, 0, static_cast<int>(data.size()) - 1);

    std::cout << "Sorted array:\n";
    for (const auto& x : data) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
