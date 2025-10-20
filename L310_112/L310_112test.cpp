//L310_112
//Вставка элементов в дерево
//ПМ-2025 Овсянникова Анастасия
#include <iostream>
#include <limits> 
#include "L310_112.hpp" 

void print_in_order(tree* node) {
    if (node == nullptr) {
        return;
    }
    print_in_order(node->left);     
    std::cout << node->item << " ";   
    print_in_order(node->right);    
}

void print_tree_structure(tree* node) {
    if (node == nullptr) {
        return;
    }
    
    std::cout << "Node: " << node->item;

    if (node->parent != nullptr) {
        std::cout << " | Parent: " << node->parent->item;
    } else {
        std::cout << " | Parent: NULL";
    }

    if (node->left != nullptr) {
        std::cout << " | Left child: " << node->left->item;
    }

    if (node->right != nullptr) {
        std::cout << " | Right child: " << node->right->item;
    }
    std::cout << std::endl;

    print_tree_structure(node->left);
    print_tree_structure(node->right);
}


int main() {
    tree* root = nullptr;

    std::cout << "Inserting elements: 8, 3, 10, 1, 6, 14, 4, 7, 13" << std::endl;
    insert_tree(&root, 8, nullptr);
    insert_tree(&root, 3, nullptr);
    insert_tree(&root, 10, nullptr);
    insert_tree(&root, 1, nullptr);
    insert_tree(&root, 6, nullptr);
    insert_tree(&root, 14, nullptr);
    insert_tree(&root, 4, nullptr);
    insert_tree(&root, 7, nullptr);
    insert_tree(&root, 13, nullptr);

    std::cout << "\nIn-order traversal:" << std::endl;
    print_in_order(root);
    std::cout << std::endl;

    std::cout << "\nTree structure:" << std::endl;
    print_tree_structure(root);

    std::cout << "\nPress Enter to exit...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}