#include <iostream>
#include <vector>
#include "subset_sum.hpp"

int main() {
    std::vector<int> numbers = {3, 34, 4, 12, 5, 2};
    int target_sum = 9;
    
    if (subset_sum(numbers, target_sum)) {
        std::cout << "Подмножество с суммой " << target_sum << " существует" << std::endl;
    } else {
        std::cout << "Подмножество с суммой " << target_sum << " не существует" << std::endl;
    }
    
    // Тест 2
    target_sum = 30;
    if (subset_sum(numbers, target_sum)) {
        std::cout << "Подмножество с суммой " << target_sum << " существует" << std::endl;
    } else {
        std::cout << "Подмножество с суммой " << target_sum << " не существует" << std::endl;
    }
    
    return 0;
}