#include <iostream>
#include <limits> 
#include "L310_111.hpp" 

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

// Вспомогательная функция для вставки (чтобы не передавать parent вручную)
void insert_wrapper(tree** root, int x) {
    insert_tree(root, x, nullptr);
}

int main() {
    tree* root = nullptr;

    std::cout << "Inserting elements: 8, 3, 10, 1, 6, 14, 4, 7, 13" << std::endl;
    
    // Используем wrapper-функцию
    insert_wrapper(&root, 8);
    insert_wrapper(&root, 3);
    insert_wrapper(&root, 10);
    insert_wrapper(&root, 1);
    insert_wrapper(&root, 6);
    insert_wrapper(&root, 14);
    insert_wrapper(&root, 4);
    insert_wrapper(&root, 7);
    insert_wrapper(&root, 13);

    std::cout << "\nIn-order traversal (should be sorted):" << std::endl;
    print_in_order(root);
    std::cout << std::endl;

    std::cout << "\nTree structure with parents:" << std::endl;
    print_tree_structure(root);

    // Проверка некоторых parent-связей
    std::cout << "\nChecking parent-child relationships:" << std::endl;
    if (root != nullptr && root->left != nullptr) {
        std::cout << "Node " << root->left->item << " has parent: " 
                  << (root->left->parent ? std::to_string(root->left->parent->item) : "NULL") 
                  << " (should be " << root->item << ")" << std::endl;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    // TODO: Освободить память (добавить функцию delete_tree)
    return 0;
}