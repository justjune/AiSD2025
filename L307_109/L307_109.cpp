// L307_109.cpp
// Реализация алгоритма рекурсивного поиска в бинарном дереве
// ПМ-2025 Овсянникова Анастасия

#include "L307_109.hpp"

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