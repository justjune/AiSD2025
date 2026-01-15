#include <iostream>
#include <vector>
#include "L0409_154.hpp"

int main() {
    std::vector<item_type> data = {7, 3, 5, 2, 9, 1, 4};

    insertion_sort(data);

    for (const auto& x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
