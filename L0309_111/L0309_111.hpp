#ifndef L0309_111_HPP
#define L0309_111_HPP

struct tree_node {
    int value;
    tree_node *left;
    tree_node *right;
};

void traverse_tree(tree_node *node);
tree_node* new_node(int value);

#endif