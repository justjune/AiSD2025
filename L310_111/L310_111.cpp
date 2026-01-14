//L310_111
//Вставка элементов в дерево
//ПМ-2025 Овсянникова Анастасия
#include "L310_111.hpp"

void insert_tree(tree** l, int x, tree* parent) {
    if (*l == nullptr) {
        tree* p = new tree;
        p->item = x;
        p->left = p->right = nullptr;
        p->parent = parent;
        *l = p;
        return;
    }

    if (x < (*l)->item) {
        insert_tree(&((*l)->left), x, *l);
    } else {
        insert_tree(&((*l)->right), x, *l);
    }
}
