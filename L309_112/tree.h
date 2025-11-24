#pragma once
typedef struct tree {
    int item;    /* Ёлемент данных */
    struct tree* parent;    /* ”казатель на родительский узел */
    struct tree* left;    /* ”казатель на левый дочерний узел */
    struct tree* right;    /* ”казатель на правый дочерний узел */
} tree;