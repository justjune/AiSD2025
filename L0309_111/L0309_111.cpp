#include <iostream>
#include "L0309_111.hpp"

void traverse_tree(tree_node *node) {
    if (node != nullptr) {
        traverse_tree(node->left);
        std::cout << node->value << " ";
        traverse_tree(node->right);
    }
}

tree_node* new_node(int value) {
    tree_node* node = new tree_node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
