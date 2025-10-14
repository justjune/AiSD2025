//L307_110
//Алгоритм рекурсивного поиска произвольного элемента в двоичном дереве
//ПМ-2025 Овсянникова Анастасия
#include <iostream>
#include <limits>

using item_type = int;

struct tree {
    item_type item;
    tree *left;
    tree *right;
};

tree* search_tree(tree* l, item_type x) {
    if (l == nullptr) {
        return nullptr;
    }
    if (l->item == x) {
        return l;
    }
    if (x < l->item) {
        return search_tree(l->left, x);
    } else {
        return search_tree(l->right, x);
    }
}


int main() {
    // Простое дерево для теста:
    tree node1  = {1, nullptr, nullptr};
    tree node6  = {6, nullptr, nullptr};
    tree node14 = {14, nullptr, nullptr};
    tree node3  = {3, &node1, &node6};
    tree node10 = {10, nullptr, &node14};
    tree root   = {8, &node3, &node10};

    int value_to_find = 6;
    tree* result = search_tree(&root, value_to_find);

    std::cout << "Searching for value: " << value_to_find << std::endl;
    if (result != nullptr) {
        std::cout << "Found! The value is: " << result->item << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    value_to_find = 99;
    result = search_tree(&root, value_to_find);
    std::cout << "Searching for value: " << value_to_find << std::endl;
    if (result != nullptr) {
        std::cout << "Found! The value is: " << result->item << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }
    
    std::cout << "Press ENTER to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}