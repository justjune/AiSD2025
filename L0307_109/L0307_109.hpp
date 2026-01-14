// L0307_109.hpp
// Заголовочный файл для работы с бинарным деревом поиска
// ПМ-2025 Овсянникова Анастасия

#ifndef L0307_109_HPP
#define L0307_109_HPP

using item_type = int;

struct tree {
    item_type item;
    tree *left;
    tree *right;
};

tree* search_tree(tree* l, item_type x);

#endif