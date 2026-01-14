// L307_109test.cpp
// Тестирование алгоритма рекурсивного поиска в бинарном дереве
// ПМ-2025 Овсянникова Анастасия

#include <iostream>
#include <limits>
#include "L307_109.hpp"

// Берем функцию вставки из проекта L310_111 (процедура 3.10)
// Но без parent, так как в L307_109 структура tree не имеет parent
void insert_tree_from_L310(tree** l, item_type x) {
    if (*l == nullptr) {
        tree* p = new tree;
        p->item = x;
        p->left = p->right = nullptr;
        *l = p;
        return;
    }
    if (x < (*l)->item) {
        insert_tree_from_L310(&((*l)->left), x);
    } else {
        insert_tree_from_L310(&((*l)->right), x);
    }
}

int main() {
    tree* root = nullptr;
    
    // ВОТ ИСПРАВЛЕНИЕ: используем функцию вставки для сборки дерева
    // (процедура 3.10 из L310_111)
    insert_tree_from_L310(&root, 8);
    insert_tree_from_L310(&root, 3);
    insert_tree_from_L310(&root, 10);
    insert_tree_from_L310(&root, 1);
    insert_tree_from_L310(&root, 6);
    insert_tree_from_L310(&root, 14);
    
    std::cout << "=== Тестирование поиска в BST ===" << std::endl;
    std::cout << "Дерево собрано через insert_tree (процедура 3.10)" << std::endl;
    std::cout << "Элементы: 8, 3, 10, 1, 6, 14" << std::endl << std::endl;
    
    // Тестируем поиск
    int test_values[] = {6, 99, 8, 14};
    
    for (int value : test_values) {
        tree* result = search_tree(root, value);
        std::cout << "Поиск " << value << ": ";
        if (result != nullptr) {
            std::cout << "найден (узел с значением " << result->item << ")" << std::endl;
        } else {
            std::cout << "не найден" << std::endl;
        }
    }
    
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    
    return 0;
}