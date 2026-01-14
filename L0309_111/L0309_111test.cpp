#include <iostream>
#include "L0309_111.hpp"

int main() {
    tree_node *root = new_node(4);
    root->left = new_node(2);
    root->right = new_node(5);
    root->left->left = new_node(1);
    root->left->right = new_node(3);

    std::cout << "Симметричный обход: ";
    traverse_tree(root);
    std::cout << std::endl;

    return 0;
}