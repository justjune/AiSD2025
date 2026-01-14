#ifndef L310_111_HPP
#define L310_111_HPP

struct tree {
    int item;
    tree* left;
    tree* right;
    tree* parent;
};

void insert_tree(tree** l, int x, tree* parent);

#endif